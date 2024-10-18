#include <iostream>
#include "huffman.h"

int main(int argc, char const *argv[])
{
    HuffmanCompressor hc("War and Peace.txt", "out.cmp");

    std::cout << hc.height(hc.root) << std::endl;

    return 0;
}
