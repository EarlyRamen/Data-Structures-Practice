#ifndef SIMPLE_CONTAINER_H
#define SIMPLE_CONTAINER_H

template<typename T>
struct SimpleContainer{
    virtual ~SimpleContainer() { };
    virtual void add(const T&)=0;
    virtual void remove()=0;
    virtual T peek() const =0;
    virtual bool empty() const =0;
};


#endif /*SIMPLE_CONTAINER_H*/