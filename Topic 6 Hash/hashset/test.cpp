#include "bucket_set.h"
#include "C:\Users\12203\Downloads\CSCI240\common\test.h"

void testAdd();
void testContains();
void testRemove();
void testGet();
void testGetThrowsException();

#define TEST_STUDENT Student s{"a12345", "Fred", 2.6}
#define TEST_BUCKET BucketSet<Student> b;

struct Student
{
    std::string id;
    std::string name;
    double gpa;

    bool operator==(const Student& other) const { return id==other.id; }
    bool operator!=(const Student& other) const { return !(*this==other); }
};

int main(int argc, char const *argv[])
{

    testAdd();
    testContains();
    testRemove();
    testGet();
    testGetThrowsException();
    return 0;
}

void testAdd()
{
    TEST_BUCKET;
    TEST_STUDENT;

    testTrue(b.size()==0,"test size == 0 before add");
    testTrue(b.empty(),"test is empty before add");

    b.add(s);
    testTrue(b.size()>0,"test size != 0 after add");
    testTrue(!b.empty(),"test not empty after add");
}

void testContains()
{
    TEST_BUCKET;
    TEST_STUDENT;

    testFalse(b.contains(s), "test bucket does not contain the test student");
    b.add(s);

    testTrue(b.contains(s), "test bucket does contain the test student");
}


void testRemove()
{
    TEST_BUCKET;
    TEST_STUDENT;

    b.add(s);
    b.remove(s);

    testFalse(b.contains(s),"Doesn't contain student after removing");
    testTrue(b.size()==0,"test size ==0 after removing the only student");
}

void testGet()
{
    TEST_BUCKET;
    TEST_STUDENT;

    b.add(s);

    testTrue(s==b.get(s), "test that can get an added student");
}

void testGetThrowsException()
{
    TEST_BUCKET;
    TEST_STUDENT;

    try
    {
        b.get(s);
        testFail("test that can get throws exception if student not exist");
    }
    catch(const std::exception& e)
    {
        testPass("test that can get throws exception if student not exist");
    }
}