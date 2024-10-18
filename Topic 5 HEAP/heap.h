#include<functional>

#ifndef B344C7BF_B3E6_4DBC_8565_34DCB12166EC
#define B344C7BF_B3E6_4DBC_8565_34DCB12166EC

#define DEFAULT_SIZE 256
#define ROOT 1

/*
    a>b yields a max heap
*/

template<typename T>
class Heap
{
    public:
        Heap(std::function<bool(const T&, const T&)> compare) : Heap(compare, DEFAULT_SIZE) { }

        Heap(std::function<bool(const T&, const T&)> compare, size_t initSize) 
            : compare{compare}, heap{new T[initSize]}, currentSize{initSize} { }

        Heap(std::function<bool(const T&, const T&)> compare, const T array[], size_t arraySize) 
            : compare{compare}, currentSize{arraySize+1}, count{arraySize}
        {   
            heap = new T[currentSize];
            for (size_t i = 0; i < arraySize; ++i)
                heap[i+1]=array[i+1];
            heapify();   
        }

        void add(const T& item)
        { 
            if(count >= currentSize-1) resize();
            heap[++count]=item;

            if(count>1) upheap(count >> 1);
        }

        T get() const { return heap[ROOT]; }

        void remove() 
        { 
            heap[ROOT] = heap[count--];
            downheap(ROOT);
        }

        bool empty() const {return count==0;}
        void clear() { }

    private:
        T* heap;
        size_t currentSize;
        size_t count;
        std::function<bool(const T&, const T&)> compare;

        void heapify()
        {
            for (size_t parent = count>>1; parent >= ROOT; --parent)
                downheap(parent);
        }

        void upheap(size_t child)
        {
            size_t parent = child>>1;
            size_t extremeIdx;

            if(child<=ROOT) return;

            extremeIdx=extrema(parent, child);

            if(extremeIdx != parent)
            {
                std::swap(heap[parent],heap[child]);
                upheap(parent);
            }
        }

        void downheap(size_t parent)
        {   
            size_t extremeIdx;
            size_t child{parent<<1};

            if(isLeaf(parent)) return;

            extremeIdx=extrema(parent, child);
            ++child;

            if(child<=count) 
                extrema(extremeIdx, child);

            if(extremeIdx != parent)
            {
                std::swap(heap[parent], heap[extremeIdx]);
                downheap(extremeIdx);
            }
        }

        size_t extrema(size_t a, size_t b)
        {
            return compare(heap[a], heap[b]) ? a : b;
        }

        bool isLeaf(size_t idx) {return (idx<<1) > count;}

        void resize()
        {
            T* newHeap;
            currentSize += DEFAULT_SIZE;
            newHeap = new T[currentSize]; 
            for (size_t i = 1; i <= count; i++)
            {
                newHeap[i]=heap[i];
            }
            
            delete[] heap;
            heap=newHeap;
        }
};


#endif /* B344C7BF_B3E6_4DBC_8565_34DCB12166EC */
