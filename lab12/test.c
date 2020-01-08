/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_12          *
 *Date:     11/05/2019      *
 ****************************/
//Headers & Preprocessor 
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int arraySize; // the total size of the sorted array
    int availableIdx; // next available index in the sorted array (current size of array)
    int *sortedArray; // the sorted array
} PQueue;
//Function Prototypes
PQueue* initPQ(int n); // This function initializes a PQueue struct with availableIdx = 0, arraySize = the input integer, and creates an integer array with length = the input integer. It returns the initialized PQueue pointer.
int insertPQ(PQueue *pq, int n); // this function receives the current priority queue and a new integer value, then inserts the new integer into the sorted array in ascending order. It returns an error code: 0 if the insertion was successful, -1 if the insertion failed
int DeQueue(PQueue *pq, int *n); // this function receives the current priority queue and an integer pointer. It removes the maximum integer from the sorted array, stores the removed value into the integer pointer, then returns an error code: 0 if the deletion was successful, -1 if the deletion failed. This function has O(1) time complexity.
int findIdx(PQueue *pq, int n); // this function receives the current priority queue and a query integer for searching. Then it searches this query integer in the sorted array and returns the index of the query integer if it exists, or -1 if it doesn't exist. This function has O(log(n)) time complexity.
void freePQ(PQueue *pq);// this function frees all the allocated memories.
void printPQ(PQueue *pq); //this function prints the current sorted array.



/* initPQ()
 * Parameters: Takes an integer n that represents the size of the desired priority queue
 * Complexity: O(1)
 * Description: Returns an empty priority queue(a PQueue whose availableIdx = 0, arraySize = the input integer, and an integer array with length = parameter n)
 */
PQueue* initPQ(int n){
    PQueue *pq;
    if((pq=malloc(sizeof(PQueue)))==NULL) return NULL;
    int *array;
    if((array=malloc(n*sizeof(int)))==NULL) return NULL;
    pq->availableIdx=0;
    pq->arraySize=n;
    pq->sortedArray=array;
    return pq;
}
/* insertPQ()
 * Parameters: Takes a priority queue pointer(PQueue*), and an integer n which represents the value of the new value to be inserted into queue
 * Complexity: O(n)
 * Description: Inserts the new integer n into the sorted array in ascending order. Returns 0 if insertion was successful, returns -1 if insertion failed
 */
int insertPQ(PQueue *pq, int n){
    if(pq==NULL) return -1;
    int i=0, j;
    while(n>*(pq->sortedArray+i)) i++; //Step 1: find point in sorted array where n < next value
    j=pq->availableIdx-i;
    while(j!=i){ //Step 2: move every value over by one to make space for new value n
        if((i+j-1)<0) break;
        *(pq->sortedArray+(i+j-1))=(*(pq->sortedArray+(i+j-2))); //(i+j=total size of array so i+j-1= last index)
        j--;
    }
    *(pq->sortedArray+i)=n; //Step 3: insert new value into location

    pq->availableIdx++;
    return 0;
}
/* DeQueue()
 * Parameters: Takes a priority queue pointer(PQueue*), and an integer pointer n
 * Complexity: O(1)
 * Description: Removes largest item in queue and places its value in integer pointer n
 */
int DeQueue(PQueue *pq, int *n){
    if(pq==NULL) return -1;
    if(pq->sortedArray==NULL) return -1;
    *n=(*(pq->sortedArray+pq->availableIdx));
    (*(pq->sortedArray+pq->availableIdx))=0;
    return 0;
}
/* findIdx()
 * Parameters: Takes a priority queue pointer(PQueue*), and an integer n
 * Complexity: O(log(n))
 * Description: Searches priority queue for value equal to n. Returns index of said value if it exists, returns -1 if it does not exist in the queue
 */
int findIdx(PQueue *pq, int n){
    int mid=pq->arraySize/2;
    if(*(pq->sortedArray+mid)==n) return mid;
    if(*(pq->sortedArray+mid)>n) return findIdx(pq, n);
    if(*(pq->sortedArray+mid+1)<n)return findIdx(pq, n+mid);
    return 0;
}
/* freePQ()
 * Parameters: Takes a priority queue pointer(PQueue*)
 * Complexity: O(1)
 * Description: Frees all memory used by a priority queue
 */
void freePQ(PQueue *pq){
    free(pq->sortedArray);
    free(pq);
}
/* printPQ()
 * Parameters: Takes a priority queue pointer(PQueue*)
 * Complexity: O(n)
 * Description: Prints a priority queue
 */
void printPQ(PQueue *pq){
    for(int i=0; i<pq->availableIdx; i++) printf("PQ[%d]: %d\n", i, *(pq->sortedArray+i));
}