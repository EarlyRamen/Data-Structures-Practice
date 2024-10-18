#include <stdexcept>
#include"simple_container.h"
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define INIT_SIZE 16
#define RESIZE_BY 2

template<typename T>
class ArrayQueue : public SimpleContainer<T>{
    public: 
        ArrayQueue(){
            count=0;
            currentSize=INIT_SIZE;
            array=new T[INIT_SIZE];
            front, back=0;
        }

        ~ArrayQueue() override{
            delete[] array;
        }

        void add(const T& item)override{
            if(count==currentSize) resize();

            array[count++]=item;
            front=0;
            back=count-1;
        }

        void remove()override{
            if(empty()){
                throw std::logic_error("remove on empty queue");
            }
            ++front;
            --count;
        }

        T peek() const override{
            if(empty()){
                throw std::logic_error("peek on empty queue");
            }
            return array[front];
        }

        bool empty() const override{
            return count==0;
        }

     private:
        T* array;
        size_t count;
        size_t currentSize; 
        size_t front;
        size_t back;

        void resize(){
            size_t newSize{currentSize*RESIZE_BY};
            T* newArray{new T[newSize]};

            for(size_t i=0; i<currentSize;++i){
                newArray[i]=array[front];
                front=(front+1)%count;
            }

            delete[] array; 
            currentSize = newSize;
            array = newArray;
            front=0;
            back=count-1;
        }
};


#endif /*ARRAY_QUEUE_H*/