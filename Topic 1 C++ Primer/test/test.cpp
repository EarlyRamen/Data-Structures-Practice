#include <iostream>
#include <cstdint>
#include "test.h"
#define ULL unsigned long long
using std::cout;
using std::endl;
using ull = unsigned long long; 

typedef unsigned long long Ull;

Ull i{10};

int main(int argc, char const *argv[]){
    printExit();
    return 0;
}

void printExit(){
    uint32_t i;

    cout << sizeof i << endl;

    for(size_t i=0; i<10; ++i){
        cout << i << endl;
        cout << "Goodbye Cruel World" << " " << i << endl;
    }
}


/*Stage of Complier
    1.Preprocessiing
        expanded source code go in stage 2.
        To check for output, use:
            g++ -E -o test.e test.cpp

    2.Complation
        Checking for syntax error and optimize
        Then output Assembly Language to stage 3
        To check for output, use:
            g++ -S -o test.asm test.cpp

    3.Assembler
        output object(machine) code
        To check for output, use:
            g++ -c test.cpp

    4.Linking
        link funtions together
        output executable file
            g++ -g(bulid with debug) -o test.out test.cpp
*/