#include"set.h"
#include"hash_set.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"



#define HCFunction [](const int& key){return key;}
#define TEST_VAL 5
#define SETUP HashSet<int>* h{new HashSet<int>(HCFunction)}
#define TEARDOWN delete h

void testAdd();
void testRemove();
void testEmpty();
void testContains();
void testSize();

int main(int argc, char const *argv[])
{
    testAdd();
    testRemove();
    testEmpty();
    testContains();
    testSize();
    return 0;
}

void testAdd()
{
    SETUP;
    h->add(TEST_VAL);

    testTrue(!h->empty(), "test set is not empty after add");

    TEARDOWN;
}


void testRemove()
{
    SETUP;
    h->add(TEST_VAL);
    h->remove(TEST_VAL);

    testTrue(h->empty(), "test set is empty after remove");

    TEARDOWN;
}

void testEmpty()
{
    SETUP;
    h->add(TEST_VAL);
    testTrue(!h->empty(), "test set is not empty after add");

    h->remove(TEST_VAL);
    testTrue(h->empty(), "test set is empty after remove");

    TEARDOWN;
}

void testContains()
{
    SETUP;
    h->add(TEST_VAL);
    testTrue(h->contains(TEST_VAL), "test set contains added item");

    TEARDOWN;
}

void testSize()
{
    SETUP;
    h->add(TEST_VAL);
    h->add(4);
    h->add(3);
    testTrue(h->size()==3, "test set contains added item");

    TEARDOWN;
}


