#include<iostream>
#include "stack.h" //Don't include cpp file

int main(int argc, char const *argv[]){

    Stack s;

    for (size_t i=0; i<10; ++i){
        push(i,s);
    }
    while (!empty(s)){
        std::cout<<peek(s)<<" ";
        pop(s);
    }

    std::cout<<std::endl;
    return 0;
}