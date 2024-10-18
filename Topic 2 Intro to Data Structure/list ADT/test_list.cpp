// who:  Ruiting Chen
// what: Test Linked List
// why:  List ADT
// when: 

#include <iostream>

#include "C:\Users\12203\Downloads\CSCI240\common\test.h"
#include "list.h"
#include "linked_list.h"
#include "array_list.h"

#define SETUP_A List<int>* a=new ArrayList<int>
#define SETUP_L List<int>* l=new LinkedList<int>
#define TEARDOWN_A delete a
#define TEARDOWN_L delete l
#define QUICKADD for (size_t i = 1; i <= 3; ++i) {a->add(i);l->add(i);}
#define TEST_VALUE 5

void testInitState();
void testAdd();
void testInsert();
void testRemoveOnPos();
void testRemove();
void testReplace();
void testAt();
void testContains();
void testSize();
void testEmpty();
void testClear();
void testExceptOnOOB();
void testExceptOnEmpty();

int main(int argc, char const *argv[])
{
    testInitState();
    testAdd();
    testInsert();
    testRemoveOnPos();
    testRemove();
    testReplace();
    testAt();
    testContains();
    testSize();
    testEmpty();
    testClear();
    testExceptOnOOB();
    testExceptOnEmpty();
    return 0;
}

void testInitState()
{
    SETUP_A;
    SETUP_L;

    testTrue(a->empty()&&l->empty(), "test list is initially empty"); 

    TEARDOWN_A;
    TEARDOWN_L;
}

void testAdd()
{
    SETUP_A;
    SETUP_L;

    a->add(TEST_VALUE);
    l->add(TEST_VALUE);

    testFalse(a->empty() && l->empty(), "test list is not empty after an added item"); 
    
    TEARDOWN_A;
    TEARDOWN_L;
}

void testInsert()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;

    a->insert(TEST_VALUE,2);
    l->insert(TEST_VALUE,2);

    testTrue(a->at(2)==TEST_VALUE && l->at(2)==TEST_VALUE, "test list inserted TEST_VALUE at position 2");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testRemoveOnPos()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    a->remove(2);
    l->remove(2);
    
    testTrue(a->at(2)==3 && l->at(2)==3, "test list removed 2 at position 2");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testRemove()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    a->remove();
    l->remove();
    
    testTrue(a->at(1)==2 && l->at(1)==2, "test list removed the first item");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testReplace()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    a->replace(TEST_VALUE, 1);
    l->replace(TEST_VALUE, 1);
    
    testTrue(a->at(1)==TEST_VALUE && l->at(1)==TEST_VALUE, "test list replaced item at position 1 with TEST_VALUE");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testAt()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    
    testTrue(a->at(3)==3 && l->at(3)==3, "test list at() returned the item at positon 3");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testContains()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    
    testTrue(a->contains(3) && l->contains(3), "test list returned true with contained item");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testSize()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    
    testTrue(a->size()==3 && l->size()==3, "test list returned the correct size");

    TEARDOWN_A;
    TEARDOWN_L;
}

void testEmpty()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    
    testTrue(!a->empty() && !l->empty(), "test list returned false when list is not empty");

    TEARDOWN_A;
    TEARDOWN_L; 
}

void testClear()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;
    a->clear();
    l->clear();
    
    testTrue(a->empty() && l->empty(), "test list is cleared");

    TEARDOWN_A;
    TEARDOWN_L; 
}

void testExceptOnOOB()
{
    SETUP_A;
    SETUP_L;

    QUICKADD;

    try{
        a->remove(4);
        l->remove(4);
        testFail("test throw out_of_range error on out of bound remove");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw out_of_range error on out of bound remove");
    }
    
    try{
        a->insert(TEST_VALUE,4);
        l->insert(TEST_VALUE,4);
        testFail("test throw out_of_range error on out of bound insert");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw out_of_range error on out of bound insert");
    }

    try{
        a->replace(TEST_VALUE,4);
        l->replace(TEST_VALUE,4);
        testFail("test throw out_of_range error on out of bound replace");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw out_of_range error on out of bound replace");
    }

    try{
        a->at(4);
        l->at(4);
        testFail("test throw out_of_range error on out of bound at");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw out_of_range error on out of bound at");
    }

    TEARDOWN_A;
    TEARDOWN_L; 
}

void testExceptOnEmpty()
{
    SETUP_A;
    SETUP_L;

    try{
        a->remove();
        l->remove();
        testFail("test throw logic_error on empty remove");
    }
    catch(const std::logic_error& e)
    {
        testPass("test throw logic_error on empty remove");
    }

    TEARDOWN_A;
    TEARDOWN_L; 
}