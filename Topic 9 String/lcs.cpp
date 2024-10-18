#include <iostream>
#include "lcs.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{
    const std::string alphabet{"ATCG"};
    std::string s = randomString(alphabet, 50);
    std::string t = randomString(alphabet, 20);

    std::string lcsSt(lcs(s,t));
    std::cout << lcsSt << std::endl << "Size" << lcsSt.length() <<std::endl;
    return 0;
}

std::string lcs(const std::string& s, const std::string& t)
{
    if(s.size()==0 || t.size()==0) return "";

    return lcs(s, t, s.size()-1, t.size()-1);
}

std::string lcs(const std::string& s, const std::string& t, int i, int j)
{
    if(i<0 || j<0) return "";

    if(s[i]==t[j]) return s[i] + lcs(s,t,i-1,j-1);

    std::string sp(lcs(s,t,i,j-1));
    std::string tp(lcs(s,t,i-1,j));

    return (sp.length()>tp.length()) ? sp : tp;
}

std::string randomString(const std::string& alphabet, size_t strLenth)
{
    std::string rtnString;
    for (size_t i = 0; i < strLenth; ++i)
        rtnString += alphabet[rand()%alphabet.size()];
    return rtnString;
}

