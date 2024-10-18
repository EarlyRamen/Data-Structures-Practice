#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
#include "bit_array.cpp"

#include "bit_array.h"

#ifndef A8840F57_9276_4737_9F57_5267EE8110A0
#define A8840F57_9276_4737_9F57_5267EE8110A0

struct Node
{
    uint64_t freq();
    char symbol();
    Node* lchild();
    Node* rchild();
    bool terminal{false};
};

struct Triple
{
    char symbol;
    uint8_t bitQty;
    uint64_t code;
    uint64_t freq();
};

using Map = std::unordered_map<char, size_t>;
using PQueue = std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*,Node*)>>;

struct HuffmanCompressor
{
    HuffmanCompressor(const std::string&, const std::string&);

    void buildMap();
    void loadPqueue();
    void buildTree();
    void buildTable();
    size_t height(const Node*);
    void traverse(const Node*);
    void storeSymbolQty(std::ofstream&);
    void storeTableSize(std::ofstream&);
    void storeTable(std::ofstream&);
    void compress(BitArray&, std::ofstream&);
    void storeCompressedData(BitArray&, std::ofstream&);
    const Triple* lookupSymbol(char);

    std::string srcPath;
    std::string dstPath;    
    Map map;
    uint32_t symbolQty;
    uint32_t tableSize;
    uint64_t bitQty;
    PQueue pqueue;
    Node* root;
    std::vector<Triple> table;
};

#endif /* A8840F57_9276_4737_9F57_5267EE8110A0 */
