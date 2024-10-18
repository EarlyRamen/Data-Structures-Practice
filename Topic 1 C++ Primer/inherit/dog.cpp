#include "dog.h"

Dog::Dog(const std::string& name):Pet(name){}

std::string Dog::speak() const{return getName()+" says: woof-woof";}