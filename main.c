#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <assert.h>

void assert_sort(int32_t list[],uint32_t size){
int32_t pass;
for(pass=0;pass<size-1;++pass){
   assert(list[pass]<=list[pass+1]);
}
}
void test_sort(){
    int32_t input []={23,19,98,76,62,5,31,63,54,86};
    //bubble_sort(input,10);
    //assert_sort(input,10);
    //selection_sort(input,10);
    //assert_sort(input,10);
    insertion_sort(input,10);
    assert_sort(input,10);
}
int main()
{
    //printf("Hello world!\n");
    test_sort();
    return 0;
}
