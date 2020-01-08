//Need to link lab12.c with lab12.h! "" for in same directory, <> for in OS's default library location
#include "lab12.h"
// you do not need to #include <stdlib.h> etc because it's already included in the .h file.
/* This function initializes a PQueue struct with the availableIdx = 0 and create an int array with length = size*/
PQueue* initPQ(int size){

    PQueue* PQ = malloc(sizeof(PQueue));
    if (PQ == NULL){
        return NULL;
    }

    PQ->arraySize = size;
    PQ->availableIdx = 0;
    PQ->sortedArray = malloc(sizeof(int)*size);
    if (PQ->sortedArray == NULL){
        free(PQ);
        PQ = NULL;
        return NULL;
    }

    return PQ;
}

/* this function receives the current priority queue and a new integer value, then inserts the new integer into queue in ascending order. It returns an error code: 0 if the insertion was successful, -1 if the insertion failed*/
int insertPQ(PQueue* PQ, int key){
    if (PQ->availableIdx == PQ->arraySize){ // no available space
        return -1;
    } else {

        if (key >= PQ->sortedArray[PQ->availableIdx-1]){
            // already larger than the last one
            PQ->sortedArray[PQ->availableIdx] = key;
        } else {
            int index = 0; // ths index to insert
            if (key <= PQ->sortedArray[0]){
                // smaller than the first one
                index = 0;
            } else {
                for (int i = 1; i < PQ->availableIdx; i++){
                    if (key >= PQ->sortedArray[i-1] && key <= PQ->sortedArray[i]){
                        index = i;
                        break;
                    }
                }
            }

            for (int i = PQ->availableIdx; i > index; i--){
                PQ->sortedArray[i] = PQ->sortedArray[i-1];
            }
            PQ->sortedArray[index] = key;
        }

        PQ->availableIdx ++;
        return 0;
    }
}

/* this function receives the current priority queue and an integer pointer. It removes the maximum integer from the queue, stores the removed value into the integer pointer, then returns an error code: 0 if the deletion was successful, -1 if the deletion failed. This function has O(1) time complexity.*/
int DeQueue(PQueue* PQ, int* removedValuePtr){
    if (PQ->availableIdx == 0){
        return -1;
    } else {
        *removedValuePtr = PQ->sortedArray[PQ->availableIdx-1];
        PQ->availableIdx --;
        return 0;
    }
}

/* this function receives the current priority queue and an query integer. Then it applies binary search on array and returns the index of the query value if the query exists, or -1 if the query doesn't exist. This function has O(log(n)) time complexity.*/
int findIdx(PQueue* PQ, int query){
    return binarySearch(PQ->sortedArray, 0, PQ->availableIdx-1, query);
}

/* this function performs binary search on the given array*/
int binarySearch(int* arr, int left, int right, int query){
    if (right >= left){
        int mid = left + (right - left) / 2;
        if (arr[mid] == query){
            return mid;
        } else if (arr[mid] > query){
            return binarySearch(arr, left, mid - 1, query);
        } else {
            return binarySearch(arr, mid + 1, right, query);
        }
    } else {
        return -1;
    }
}

/* this function frees all the allocated memories.*/
void freePQ(PQueue* PQ){
    free (PQ->sortedArray);
    PQ->sortedArray = NULL;

    free (PQ);
    PQ = NULL;
}

/*this function prints the current prioiry queue.*/
void printPQ(PQueue* PQ){
    if (PQ->availableIdx == 0){
        printf("PQ is empty.\n");
    } else {
        printf("PQ is: ");
        for (int i = 0; i < PQ->availableIdx; i++){
            printf("%d ",PQ->sortedArray[i]);
        }
        printf("\n");
    }
}