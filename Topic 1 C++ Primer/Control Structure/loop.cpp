#include <iostream>

int main(int argc, char const *argv[]){
    size_t n=10;
    size_t t=0;
    for(size_t i=0, t=0, l=1, tmp; i<n; i++, tmp=l, l+=t, t=tmp);
    
    std::cout<<t<<std::endl;
    
    
    /*{
        size_t i{0};

        while(i<10){
            std::cout<<i++<<" ";
        }

        std::cout<<std::endl;
    }
    std::cout<<i<<std::endl;
    return 0;*/
}
