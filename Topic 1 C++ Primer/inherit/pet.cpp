#include <stdexcept>

#include "pet.h"

Pet::Pet(const std::string& name){
    if(name.empty()) throw std::logic_error("name cannot be empty!");
    this->name = name;
}

std::string Pet::getName() const{return name;}