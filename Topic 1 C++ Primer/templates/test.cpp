#include <iostream>

#include "stack.h"

template<typename T>
void printCollection(Collection<T>&);


int main(int argc, char const *argv[])
{
    Collection<double>* s{new Stack<double>};

    for (double i = 0; i < 10.0; ++i){
        s->add(i+i/10);
    }
    
    printCollection(*s);

    delete s;

    return 0;
}

template<typename T>
void printCollection(Collection<T>& c){
    std::cout<<c.print()<<std::endl;
}