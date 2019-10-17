#include <stdio.h>
#include <stdlib.h>
typedef struct nodestruct{
    int info;
    struct nodestruct *next;
} Node;
typedef struct{
    int size;
    Node *front, *rear;
} Queue;
//All functions must take O(1) except freeQueue()
Queue* initQueue();//Return empty queue
int enqueue(int n, Queue *queue);//enqueue and dequeue each return an int error code
int dequeue(Queue *queue, int *n);
int getQsize(Queue *queue);//Returns # of items in queue
void freeQueue(Queue *queue);//Free *all* space

int main(void){

}
Queue* initQueue(){
    Queue *queue;
    if((queue=malloc(sizeof(Queue))==NULL)) return NULL;
    queue->size=0;
    queue->rear=NULL; //might have to change later if adding dummy node(s)
    return queue;
}
int enqueue(int n, Queue *queue){

}
int dequeue(Queue *queue, int *n){ //error check if given an empty queue

}
int getQsize(Queue *queue){
    return queue->size;
}
void freeQueue(Queue *queue){ //will take O(n)
    Node *temp;
    queue->size=0;
    temp=queue->front;
    while(temp!=NULL){
        
    }
}