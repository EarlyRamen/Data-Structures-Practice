#include <functional>

#include "heap.h"

#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2


template<typename T>
class ArrayHeap : public Heap<T>
{ 
public:
    ArrayHeap(std::function<bool(const T&, const T&)> comparator) 
        : ArrayHeap(comparator, DEFAULT_SIZE) { }

    ArrayHeap(std::function<bool(const T&, const T&)> comparator, size_t initialSize) 
        : store{new T[initialSize]}, count{0}, currentSize{initialSize}, comparator{comparator} { }

    ArrayHeap(std::function<bool(const T&, const T&)> comparator, const T srcArray[], size_t size) 
    { 
        comparator=comparator;
        store=new T[size];
        currentSize=size;
        for (size_t i = 1; i < (sizeof(srcArray)/sizeof(srcArray[1])); ++i)
        {
            store[i]=srcArray[i];
            ++count;
        }
        
        heapify(store, count);
    }
    
    ~ArrayHeap() { delete[] store; }

    void add(const T& item)
    {
        if(count >= currentSize-1) resize();
        ++count;
        store[count]=item;
        upHeap(count);
    }

    void remove()
    {
        heapify(store,count);
        downHeap(1);
    }

    T get() const
    {
        return store[1];
    }

    bool empty() const
    {
        return count==0;
    }

    void clear()
    {
        while(count>0)
        {
            remove();
        }
    }

private:
    T*  store;
    size_t currentSize;
    size_t count;
    std::function<bool(const T&, const T&)> comparator;

    void downHeap(const size_t parent)
    {
        size_t lChild=parent*2;
        size_t rChild=parent*2+1;

        store[parent]=store[count];
        --count;

        while(! (comparator(store[parent], store[lChild]) && comparator(store[parent], store[rChild])))
        {
            size_t minMax;
            T tmp=store[parent];

            if(comparator(store[lChild], store[rChild])) {minMax=lChild;}
            else{minMax=rChild;}

            store[parent]=store[minMax];
            store[minMax]=tmp;
        }

    }

    void upHeap(const size_t node)
    {
        size_t parent=node/2;

        if(comparator(store[parent], store[node])) return;
        else
        {
            T tmp=store[parent];
            store[parent]=store[node];
            store[node]=tmp;
            upHeap(parent);
        }
    }

    void heapify(T array[], size_t size)
    {
        size_t lastNonLeaf=((size-1)/2) + (((size-1)%2)!=0);
        while(lastNonLeaf>=1)
        {
            upHeap(lastNonLeaf);
            --lastNonLeaf;
        }
    }
    
    void resize()
    {
        size_t newSize{currentSize*SCALING_FACTOR};
        T* newStore{new T[newSize]};

        for(size_t i=1; i<currentSize;++i)
        {
            newStore[i]=store[i];
        }

        delete[] store; 
        currentSize = newSize;
        store = newStore;
    }
};


#endif /* ARRAY_HEAP_H */
