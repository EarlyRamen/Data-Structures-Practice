#include "C:\Users\12203\Downloads\CSCI240\common\test.h"
#include "bucket_interface.h"
#include "linklist_bucket.h"

#define SETUP Bucket<int>* b{new LinkListBucket<int>}
#define TEARDOWN delete b

#define TEST_VALUE 5

void testIninialState();
void testAddFunction();
void testRemoveFunction();
void testRemoveQty();
void testContains();
void testRemoveSpecificItem();
void testRemoveSpecificItems();

int main(int argc, char const *argv[])
{
    testIninialState();
    testAddFunction();
    testRemoveFunction();
    testRemoveQty();
    testContains();
    testRemoveSpecificItem();
    testRemoveSpecificItems();
    return 0;
}

void testIninialState(){
    SETUP;

    testTrue(b->empty(), "test bucket is initially empty");

    testTrue(b->size()==0, "test bucket's initial size is 0");

    try
    {
        b->remove();
        testFail("test thast empty bucket throw an exception on remove");
    }
    catch(const std::logic_error&)
    {
        testPass("test thast empty bucket throw an exception on remove");
    }
    
    TEARDOWN;
}

void testAddFunction(){
    SETUP;

    b->add(TEST_VALUE);

    testFalse(b->empty(), "bucket should not be empty after add");

    testTrue(b->size()==1, "bucket size should be 1");

    TEARDOWN;
}

void testRemoveFunction(){
    SETUP;

    b->add(TEST_VALUE);

    testTrue(TEST_VALUE==b->remove(), "test remove returns the test value");

    TEARDOWN;
}

void testRemoveQty(){
    SETUP;
    int val;

    bool foundvalue[10]{};

    for (int i = 0; i < 10; ++i){
        b->add(i);
    }

    while(!b->empty()){
        foundvalue[b->remove()]=true;
    }

    for (size_t i = 0; i < 10; ++i){
        if(!foundvalue[i]){
            testFail("test remove added values"); 
            return; 
        }
    }

    testPass("test remove added values"); 

    TEARDOWN;
}

void testContains(){
    SETUP;

    b->add(TEST_VALUE);
    testTrue(b->contains(TEST_VALUE), "test contains a specific item");
    TEARDOWN;
}

void testRemoveSpecificItem(){
    SETUP;

    b->add(TEST_VALUE);
    testTrue(b->remove(TEST_VALUE), "test removes a specific item");

    TEARDOWN;
}

void testRemoveSpecificItems(){
    int testValues[]{1,2,3,4,4};

    SETUP;

    for (auto &i : testValues){
        b->add(i);
    }

    b->remove(4);
    testTrue(b->size()==3, "test removes of multiple equal items");
    TEARDOWN;
}
