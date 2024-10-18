#include "sorter.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"

#define TEST_VALS int array[]{5, 2, 7, 3, 2, 9, 1, 2}

void testBubbleSort();
void testSelectionSort();
bool compare(int a, int b){return a<b;}

int main(int argc, char const *argv[])
{
    testBubbleSort();
    testSelectionSort();
    return 0;
}

void testBubbleSort(){
    TEST_VALS;
    int lastValue;
    size_t size=sizeof(array) / sizeof(array[0]);

    Sorter<int>::bubbleSort(array, size, [](int a, int b) {return a<b;});

    lastValue=array[0];
    for (size_t i = 1; i < size; ++i){
        if(lastValue>array[i]){
        testFail("BubbleSort properly ordered");
        return;
        }
        lastValue = array[i];
    }
    testPass("BubbleSort properly ordered");
}

void testSelectionSort(){
    TEST_VALS;
    int lastValue;
    size_t size=sizeof(array) / sizeof(array[0]);

    Sorter<int>::selectionSort(array, size, compare);

    lastValue=array[0];
    for (size_t i = 1; i < size; ++i){
        if(lastValue>array[i]){
        testFail("SelectionSort properly ordered");
        return;
        }
        lastValue = array[i];
    }
    testPass("SelectionSort properly ordered");
}
