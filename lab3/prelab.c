/*Name:     Sean Brennan
 *Pawprint: slbvp6
 *Lab:      Lab_3
 *Date:     09/03/2019
 */
#include <stdio.h>
#include <stdlib.h>

int* createIntArray(int size, int init);
void* createArray(int size, int elemSize);
void initCharArray(char* charPtr, int size);

int main(void){
    int size, init, i;
    int *intArray;
    char *charArray;
    
    //Test createIntArray()
    printf("Enter the size of the integer array:\n");
    scanf("%d", &size);
    printf("\nEnter the initialize value:\n");
    scanf("%d", &init);
    intArray=createIntArray(size, init);
    for(i=0; i<size; i++){
        printf("Array[%d]: %d\n", i, intArray[i]);
    }
    //Test createArray()
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    charArray=createArray(size, sizeof(char));
    printf("Address of array: %p\n", charArray);
    initCharArray(charArray, size);
    for(i=0; i<size; i++){
        printf("array[%d]= %d\n", i, charArray[i]);
    }

    return 0;
}
int* createIntArray(int size, int init){
    int* array;
    
    if((array=malloc(size*sizeof(int)))==NULL){
        printf("!***ERROR*** could not allocate memory!\n\n\n");
    }
    else{
        for(int i=0; i<size; i++){
            array[i]=init;
        }
    }
    return array;
}
void* createArray(int size, int elemSize){
    void* array;
    
    if((array=malloc(size*elemSize))==NULL){ //Error checking
        printf("!***ERROR*** could not allocate memory!\n\n\n");
    }
    
    return array;
}
void initCharArray(char* charPtr, int size){
    for(int i=0; i<size; i++){
        charPtr[i]='c';
    }
}