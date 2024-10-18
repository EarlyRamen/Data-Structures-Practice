#include "C:\Users\12203\Downloads\CSCI240\common\test.h"
#include "splaytree.h"
#include <iostream>

#define SETUP SplayTree<int>* b{new SplayTree<int>}
#define TEARDOWN delete b

void testAdd();
void testRemove();
void testContain();
void testSize();
void testEmpty();
void testOrder();
void testPre();
void testIn();
void testPost();
void testLevel();

int main(int argc, char const *argv[])
{
    testAdd();
    testRemove();
    testContain();
    testSize();
    testEmpty();
    testOrder();
    testPre();
    testIn();
    testPost();
    testLevel();
}

void testAdd()
{
    SETUP;
    b->add(10);
    b->add(5);
    testTrue(b->empty()==false, "test tree is not empty after add");
    TEARDOWN;
}

void testRemove()
{
    SETUP;
    b->add(10);
    b->add(5);
    b->remove(5);
    b->remove(10);
    testTrue(b->empty()==true, "test tree is empty after remove");
    TEARDOWN;
}

void testContain()
{
    SETUP;
    b->add(10);
    testTrue(b->contains(10)==true, "test tree contains the item");
    TEARDOWN;
}

void testSize()
{
    SETUP;
    b->add(10);
    b->add(5);
    testTrue(b->size()==2, "test tree returns the correct size after add");
    TEARDOWN;
}

void testEmpty()
{
    SETUP;
    testTrue(b->empty(), "test tree is initally empty");
    TEARDOWN;
}

void testOrder()
{
    SETUP;
    b->add(10);
    b->add(5);
    testTrue(b->get()==5, "test tree is in correct order that item just added is at the root");
    TEARDOWN;
}

void testPre()
{
    SETUP;
    b->add(1);
    b->add(2);
    b->add(3);
    int preArray[3]={3,2,1};
    int testArray[]{*(b->preOrder())};
    for (size_t i = 0; i < 3; ++i)
    {
        if(testArray[i]!=preArray[i])
        {
            testFail("Preorder does not return the correct order");
            return;
        }
    }
    testPass("Preorder returns the correct order");
    TEARDOWN;
}

void testIn()
{
    SETUP;
    b->add(1);
    b->add(2);
    b->add(3);
    int inArray[3]={1,2,3};
    int testArray[]{*(b->inOrder())};
    for (size_t i = 0; i < 3; ++i)
    {
        if(testArray[i]!=inArray[i])
        {
            testFail("Inorder does not return the correct order");
            return;
        }
    }
    testPass("Inorder returns the correct order");
    TEARDOWN;
}

void testPost()
{
    SETUP;
    b->add(1);
    b->add(2);
    b->add(3);
    int postArray[3]={1,2,3};
    int testArray[]{*(b->postOrder())};
    for (size_t i = 0; i < 3; ++i)
    {
        if(testArray[i]!=postArray[i])
        {
            testFail("Postorder does not return the correct order");
            return;
        }
    }
    testPass("Postorder returns the correct order");
    TEARDOWN;

}

void testLevel()
{
    SETUP;
    b->add(1);
    b->add(2);
    b->add(3);
    int levelArray[3]={3,2,1};
    int testArray[]{*(b->levelOrder())};
    for (size_t i = 0; i < 3; ++i)
    {
        if(testArray[i]!=levelArray[i])
        {
            testFail("Levelorder does not return the correct order");
            return;
        }
    }
    testPass("Postorder returns the correct order");
    TEARDOWN;
}

