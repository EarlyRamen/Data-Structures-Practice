#ifndef BD19C065_EF7C_4DE0_A32D_F7B809621527
#define BD19C065_EF7C_4DE0_A32D_F7B809621527
#include <cstddef>
#include <functional>
#include <cstdint>
#include <vector>

using Bucket = std::vector<uint32_t>;

template<typename T>
class Sorter
{
    using Comparator = std::function<bool(const T&, const T&)>;
    public:

        static void radixSort(uint32_t array[], size_t size)
        {
            Bucket bucket[2];
            bucket[0].reserve(size);
            bucket[1].reserve(size);
            const uint32_t MASK {1};
            size_t k {0};
            size_t i;
            size_t j;
            size_t v0idx;
            size_t v1idx;

            for (i = 0; i < sizeof(array[0])<< 3; ++i)
            {
                v0idx=0;
                v1idx=0;
                k=0;

                for (j = 0; j < size; ++j)
                    (((array[j] & MASK << i)==0) 
                        ? bucket[0][v0idx++] : bucket[1][v1idx++]) = array[j];
            
                for (j = 0; j < v0idx; ++j)
                    array[k++]=bucket[0][j];

                for (j = 0; j < v1idx; ++j)
                    array[k++]=bucket[1][j];
            }
        }

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

        static size_t partition(uint32_t array[], size_t start, size_t end)
        {
            T pivotVal{array[end]};
            size_t pivotPt{start};
            for (size_t i = start; i < end; ++i)
            {
                if(array[i]<=pivotVal) continue;

                swap(array[pivotPt],array[i]);
                ++pivotPt;
            }
            
            if (pivotPt!=end)
                swap(array[pivotPt], array[end]);

            return pivotPt;
        }
};



#endif /* BD19C065_EF7C_4DE0_A32D_F7B809621527 */
