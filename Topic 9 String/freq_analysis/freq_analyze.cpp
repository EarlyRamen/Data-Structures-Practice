#include <iostream>
#include <fstream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::unordered_map<char,uint32_t> lut;
    std::ifstream in("War and Peace.txt");
    char c;
    int ci;

    if(!in) return 1;

    while(!in.eof())
    {
        c = tolower(in.get());
        if(lut.find(c) == lut.end())
            lut[c] = 1;
        else
            ++lut[c];
    }

    in.close();

    std::cout<<lut.size();
    

    for(auto p : lut)
    {
        ci = static_cast<int>(p.first);
        if(ci != '\n' && ci !=' ' && ci != '\t')
            std::cout<< ci << " had a count of " << p.second << std::endl;
    }

    std::cout<<char(187);
    return 0;
}
