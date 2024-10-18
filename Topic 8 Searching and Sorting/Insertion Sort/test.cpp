#include "sorter.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"

#define ARRAY_SIZE 8
#define TEST_ARRAY int array[]{5, 2, 7, 3, 2, 9, 1, 2}
#define SOL_ARRAY int sarray[]{1, 2, 2, 2, 3, 5, 7, 9}


void testInsertionSort();
bool compare(int a, int b){return a<b;}

int main(int argc, char const *argv[])
{
    testInsertionSort();
    return 0;
}

void testInsertionSort(){
    TEST_ARRAY;
    SOL_ARRAY;
    Sorter<int>::insertionSort(array, ARRAY_SIZE, compare);
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        if (array[i]!=sarray[i])
        {
            testFail("Not ordered");
            return;
        }
    }
    testPass("test ordered");
}
