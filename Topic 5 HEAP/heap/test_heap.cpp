#include "heap.h"
#include "array_heap.h"
#include "priority_queue.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"

#define SETUP PriorityQueue<int>* p{new PriorityQueue<int>([](const T& a, const T& b) {return a <= b;})}
#define TEARDOWN delete p
#define TEST_Vals int array[]{10,9,8,7,6}
#define TEST_Key size_t key[]{5,4,2,3,1} 

template<typename T>
void testEnqueue();
template<typename T>
void testDequeue();
template<typename T>
void testFront();
template<typename T>
void testEmpty();
template<typename T>
void testClear();
template<typename T>
void testOrdering();

int main(int argc, char const *argv[])
{
    testEnqueue<int>();
    testDequeue<int>();
    testFront<int>();
    testEmpty<int>();
    testClear<int>();
    testOrdering<int>();
}

template<typename T>
void testEnqueue()
{
    SETUP;
    TEST_Vals;
    TEST_Key;
    for (size_t i = 0; i < (sizeof(array)/sizeof(array[1])); ++i)
    {
        p->enqueue(key[i],array[i]);
    }
    testTrue(p->empty()==false, "test PriorityQueue added items");
    TEARDOWN;
}

template<typename T>
void testDequeue()
{
    SETUP;
    TEST_Vals; 
    TEST_Key;
    for (size_t i = 0; i < (sizeof(array)/sizeof(array[1])); ++i)
    {
        p->enqueue(key[i],array[i]);
    }
    p->dequeue();
    testTrue(p->front()==8, "test PriorityQueue removed the item with the lowest key");
    TEARDOWN;
}

template<typename T>
void testFront()
{
    SETUP;
    TEST_Vals; 
    TEST_Key;
    for (size_t i = 0; i < (sizeof(array)/sizeof(array[1])); ++i)
    {
        p->enqueue(key[i],array[i]);
    }
    testTrue(p->front()==6, "test PriorityQueue returned the item at front");
    TEARDOWN;
}

template<typename T>
void testEmpty()
{
    SETUP;
    testTrue(p->empty()==true, "test PriorityQueue is empty");
    TEARDOWN;
}

template<typename T>
void testClear()
{
    SETUP;
    TEST_Vals; 
    TEST_Key;
    for (size_t i = 0; i < (sizeof(array)/sizeof(array[1])); ++i)
    {
        p->enqueue(key[i],array[i]);
    }
    p->clear();
    testTrue(p->empty()==true, "test PriorityQueue is cleared");
    TEARDOWN;
}

template<typename T>
void testOrdering()
{
    SETUP;
    TEST_Vals; 
    TEST_Key;
    for (size_t i = 0; i < (sizeof(array)/sizeof(array[1])); ++i)
    {
        p->enqueue(key[i], array[i]);
    }

    bool fi=p->front()==6;
    p->dequeue();

    bool s=p->front()==8;
    p->dequeue();

    bool t=p->front()==7;
    p->dequeue();

    bool fo=p->front()==9;

    testTrue((fi&&s&&t&&fo), "test PriorityQueue has correct ordering");
}







