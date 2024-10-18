#include "C:\Users\12203\Downloads\CSCI240\common\test.h"
#include "simple_container.h"
#include "array_queue.h"

#define SETUP SimpleContainer<int>* q{new ArrayQueue<int>}
#define TEARDOWN delete q
#define TEST_VAL 5

void testEmptyQueue();
void testAddItem();
void testPeekItem();
void testRemove();
void testRemoveOrder();
void testExceptionOnEmptyPeek();
void testExceptionOnEmptyRemove();


int main(int argc, char const *argv[]){
    testEmptyQueue();
    testAddItem();
    testPeekItem();
    testRemove();
    testRemoveOrder();
    testExceptionOnEmptyPeek();
    testExceptionOnEmptyRemove();
    return 0;
}


void testEmptyQueue(){
    SETUP;
    testTrue(q->empty(), "test queue is initially empty");
    TEARDOWN;
}

void testAddItem(){
    SETUP;
    q->add(TEST_VAL);
    testTrue(!q->empty(), "test not empty after an added item");
    TEARDOWN;
}

void testPeekItem(){
    SETUP;
    q->add(TEST_VAL);
    testTrue(q->peek()==5, "test peek returns an added item");
    TEARDOWN;
}

void testRemove()
{
    SETUP;
    q->add(TEST_VAL);
    q->remove();
    testTrue(q->empty(), "test empty on a final remove");
    TEARDOWN;
}

void testRemoveOrder(){
    SETUP;  
    size_t i;
    for (i = 0; i < TEST_VAL; ++i){
        q->add(i);
    }

    for (i = 0; i < TEST_VAL; ++i){
        if(q->peek()!=i){
            testFail("test ordering");
            break; 
        }
        q->remove();
    }

    if(i==TEST_VAL) testPass("test ordering");

    TEARDOWN;
}

void testExceptionOnEmptyPeek(){
    SETUP;
    try
    {
        q->peek();
        testFail("test throw logic error on empty peek");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw logic error on empty peek");
    }
    
    TEARDOWN; 
}

void testExceptionOnEmptyRemove(){
    SETUP;
    try
    {
        q->remove();
        testFail("test throw logic error on empty remove");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw logic error on empty remove");
    }
    TEARDOWN; 
}