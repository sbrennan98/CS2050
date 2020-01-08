/***INCOMPLETE***/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float num;
} Node;
typedef struct{
    int size, totalsize;
    Node *list;
} PQueue;

PQueue *initPQ(int size);
int insertPQ(float f, PQueue *pq);
int deleteMaxPQ(PQueue *pq, float *f);
int getSizePQ(PQueue *pq);
int isInPQ(float f, PQueue *pq); //O(log(n))
void freePQ(PQueue *pq);
void printPQ(PQueue *pq);

int main(void){
    PQueue *pq=initPQ(10);
    insertPQ(6.9, pq);
    insertPQ(420.69, pq);
    insertPQ(4.2, pq);
    insertPQ(69.69, pq);
    insertPQ(10.1, pq);
    insertPQ(0.69, pq);
    insertPQ(420.42, pq);
    insertPQ(0.42, pq);
    insertPQ(96.69, pq);
    insertPQ(69.96, pq);
    printPQ(pq);

}
PQueue *initPQ(int size){
    Node *array;
    if((array=malloc(size*sizeof(Node)))==NULL) return NULL;
    PQueue *pq;
    if((pq=malloc(sizeof(PQueue)))==NULL) return NULL;
    pq->size=0;
    pq->totalsize=size;
    pq->list=array;
    return pq;
}
int insertPQ(float f, PQueue *pq){ //inserted in descending order
    if(pq==NULL) return -1;
    int i=0, j;
    while(f<(((pq->list)+i)->num)) i++; //step 1
    j=pq->size-i; //j= number of elements to move over by one to make space for new value
    while(j!=0){ //step 2
        (((pq->list)+i+j)->num)=(((pq->list)+i+(j-1))->num);
        j--;
    }
    (((pq->list)+i)->num)=f; //step 3
    pq->size++;
    return 0;
}
int deleteMaxPQ(PQueue *pq, float *f){
    //pq->size--;
    return 0;
}
int getSizePQ(PQueue *pq){
    return pq->size;
}
int isInPQ(float f, PQueue *pq){
    int i=pq->size/2;
    while(i>1){
        if((pq->list+i)->num==f) return 1;
        if((pq->list+i)->num<f){ //lefthand side

        }
        if((pq->list+(i+1))->num>f){ //righthand side

        }
    }
    return 0;
}
void freePQ(PQueue *pq){

}
void printPQ(PQueue *pq){
    for(int i=0; i<pq->size; i++) printf("PQ[%d]: %.3f\n", i, ((pq->list)+i)->num);
}
/****INCOMPLETE****/