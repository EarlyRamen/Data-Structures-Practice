#include <cstddef>
#include <functional>
#include <stdexcept>

#include "set.h"

#ifndef HASH_SET_H
#define HASH_SET_H

#define MAX_PROBE

enum Prober{LINEAR, QUADRATIC};

enum Status{Occupied, Empty, Free};

//Type T must have the equality operator implemented

template<typename T>
class HashSet : public Set<T>
{

public:

    HashSet(std::function<size_t(const T&)> hashcode, Prober prober) : prober{prober}, hashcode{hashcode} { }

    HashSet(std::function<int(const T&)> h1)
    {
        HashSet(h1, LINEAR);
    }

    /** adds an item to the set. 
     *  Replaces the item if it already exists
    */
    void add(const T& item)
    {
        //if(count>(currentSize*0.75)) resize();

        int itemIdx=findItem(item);
        if(itemIdx>-1) 
        {
            store[itemIdx].item=item;
        }

        else
        {   
            itemIdx=probe(h1(item));
            if(itemIdx==-1) throw std::runtime_error("Probing failed and returned -1");
            store[itemIdx].item=item;
            store[itemIdx].status=Occupied;
        }

        ++count;
    }

    /** removes the item from the set
     *  throws a runtime error if the item is not a member
    */
    T remove(const T& item)
    {
        if(!contains(item))
            throw std::runtime_error("item is not a member");
        store[findItem(item)].item=T{};
        store[findItem(item)].status=Free;
        --count;
        return item;
    }

    /** returns true if the set is empty or false otherwise */
    bool empty() const {return count==0;}

    /** returns true if the item is a member or false otherwise */
    bool contains(const T& item) const
    {
        size_t index=(probe(T,hashcode(item)));
        return false; 
    }

    /** returns the number of members in the set */
    size_t size() const {return count;}

private:
    struct Element {T item; Status status;};

private:
    T* store;
    size_t currentSize;
    size_t count;
    std::function<int(const T&)> hashcode;
    Prober prober;
    Element* elements

    int probe(const T& item, size_t hcode) const
    {
        return (prober == LINEAR)
        ? linearProbe(item, hcode):quadraticProbe(item,hcode);
    }

    int linearProbe(const T& item, size_t hcode) const
    {
        for (int i = 0; i < 15; ++i)
        {
            if( (store[hcode % currentSize].status == Empty) || (store[hcode % currentSize].status == Free) )
                return hcode % currentSize;
            ++hcode;
        }
        return -1;
    }

    int quadraticProbe(const T& item, size_t hcode) const
    {
        for (int i = 0; i < 15; ++i)
        {
            if( (store[(hcode+i*i) % currentSize].status == Empty) || (store[(hcode+i*i) % currentSize].status == Free) )
                return (hcode+i*i) % currentSize;
        }
        return -1;
    }

    void resize()
    {
        size_t oldSize=currentSize;
        currentSize *= 2;
        count=0;
        Entry<T>* newSet{new Entry<T>[currentSize]};
        Entry<T>* oldSet = store;
        store = newSet;

        for (size_t i = 0; i < oldSize; ++i)
        {
            if(oldSet[i].status==Occupied)
                newSet[probe(h1(oldSet[i].item))]=oldSet[i];
                newSet[probe(h1(oldSet[i].item))].status=Occupied;
        }
        delete[] oldSet; 
    }

    int findItem(const T& item) const
    {
        for (int i = 0; i < currentSize; ++i)
        {
            if(store[i].item==item)
                return i;
        }
        return -1;
    }
};

#endif /* HASH_SET_H */
