#include<cstddef>


#ifndef SET_H
#define SET_H

template<typename T>
struct Set
{
    virtual ~Set() { }

    /** adds an item to the set. 
     *  throws an runtime error if the item is already a member
    */
    virtual void add(const T&) = 0;

    /** removes the item from the set
     *  throws aexception if the item doesn't exists
    */
    virtual T remove(const T&) = 0;

    /** returns true if the set is empty or false otherwise */
    virtual bool empty() const = 0;

    /** returns true if the item is a member or false otherwise */
    virtual bool contains(const T&) const = 0;

    /** returns the number of members in the set */
    virtual size_t size() const = 0;
};


#endif /* SET_H */
