#ifndef HEAP_H
#define HEAP_H

template<typename T>
struct Heap
{
    virtual ~Heap() {  }
    virtual void add(const T&) = 0;
    virtual void remove() = 0;
    virtual T get() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif /* HEAP_H */
