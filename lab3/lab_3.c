/*Name:     Sean Brennan
 *Pawprint: slbvp6
 *Lab:      Lab_3
 *Date:     09/03/2019
 */
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
#define UPPERVALUE 10
#define LOWERVALUE 1

void computeInOut(int arr[], int size, int lowBoundary, int highBoundary, int* inPtr, int* outPtr);
void* createArray(int elemSize, int elemNumber);
void initArray(int* array, int size);
int randInt(void);
void printArray(int* array, int* inPtr, int* outPtr, int size);

/*computeInOut(): Takes an array, the size of the array, the lowest possible value of an inlier, the highest possible value of an inlier, an integer pointer to the total number of inliers, and an integer pointer to the total number of outliers.
 *  -Counts the number of inliers and outliers in an integer array.
 *createArray(): Takes the number of elements of an array, and the size of each element. *MAY REQUIRE CASTING*
 *  -Creates an array of any data type by returning the address of void.
 *initArray(): Takes an integer array, and the size of the array.
 *  -Initializes an array with random values.
 *randInt(): VOID
 *  -Returns a random integer.
 *printArray(): Takes an integer array, a pointer to the number of inliers, a pointer to the number of outliers, and the size of the array.
 *  -Prints the values of an array, as well as the number of inliers and outliers.
 */


int main(void){
    //Use current time as seed for random generator
    srand(time(0));
    //Variable Declarations & Initializations
    int size = 10, lowBoundary = 3, highBoundary = 6, inlier=0, outlier=0;
    int *array=(int *)createArray(sizeof(int), size), *inPtr=&inlier, *outPtr=&outlier;
    //main()
    initArray(array, size);
    computeInOut(array, size, lowBoundary, highBoundary, inPtr, outPtr);
    printArray(array, inPtr, outPtr, size);
    
    free(array); //Free any allocated memory
    return 0;
}
void* createArray(int elemSize, int elemNumber){
    void* array;
    
    if((array=malloc(elemNumber*elemSize))==NULL){ //Error checking
        printf("!***ERROR*** could not allocate memory!\n\n\n");
        return NULL;
    }

    return array;
}
void computeInOut(int arr[], int size, int lowBoundary, int highBoundary, int* inPtr, int* outPtr){
    for(int i=0; i<size; i++){//Scans array and counts number of inliers & outliers
        if((arr[i]>=lowBoundary)&&(arr[i]<=highBoundary)){
            *inPtr+=1;
        }
        else{
            *outPtr+=1;
        }
    }
}
void initArray(int* array, int size){
    for(int i=0; i<size; i++){
        array[i]=randInt();
    }
}
int randInt(void){
    int i;
    i=(rand()%(UPPERVALUE-LOWERVALUE+1)+LOWERVALUE);
    return i;
}
void printArray(int* array, int* inPtr, int* outPtr, int size){
    for(int i=0; i<size; i++){
        printf("Array[%d]: %d\n", i, array[i]);
    }
    printf("There are %d inliers, and there are %d outliers.\n", *inPtr, *outPtr);
}
