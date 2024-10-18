#include <iostream>
#include <unordered_map>
#include <vector>

#define TEST_VAL 50
size_t fib(size_t);


int main(int argc, char const *argv[]){
    std::cout<<fib(TEST_VAL)<<std::endl;
}

size_t fib(size_t n){

    static std::unordered_map<size_t, size_t> map; 

    if(n<=1){
        return n;
    }

    if(map.find(n) != map.end()) return map[n];

    map[n]=fib(n-2)+fib(n-1)

    return map[n];
}

