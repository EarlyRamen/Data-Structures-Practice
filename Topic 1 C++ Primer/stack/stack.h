#include <cstdint>

#ifndef STACK_H
#define STACK_H

struct Stack{
    int stack[100];
    uint32_t top{};
};

void push(int, Stack&);
void pop(Stack&);
int peek(const Stack&);
bool empty(Stack&);

#endif