#include <stdio.h>
#include <stdlib.h>
typedef struct nodestruct{
    int item;
    float priority;
    struct nodestruct *next;
} Node;
typedef struct{
    int size;
    Node *front;
} pQueue;

pQueue* initPQ();
int insertPQ(int n, float f, pQueue *queue); //O(n)
int deleteMaxPQ(pQueue *queue, int *n); //O(1)
int getSizePQ(pQueue *queue); //O(1)
void reInitPQ(pQueue *queue);
void freePQ(pQueue *queue);

int main(void){
    int n;
    pQueue *applicants=initPQ();
    //for sake of testing, will insert a sample of ten students into applicants queue & only eight will be accepted
    insertPQ(1, 4.0, applicants);
    insertPQ(2, 2.5, applicants);
    insertPQ(3, 2.8, applicants);
    insertPQ(4, 2.2, applicants);
    insertPQ(5, 1.0, applicants);
    insertPQ(6, 3.7, applicants);
    insertPQ(7, 3.2, applicants);
    insertPQ(8, 3.4, applicants);
    insertPQ(9, 3.9, applicants);
    insertPQ(10, 2.5, applicants);
    for(int i=0; i<8; i++){
        deleteMaxPQ(applicants, &n);
    }
    printf("%f\n", applicants->front->priority);
    printf("%f\n", applicants->front->next->priority);

}
pQueue* initPQ(){
    pQueue *queue;
    if((queue=malloc(sizeof(pQueue)))==NULL) return NULL; //Error check for malloc
    queue->size=0;
    queue->front=NULL;
    return queue;
}
int insertPQ(int n, float f, pQueue *queue){
    Node *new, *temp=queue->front;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //error check for malloc
    new->item=n;
    new->priority=f;

    if(temp==NULL){ //check to see if empty
        queue->front=new;
        new->next=NULL;
        queue->size++;
        return 0;
    }
    if(temp->next==NULL){ //check to see if temp->next actually exists or if the list is down to one Node
        if(new->priority<temp->priority){
            temp->next=new;
            new->next=NULL;
            queue->size++;
            return 0;
        }
        new->next=temp;
        queue->size++;
        return 0;
    }
    if(new->priority>temp->priority){
        new->next=temp;
        queue->front=new;
        queue->size++;
        return 0;
    }
    while(new->priority<=temp->next->priority){ //find correct order in queue. Stop searching when the next Node's priority is less than that of the new Node.
        if(temp->next->next==NULL){
            new->next=NULL;
            temp->next->next=new;
            queue->size++;
            return 0;
        }
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    queue->size++;

    return 0;
}
int deleteMaxPQ(pQueue *queue, int *n){
    if(queue->front==NULL) return -1;
    Node *temp=queue->front;
    queue->front=queue->front->next;
    free(temp);
    queue->size--;
    return 0;
}
int getSizePQ(pQueue *queue){
    return queue->size;
}
void reInitPQ(pQueue *queue){

}
void freePQ(pQueue *queue){

}