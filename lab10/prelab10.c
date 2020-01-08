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
int dequeue(Queue *queue, int *n); //places key of dequeued item in space given by ptr passed
int getQsize(Queue *queue);//Returns # of items in queue
void freeQueue(Queue *queue);//Free *all* space

int main(void){
    int n;
    Queue *queue;
    if((queue=initQueue())==NULL) return -1; //error check for malloc
    printf("Queue size: %d\n", getQsize(queue));
    enqueue(10, queue);
    enqueue(20, queue);
    enqueue(30, queue);
    enqueue(40, queue);
    enqueue(50, queue);
    printf("Queue size: %d\n", getQsize(queue));
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    printf("Queue size: %d\n", getQsize(queue));

    freeQueue(queue);
}
Queue* initQueue(){
    Queue *queue;
    if((queue=malloc(sizeof(Queue)))==NULL) return NULL; //Error check for malloc
    queue->size=0;
    queue->rear=NULL; //might have to change later if adding dummy node(s)
    queue->front=NULL;
    return queue;
}
int enqueue(int n, Queue *queue){
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //Error check for malloc
    new->info=n; //set the value in the new Node.
    if(queue->front==NULL){ //check to see if queue is empty.
        new->next=new;
        queue->rear=new;
        queue->front=new;
        queue->size++;
        return 0;
    }
    new->next=queue->rear->next; //set the new Node to point to the previously newest Node.
    queue->rear->next=new; //set previous rear of queue to point to newly queued Node.
    queue->rear=new; //set rear of queue to newly queued Node.
    queue->size++;
    return 0;
}
int dequeue(Queue *queue, int *n){ //buggy
    if(queue->front==NULL) return -1; //error check if given an empty queue
    *n=queue->front->info;
    if(queue->front->next==queue->front){
        free(queue->front);
        queue->front=NULL;
        queue->rear=NULL;
        queue->size=0;
        return 0;
    }
    Node *temp=queue->front;
    queue->front=queue->front->next; //advance to the next in queue
    free(temp);
    queue->size--;
    return 0;
}
int getQsize(Queue *queue){
    return queue->size;
}
void freeQueue(Queue *queue){ //seg fault
    if(queue->front==NULL || queue==NULL) return;
    Node *temp;
    while(queue->front!=queue->rear){
        temp=queue->front;
        queue->front=queue->front->next;
        free(temp);
    }
/*  while(queue->front!=queue->front->next){
        temp=queue->front;
        queue->front=queue->front->next;
        free(temp);
    } why does this segfault but the one above doesn't?
*/
    free(queue->front);
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
}