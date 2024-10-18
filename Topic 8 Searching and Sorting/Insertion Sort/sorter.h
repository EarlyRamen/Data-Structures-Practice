#ifndef E11BCFFA_8653_47AB_A1DF_0B353F3FD543
#define E11BCFFA_8653_47AB_A1DF_0B353F3FD543
#include <cstddef>
#include <functional>

template<typename T>
class Sorter{
    public:
        static void bubbleSort(T array[], size_t size, std::function<bool(const T&, const T&)> compare){
            bool swapped;
            for (size_t i = size-1; i > 0; --i){
                swapped=false;
                for (size_t j = 0; j < i; ++j){
                    if(!compare(array[j], array[j+1])){
                    swap(array[j], array[j+1]);
                    swapped=true;
                    }
                }

                if(!swapped) return; 
            }
        }

        static void selectionSort(T array[], size_t size, std::function<bool(const T&, const T&)> compare){
            size_t extremeIdx;  
            for (size_t i = 0; i < size - 1; ++i){
                extremeIdx=extrema(array, i, size-1, compare);
                if(extremeIdx!=i) swap(array[i], array[extremeIdx]);
            }
        }

        static void insertionSort(T array[], size_t size, std::function<bool(const T&, const T&)> compare)
        {
            T item;
            int i;
            int j;

            for (i = 1; i < size; ++i)
            {
                item=array[i];
                j = i-1;
                while (j>=0 && !compare(array[j], item))
                {
                    array[j+1]=array[j];
                    --j;
                }   
                array[j+1]=item;   
            }
        }


    private:
        static void swap(T& a, T& b){
            T tmp=a;
            a=b;
            b=tmp;
        }

        static size_t extrema(T array[], size_t start, size_t end, std::function<bool(const T&, const T&)> compare){
            size_t extremeIdx=start;

            for (size_t i = start+1; i <= end; ++i){
                if(compare(array[i], array[extremeIdx])) extremeIdx=i;
            }
            return extremeIdx;
        }
};




#endif /* E11BCFFA_8653_47AB_A1DF_0B353F3FD543 */
