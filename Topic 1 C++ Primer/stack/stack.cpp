#include "stack.h"

void push(int val, Stack&stack){
    stack.stack[stack.top]=val;
    ++stack.top;
}

void pop(Stack&stack){
    --stack.top;
    //pre decrement is faster and better
}

int peek(const Stack&stack){
    return stack.stack[stack.top-1];
}

bool empty(Stack&stack){
    return stack.top==0;
}
