#include "C:\Users\12203\Downloads\CSCI240\common\test.h"
#include "search.h"


void testMembership();
void testNonMembership();

int main(int argc, char const *argv[])
{
    testMembership();
    testNonMembership();
    return 0;
}

void testMembership(){
    int array[]{0,1,2,3,4,5,6,7,8,9};
    int count=sizeof(array)/sizeof(array[0]);

    testTrue(Searcher<int>::binSearch(array, count,0)==0, "test 0 membership");
    testTrue(Searcher<int>::binSearch(array, count,9)==9, "test 9 membership");
    testTrue(Searcher<int>::binSearch(array, count,4)==4, "test 4 membership");
}

void testNonMembership(){
    int array[]{0,1,2,3,4,5,6,7,8,9};
    int count=sizeof(array)/sizeof(array[0]);

    testTrue(Searcher<int>::binSearch(array, count,11)==-1, "test 11 non membership");
    testTrue(Searcher<int>::binSearch(array, count,12)==-1, "test 12 non membership");
    testTrue(Searcher<int>::binSearch(array, count,13)==-1, "test 13 non membership");
}
