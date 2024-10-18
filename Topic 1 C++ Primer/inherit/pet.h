#include <string>
#ifndef PET_H
#define PET_H

class Pet{
    public:
        Pet(const std::string&);             //Virtual keyword is needed when the function is meant to be overridden in sub-class
        virtual std::string speak() const=0; //virtual is only needed in the header file as a declaration, const
        std::string getName() const;         //is both declaration and def.
                                             //setting a func to 0 make the class abstract. Instance of that class is no
                                             //longer allowed.
    private:
        std::string name;
};

#endif /*PET_H*/