#include <fstream>
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    char buffer[1024];
    std::ifstream in("as1.zip", std::ios::binary);
    std::ofstream out;
    int qtyRead;

    if (in)
    {
        out.open("as1_copy.zip", std::ios::binary);

        while(true)
        {
            in.read(buffer, BUFFER_SIZE);
            qtyRead = in.gcount();
            if(qtyRead == 0) break;
            out.write(buffer, qtyRead);
        }
    }
    in.close();
    out.close();
    return 0;
}
