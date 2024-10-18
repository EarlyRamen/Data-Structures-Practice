#include <stdexcept>
#include "bucket_interface.h"

#ifndef BUCKET_H
#define BUCKET_H

#define INIT_SIZE 16
#define RESIZE_BY 16

template<typename T>
class ArrayBucket:public Bucket<T>{
    public:
        ArrayBucket():count{}, currentSize{INIT_SIZE}, array{new T[INIT_SIZE]}{}

        ~ArrayBucket() {delete[] array;}

        //adds an item to the collection
        void add(const T& item){
            if(count==currentSize) resize();

            array[count++] = item;
        }

        //removes and returns an arbitrary item from the collection
        T remove(){
            if(empty()) throw std::logic_error("remove on empty bucket");
            return array[--count];
        }
        
        //removes all of the items that match the argument
        bool remove(const T& item){
            size_t ptr{0};
            bool removed{false};
            while(ptr<count){
                if(array[ptr]==item){
                    array[ptr] = array[--count];
                    removed=true;
                }
                else{
                    ++ptr;
                }
            }
            return removed;  
        }

        //checks collection for membership
        bool contains(const T& item) const{
            for (size_t i = 0; i < count; ++i){
                if(array[i]==item) return true;
            }
            return false;
        }

        //returns an array of items
        T* toArray() const{
            T* rtnArray=new T[count];
            for (size_t i = 0; i < count; ++i){
                rtnArray[i]=array[i];
            }
            return rtnArray;
        }

        //empties the collection 
        void clear(){
            count=0;
        }

        //returns the number of items
        size_t size() const{
            return count; 
        } 

        //retuns true if empty or false otherwise
        bool empty() const{
            return count == 0;
        }

    private:
        T* array;
        size_t count;
        size_t currentSize; 

        void resize(){
            size_t newSize{currentSize+RESIZE_BY};
            T* newArray{new T[newSize]};

            for(size_t i=0; i<currentSize;++i){
                newArray[i]=array[i];
            }

            delete[] array; 
            currentSize = newSize;
            array = newArray;
        }
};

#endif /*BUCKET_H"*/