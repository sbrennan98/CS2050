//We do not have an actual lab this week, just instructions and notes on breakpoints, debugging, header files, etc.

#include <stdlib.h>
#include <stdio.h>

int main(void){
    int n, array[3]={0,1,2},*ptr=NULL;

    //ptr=malloc(sizeof(int));
    n=5;
    *ptr=array[0]; // Breakpoint set here: program breaks here, only memory elements above will be stored in cache.

    printf("Current n is %d, current value in ptr is %d\n", n, *ptr);

}
/* Header Files



Header files: lab14.h & lab14.c
Testing file: main.c

*/