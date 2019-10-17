/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_2           *
 *Date:     08/27/2019      *
 ****************************/
#include <stdio.h>
#include <stdlib.h>

void computeSumAve(int arr[], int size, int* sumPtr, float* avgPtr); //Computes the sum and average values of an integer array and returns the values by reference.
void printSumAvg(float *avgPtr, int *sumPtr); //Prints the sum and average of numbers in an integer array.
void printArrInfo(int arr[], int size); //Prints the information of an integer array.

//Calling program(main)
int main(void){
    float avg=0;
    int size=10, array[10]={5,-9,8,2,-7,10,12,-9,3,-6}, sum=0;
    int *sumPtr=(&sum);
    float *avgPtr=(&avg);

    computeSumAve(array, size, sumPtr, avgPtr);
    printArrInfo(array, size);
    printSumAvg(avgPtr, sumPtr);
    
    return 0;
}
void computeSumAve(int arr[], int size, int* sumPtr, float* avgPtr){
    int sum=0;
    float avg=0;

    //compute sum
    for(int i=0; i<size; i++){
        sum=sum+arr[i];
    }
    //compute average
    avg=((float)sum/(float)size); //cast EACH INTEGER as a float so the division is done properly

    *sumPtr=sum;
    *avgPtr=avg;
}
void printSumAvg(float *avgPtr, int *sumPtr){
    printf("Sum of Array: %d\nAvg of Array: %f\n", *sumPtr, *avgPtr);
}
void printArrInfo(int arr[], int size){
    printf("Array Size: %d\nArray Values: ", size);
    for(int i=0; i<size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n"); //new line for next program
}