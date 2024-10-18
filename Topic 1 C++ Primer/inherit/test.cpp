#include <iostream>
#include "pet.h"
#include "dog.h"

int main(int argc, char const *argv[]){
    Pet* p(new Dog("fred"));

    std::cout<<p->speak()<<std::endl;

    return 0;
}
