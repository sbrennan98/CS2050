/*Name:     Sean Brennan
 *PawPrint: slbvp6
 *Lab:      PreLab_4
 *Date:     09/06/2019
 */

#include <stdio.h>
#include <stdlib.h>

void* createArray(int n, int size);//Creates an array
int getArraySize(void* array);
void freeArray(void* array);

void* makeArray(); //Takes user input to create an array
void initIntArray(int* array, int n);//Initializes all values of an integer array to the integer given. Remember to cast if you're passing a non-integer array.

int main(void){
    //Variable Declarations
    void* array;
    //Call functions
    array=makeArray();
    printf("Array size: %d\n", getArraySize(array));
    initIntArray((int*)array, 10);
    for(int i=0; i<((int*)array)[-1];i++){
        printf("Array[%d]= %d\n", i, ((int*)array)[i]);
    }
    freeArray(array);
    return 0;
}
void* createArray(int n, int size){
    void *array;

    if((array=malloc(n*size))==NULL){
        printf("*!ERROR! COULDN'T ALLOCATE MEMORY*\n");
        return NULL;
    }
    else{
        ((int*)array)[0]=n;
        array=((int*)array)+1;
    }
    return array;
}
int getArraySize(void* array){
    return ((int*)array)[-1];
}
void freeArray(void* array){
    free(((int*)array)-1);
}
void* makeArray(){
    int n, size;
    printf("How many elements?\n");
    scanf("%d", &n);
    printf("Type:\n(1)int\n(2)double\n(3)char\n");
    scanf("%d", &size);
    if(size==1){
        return createArray(n, sizeof(int));
    }
    else if(size==2){
        return createArray(n, sizeof(double));
    }
    else if(size==3){
        return createArray(n, sizeof(char));
    }
    
    printf("*!Error! Couldn't make array properly*\n");
    return NULL;
}
void initIntArray(int* array, int n){
    for(int i=0; i<array[-1]; i++){
        array[i]=n;
    }
}