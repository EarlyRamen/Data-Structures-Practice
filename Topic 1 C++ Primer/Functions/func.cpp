#include <iostream>

#include "func.h"

int main(int argc, char const *argv[])
{
    int a[]{1,2,3,4,5,6,7,8,9};
    size_t size{sizeof a/sizeof a[0]};

    std::cout<<*a<<std::endl;

    PrintINArray(a, size);

    return 0;
}

void PrintINArray(int array[], size_t size){
    char comma={' '};
    std::cout<<array<<std::endl; //sizeof arry here will output the size of the address not the array itself
                                 //which is 8 bytes
    std::cout<<'[';
    for (size_t i = 0; i < size; ++i){
        std::cout<<comma<<array[i];
        comma=',';
    }
    std::cout<<" ]";


}