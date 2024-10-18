#include <stdexcept>

#include "list.h"

#ifndef ARRAY_LIST
#define ARRAY_LIST

#define INIT_SIZE 16
#define RESIZE_BY 2

template<typename T>
class ArrayList : public List<T>
{
    public:
        ArrayList()
        {
            count=0;
            currentSize=INIT_SIZE-1;
            array=new T[INIT_SIZE];
        }

        ~ArrayList() override
        {
            delete[] array;
        }

        void add(const T& item) override
        {
            if(count==currentSize) resize();
            array[++count]=item;
        }

        void insert(const T& item, size_t pos) override
        {
            if(pos<1 || pos>currentSize) throw std::out_of_range("insert on a out of range position");

            if(pos==currentSize) resize();

            for (size_t i = currentSize; i >= pos; --i)
            {
                array[i]=array[i-1];
            }

            array[pos]=item;
            ++count;
        }

        T remove(size_t pos) override
        {
            if(pos<1 || pos>currentSize) throw std::out_of_range("remove on a out of range position");

            T returnItem=array[pos];

            for (size_t i = pos; i < currentSize; ++i)
            {
                array[i]=array[i+1];
            }

            --count;

            return returnItem;
        }

        T remove() override
        {
            if(empty()) throw std::logic_error("remove on empty list");

            T rtnItem=array[1];

            for (size_t i = 1; i < currentSize; ++i)
            {
                array[i]=array[i+1];
            }

            --count;
            return rtnItem;
        }

        void replace(const T& item, size_t pos) override
        {
            if(pos<1 || pos>currentSize) throw std::out_of_range("remove on a out of range position");
            array[pos]=item;
        }


        T at(size_t pos) const override
        {
            if(pos<1 || pos>currentSize) throw std::out_of_range("remove on a out of range position");
            return array[pos];
        }

        bool contains(const T& item) const override
        {
            for (size_t i = 1; i <= currentSize; ++i)
            {
                if(array[i]=item) return true;
            }
            return false;
        }

        size_t size() const override
        {
            return count;
        }

        bool empty() const override
        {
            return count==0;
        }

        void clear() override
        {
            count=0;
        }

    private:
        T* array;
        size_t count;
        size_t currentSize;
        size_t back;

        void resize()
        {
            size_t newSize=INIT_SIZE*RESIZE_BY;
            T* newArray=new T[newSize];

            for (size_t i = 1; i <= currentSize; i++)
            {
                newArray[i]=array[i];
            }
            
            delete[] array; 
            currentSize=newSize-1;
            array=newArray; 
        }
};

#endif /* ARRAY_LIST */

