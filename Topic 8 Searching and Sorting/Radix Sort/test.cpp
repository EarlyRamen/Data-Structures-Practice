#include "sorter.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"

#define TEST_VALS uint32_t array[]{5, 2, 7, 3, 2, 9, 1, 2}

void testRadixSort();
bool compare(int a, int b){return a<b;}

int main(int argc, char const *argv[])
{   
    testRadixSort();
    return 0;
}

void testRadixSort()
{
    TEST_VALS;
    int lastValue;
    size_t size=sizeof(array) / sizeof(array[0]);

    Sorter<uint32_t>::radixSort(array, size);

    lastValue=array[0];
    for (size_t i = 1; i < size; ++i){
        if(lastValue>array[i]){
        testFail("RadixSort properly ordered");
        return;
        }
        lastValue = array[i];
    }
    testPass("RadixSort properly ordered");
}
