#include <iostream>

int main(int argc, char const *argv[])
{
    int i{5};
    int* pi{&i};

    int array[]{1,2,3,4,5,6,7,8,9};
    int* pa{array};

    std::cout<<i<<" "<<&i<<std::endl;
    std::cout<<*pi<<" "<<pi<<" "<<&pi<<std::endl;

    std::cout<<*(pa+4)<<" "<<pa<<" "<<&pa<<std::endl; 

    while(pa<array+9)
        std::cout<<*(pa++)<<" ";
    
    return 0;
}
