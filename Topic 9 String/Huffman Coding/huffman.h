#include <string>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

#ifndef C7579ED4_95EA_4F1A_8596_0BACFA5096F2
#define C7579ED4_95EA_4F1A_8596_0BACFA5096F2

class Huffman
{
public:
    Huffman(std::string inFile)
    {
        freqTable(inFile);
        Huffmancoding(freqMap);
        makeCodeTable();
        outputCodeTableToTXT();
        //output(inFile, "out.txt");
    }

private: 
    struct node
    {
        char item;
        size_t freq;
        node* lchild;
        node* rchild;

        node(char item, size_t freq)
        {
            lchild=nullptr;
            rchild=nullptr;
            this->item=item;
            this->freq=freq;
        }
    };

    struct compare
    {
        bool operator()(node* node1, node* node2) {return node1->freq > node2->freq;}
    };

    std::string inFile;
    std::ifstream in;
    std::ofstream out;
    std::priority_queue<node*, std::vector<node*>, compare> minHeap;
    std::unordered_map<char, size_t> freqMap;
    std::queue<std::pair<std::string, node*>> codeQueue;
    std::unordered_map<char, std::string> codeMap;
    char buffer[1024];

    void Huffmancoding(std::unordered_map<char, size_t> freqMap)
    {
        node* internalNode;
        node* lchild;
        node* rchild;

        std::unordered_map<char, size_t>::iterator it;

        for (it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            minHeap.push(new node(it->first,it->second));
        }

        while(minHeap.size()!=1)
        {
            lchild=minHeap.top();
            minHeap.pop();

            rchild=minHeap.top();
            minHeap.pop();

            internalNode=new node('$', lchild->freq + rchild->freq);
            internalNode->lchild=lchild;
            internalNode->rchild=rchild;

            minHeap.push(internalNode);
        }
    }

    void freqTable(std::string inFile)
    {
        in.open(inFile, std::ios::in);
        if(!in) throw std::runtime_error("Error opening input file");
        while(true)
        {
            in.read(buffer, 1024);
            if(in.gcount() == 0) break;
            for(size_t i = 0; i < in.gcount(); i++)
            {
                freqMap[buffer[i]]++;
            }
        }
        in.close();
    }

    void makeCodeTable()
    {
        std::pair<std::string, node*> pushNode;
        pushNode.first='$';
        pushNode.second=minHeap.top();
        codeQueue.push(pushNode);

        while(codeQueue.size() > 0)
        {   
            if(codeQueue.front().second->item == '$')
            {
                if(codeQueue.front().second->lchild != nullptr)
                {
                    pushNode.first = codeQueue.front().first+"0";
                    pushNode.second = codeQueue.front().second->lchild;
                    codeQueue.push(pushNode);
                }
                if(codeQueue.front().second->rchild != nullptr)
                {
                    pushNode.first = codeQueue.front().first+"1";
                    pushNode.second = codeQueue.front().second->rchild;
                    codeQueue.push(pushNode);
                }
            }

            else
                codeMap[codeQueue.front().second->item] = codeQueue.front().first;
            codeQueue.pop();
        }
    }

    void outputCodeTableToTXT()
    {
        std::stringstream ss;
        out.open("bitCodeTable.txt", std::ios::out);
        for (auto pair : codeMap)
        {
            ss.clear();
            ss<<"symbol: "<<pair.first<<" bitCode: "<<pair.second<<std::endl;
            out<<ss.rdbuf();
        }

        out.close();
    }

    void output(std::string inFile, std::string outFile)
    {
        //I tested my Huffman Tree with a online output() function, and it worked. But I don't know how to write
        //my own. 
    }
};
#endif /* C7579ED4_95EA_4F1A_8596_0BACFA5096F2 */
