/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_4           *
 *Date:     09/10/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define MIN 1
//Lab Required Functions
void* createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);
//Additional Functions
void initIntArray(void* array);
int randInt();
int getIntArrayMax(void* array);
/* createArray(): Takes the number of indeces, and the size of the element.
 *  -Creates an array that hides space for two integers before it.
 * getArraySize(): Takes a void array.
 *  -Returns the size of an array created by createArray by returning the value stored in ((int)array)[-1].
 * freeArray(): Takes a void array.
 *  -Frees an array created by createArray to include the hidden space allocated for two integers.
 * initIntArray(): Takes a void array.
 *  -Casts a void array to integer and initializes the values to random integers as well as initialize the max value of the array in ((int*)array)[-2].
 * randInt(): VOID
 *  -Returns a random integer vaue between the numbers MIN and MAX.
 * getIntArrayMax(): Takes an integer array.
 *  -Gets the maximum value of an integer array created with createArray().
 */

//main()
int main(void){
    srand(time(NULL)); //for random integers
    //Variable Declarations
    int n=1000; //size of array
    void* array;
    //Calling Functions
    array=createArray(n, sizeof(int));
    printf("Size of the array: %d\nMaximum value in the array: %d\n", getArraySize(array), getIntArrayMax(array));
    for(int i=0; i<n; i++){
        printf("Array[%d]: %d\n", i, ((int*)array)[i]);
    }
    //end program
    freeArray(array);
    return 0;
}
void* createArray(int n, int size){
    void *array;

    if((array=malloc((n*size)+(2*sizeof(int))))==NULL){//Allocates memory for the array PLUS the size of two integers
        printf("*!ERROR! COULDN'T ALLOCATE MEMORY*\n");
        return NULL;
    }
    else{
        array=((int*)array)+2;
        ((int*)array)[-1]=n;
        initIntArray(array);
    }
    return array;
}
int getArraySize(void* array){
    return ((int*)array)[-1];
}
void freeArray(void* array){
    free(((int*)array)-2);
}
void initIntArray(void* array){
    int i, max;
    for(i=0; i<((int*)array)[-1]; i++){
        ((int*)array)[i]=randInt();
    }
    //Then scan the array for the maximum value and store it in array[-2].
    for(i=0; i<((int*)array)[-1]; i++){
        if(max<((int*)array)[i]){
            max=((int*)array)[i];
        }
    }
    ((int*)array)[-2]=max;
}
int randInt(){
    return (rand()%(MAX-MIN+1)+MIN);
}
int getIntArrayMax(void* array){
    return ((int*)array)[-2];
}