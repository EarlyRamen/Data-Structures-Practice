#include <fstream>

struct widget{double loc; int size;};

int main(int argc, char const *argv[])
{
    widget array[113];
    int elemSz{sizeof(widget)};
    int size{elemSz*113};
    std::ofstream out("outStruct.bin");
    char* deepFake = reinterpret_cast<char*>(array);
    out.write(deepFake, size);
    out.close(); 

    return 0;
}
