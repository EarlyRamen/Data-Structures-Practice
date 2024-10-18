#include <cstddef>
#ifndef BUCKET_INTERFACE_H
#define BUCKET_INTERFACE_H

/**
 *Interface for a bucket container
 *Type T must have the equality operator implmented
*/
template<typename T> 
struct Bucket{

    //adds an item to the collection
    virtual void add(const T&) = 0;

    //removes and returns an arbitrary item from the collection
    virtual T remove() = 0;
    
    //removes all of the items that match the argument
    virtual bool remove(const T&) = 0;

    //checks collection for membership
    virtual bool contains(const T&) const = 0;

    //returns an array of items
    virtual T* toArray() const = 0; 

    //empties the collection 
    virtual void clear() = 0; 

    //returns the number of items
    virtual size_t size() const = 0;

    //retuns true if empty or false otherwise
    virtual bool empty() const = 0;
};

#endif /*BUCKET_INTERFACE_H"*/

