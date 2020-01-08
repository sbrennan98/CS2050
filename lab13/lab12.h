# include <stdio.h>
# include <stdlib.h>
# include <time.h>
typedef struct {
    int arraySize;
    int availableIdx;
    int *sortedArray;
} PQueue;

PQueue* initPQ(int);
int insertPQ(PQueue*, int);
int DeQueue(PQueue*, int*);
int findIdx(PQueue*, int);
int binarySearch(int*, int, int, int);
void freePQ(PQueue*);
void printPQ(PQueue*);