#ifndef E75E771A_CD75_4CA4_9670_FD45661768AB
#define E75E771A_CD75_4CA4_9670_FD45661768AB

#include "heap.h"

template<typename T>
class PriorityQueue
{
    public:
        PriorityQueue(std::function<bool(const T&, const T&)> compare)
            :heap{heap(compare)} {}

        void enqueue(const T& item) { heap.add(item); }
        void dequeue() { heap.remove(); }
        T front() { return heap.get(); }
        bool empty() { return heap.empty(); }

    private:
        Heap<T> heap;
};

#endif /* E75E771A_CD75_4CA4_9670_FD45661768AB */
