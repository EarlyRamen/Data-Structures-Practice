#include <cstddef>
#include <stdexcept>
#ifndef BD608A08_6903_4B11_9615_06FC127A2EE1
#define BD608A08_6903_4B11_9615_06FC127A2EE1

template<typename T>
class Searcher{
    public:
        //array is sorted
        static int binSearch(const T array[], int count, const T& item){
            if(count < 1) return -1;
            return binSearch(array, 0, count-1, item);
        }

    private:
        static int binSearch(const T array[], int start, int end, const T& term){
            int mid;
            if(start>end) return -1; 
            mid=(start+end)>>1;

            if(array[mid]==term){
                return mid;
            }

            if(array[mid]<term){
                return binSearch(array, mid+1, end, term);
            }

            return binSearch(array, 0, mid-1, term);
        }
};

#endif /* BD608A08_6903_4B11_9615_06FC127A2EE1 */
