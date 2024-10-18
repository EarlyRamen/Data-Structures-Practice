#include <stdexcept>
#include "stack.h"

Stack::Stack():top{}, array{new int[INIT_STACK_SZ]}, currentSize{INIT_STACK_SZ}{};

Stack::~Stack(){delete[] array;}

void Stack::push(int val){
    if(top==currentSize){
        resize();
    }
    array[top++]=val;
}

void Stack::pop(){
    if(empty()) 
        throw std::logic_error("pop on a empty stack");
    --top;
}

int Stack::peek(){
    if(empty()) 
        throw std::logic_error("peek on a empty stack");
    return array[top-1];
}

void Stack::resize(){
    size_t newSize{currentSize*SCALING_FACTOR};
    int* newArray{new int[newSize]};

    for (size_t i = 0; i < currentSize; ++i){
        newArray[i]=array[i];
    }
    currentSize=newSize;
    delete[] array;
    array = newArray; 
}

bool Stack::empty(){
    return top==0;
}

