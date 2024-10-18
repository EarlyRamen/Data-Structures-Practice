#include <iostream>

union dblint
{
    double dbl;
    size_t uint;
};

#define ARRAY_SIZE 127

void printBin(int v);
size_t hashcode(const std::string& s);

namespace msac
{
    inline int noneg(int v) {return v & 0x7fffffff;}
}

int main(int argc, char const *argv[])
{
    int neg=-7676868768;
    double dbl{-2345.6789};

    dblint dbli{dbl};
    
    std::cout << hashcode("wazup!") << std::endl;
}

void printBin(int v)
{
    for (size_t i = 0; i < 32; ++i)
    {
        std::cout<<((v & 0x800000000) ? 1:0);
        v <<= 1;
    }
    
    std::cout<<std::endl;
}

size_t hashcode(const std::string& s)
{
    size_t code{};
    for(char c:s)
        code=code * 31 + c;
    return code;
}