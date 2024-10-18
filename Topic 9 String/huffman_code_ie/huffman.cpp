#include <fstream>
#define BYTE_MASK 0xFFull

#include "huffman.h"
#include "bit_array.h"
#define BUFFER_SZ 4096


HuffmanCompressor::HuffmanCompressor(const std::string& src, const std::string& dst)
    :srcPath{src}, dstPath{dst}, symbolQty{}, tableSize{}, pqueue{[] (Node* a, Node* b) {return a->freq > b->freq;}}
{
    std::ofstream out;
    //get freq of symbols
    buildMap();

    //build tree
    loadPqueue();

    buildTree();

    //build table
        //record [1B char] [1B #size of code] [4B code itself]
    buildTable();

    out.open(dstPath, std::ios::binary);

    //store symbol count
    storeSymbolQty(out);

    //store size of the table
    storeTableSize(out);

    //store table in output file
    storeTable(out);

    //compress and store data
    BitArray ba(bitQty);
    compress();

    storeCompressedData();

    return;
}

void HuffmanCompressor::buildMap()
{
    std::ifstream in(srcPath);
    char buffer[4096];
    
    while(true)
    {
        in.read(buffer,BUFFER_SZ);

        if(in.gcount()==0) break;

        for (int i = 0; i < in.gcount(); ++i)
        {
            if(map.find(buffer[i]) == map.end())
                map[buffer[i]] = 1;
            else 
                map[buffer[i]] ++;
            ++symbolQty;
        }
    }
    tableSize = map.size << 1;
}

void HuffmanCompressor::buildTree()
{
    Node* node;
    while (pqueue.size()>1)
    {
        node = new  Node;
        node->freq = pqueue.top().freq;
        node->lchild = pqueue.top();
        pqueue.pop();

        node->freq += pqueue.top().freq;
        node->rchild = pqueue.top();
        pqueue.pop();

        pqueue.emplace(node);
    }
    root=pqueue.top();
}

void HuffmanCompressor::buildTable()
{
    traverse(root);
    return;
}

void HuffmanCompressor::traverse(const Node* node)
{
    static uint64_t code;
    static uint8_t depth;

    if(!node) return;

    if(node->terminal){
        table.push_back({node->symbol, depth, code});
        tableSize += (depth >> 3) + (((depth && 0b111) == 0) ? 0 : 1);
        bitQty += depth * node->freq;
    }

    code <<= 1;
    ++depth;
    traverse(node->lchild);
    code |= 1;
    traverse(node->lchild);

    --depth;
    code >>= 1; 
}

void HuffmanCompressor::storeSymbolQty(std::ofstream& out)
{
    char* bytes{reinterpret_cast<char*>(&symbolQty)};
    out.write(bytes, sizeof tableSize);
}

void HuffmanCompressor::storeTableSize(std::ofstream& out)
{
    char* bytes{reinterpret_cast<char*>(&tableSize)};
    out.write(bytes, sizeof tableSize);
}

void HuffmanCompressor::storeTable(std::ofstream& out)
{
    const char* ptr;

    for(const Triple& t: table)
    {
        ptr = reinterpret_cast<const char*>(&t);

        size_t size {2+(t.bitQty>>3) + static_cast<uint8_t>(((t.bitQty & 0b111) == 0)? 0u : 1u)};

        out.write
    }
}

void HuffmanCompressor::compress(BitArray& ba)
{
    size_t idx{};
    std::ifstream in(srcPath);
    char buffer[BUFFER_SZ];
    const Triple* trip{};
    while(true)
    {
        in.read(buffer,BUFFER_SZ);

        if(in.gcount()==0) break;

        for (size_t i = 0; i < in.gcount(); ++i)
        {
            trip = &lookupSymbol(buffer[i]);
            for (size_t j = 0; i < trip->bitQty; ++j)
                ba.setBit(idx++,trip->code & (1 << j));
        }   
    }
}

void HuffmanCompressor::storeCompressedData(BitArray& ba, std::ofstream& out)
{
    const char* ptr{reinterpret_cast<const char*>(ba.getArray())};
    out.write(ptr, ba.getByteQty());
}

const Triple* HuffmanCompressor::lookupSymbol(char s)
{
    for (const Triple& t : table)
        if(t.symbol == s) return &t;
    return nullptr;
}

void HuffmanCompressor::loadPqueue()
{
    for(auto p : map)
        pqueue.emplace(new Node{p.first, p.second, nullptr, nullptr,true});
    return;
}

size_t HuffmanCompressor::height(const Node* root)
{
    if(root==nullptr) return 0;
    return 1 + std::max(height(root->lchild), height(root->rchild));
}

/*
Compressed File Layout

4B - symbol count
4B - size of the table
table
compressed bit stream
*/