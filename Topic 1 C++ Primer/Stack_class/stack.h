#include <cstddef>
#ifndef STACK_H
#define STACK_H

#define INIT_STACK_SZ 16
#define SCALING_FACTOR 2

class Stack{
    public:
        Stack();
        ~Stack(); //Must be in public and no parameter
        void push(int);
        void pop();
        int peek();
        bool empty();

    private:
        size_t top;
        size_t currentSize;
        int* array; //In heap when new and pointer variable is used. Destruct function is needed. 

        void resize();
};

#endif /*STACK_H*/ 