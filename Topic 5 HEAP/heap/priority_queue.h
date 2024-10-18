#include <functional>
#include "array_heap.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<typename T>
struct pair
{
    pair() : key{0}, item{0} { }
    pair(const size_t& key, const T& item) 
        : key{key}, item{item} { }

    size_t key;
    T item;
};

template<typename T>
class PriorityQueue
{
public:
    PriorityQueue(std::function<bool(const T&, const T&)> comparator)
        : queue{ArrayHeap<pair<T>>
        ([comparator](const pair<T>& a, const pair<T>& b) {return comparator(a.key, b.key);}) } { }

    void enqueue(const size_t& key, const T& item)
    {  
        queue.add(pair<T>{key,item});
    }
    
    void dequeue() 
    {  
        queue.remove();
    }

    T front() const{  
        return queue.get().item;
    } 

    bool empty() const 
    {  
        return queue.empty();
    }

    void clear() {
        queue.clear();
    }

private:
    ArrayHeap<pair<T>> queue;
};

#endif /* PRIORITY_QUEUE_H */
