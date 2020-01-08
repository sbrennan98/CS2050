/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_10          *
 *Date:     10/22/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 10
typedef struct nodestruct {
    int item;
    struct nodestruct *next;
} Node;
typedef struct {
    int size, sum;
    Node *rear;
} Queue;
//Function Prototypes
Queue* initQueue();
int enqueue(int n, Queue *queue);
int dequeue(Queue *queue, int *n);
void freeQueue(Queue *queue);
int getSum(Queue *queue);
int randInt();

/*
//Uncomment if you want to test.
int main(void){
    srand(time(NULL));
    int n;
    Queue *queue;
    if((queue=initQueue())==NULL) return -1; //error check for malloc
    printf("Queue sum: %d\n", getSum(queue));
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    enqueue(randInt(), queue);
    printf("Queue sum: %d\n", getSum(queue));
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    dequeue(queue, &n);
    printf("Dequeued info: %d\n", n);
    printf("Queue sum: %d\n", getSum(queue));

    freeQueue(queue);
}
*/

/* initQueue():
 * Parameters: NULL
 * Complexity: O(1)
 * Description: Returns an empty queue(queue whose size, sum, and rear values have been initialized to NULL/0). 
 */
Queue* initQueue(){
    Queue *queue;
    if((queue=malloc(sizeof(Queue)))==NULL) return NULL; //Error check for malloc
    queue->size=0;
    queue->sum=0;
    queue->rear=NULL;
    return queue;
}
/* enqueue():
 * Parameters: Takes an integer(must be between 1 and 10), and a Queue ptr (Queue *queue)
 * Complexity: O(1)
 * Description: Add a new node(whose value must be between 1 and 10) to a circular linked list as defined above. Returns -1 if malloc failed, -2 if given values less than 1 or greater than 10, and 0 if all good. 
 */
int enqueue(int n, Queue *queue){
    if(n<1 || n>10) return -2; //by the given constraints of lab10, the integers must be between 1 and 10.
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //Error check for malloc
    new->item=n; //set the value in the new Node.
    if(queue->rear==NULL){ //check to see if queue is empty.
        new->next=new;
        queue->rear=new;
        queue->size++;
        queue->sum=new->item;
        return 0;
    }
    new->next=queue->rear->next; //set the new Node to point to the previously newest Node.
    queue->rear->next=new; //set previous rear of queue to point to newly queued Node.
    queue->rear=new; //set rear of queue to newly queued Node.
    queue->size++;
    queue->sum+=new->item;
    return 0;
}
/* dequeue():
 * Parameters: Takes a Queue ptr (Queue *queue), and an integer ptr (int *n)
 * Complexity: O(1)
 * Description: Removes frontmost Node from a given Queue as defined above, places key of dequeued item in space given by ptr passed, and then frees its memory. Returns -1 if given an empty list that cannot be dequeued, 0 if all good. 
 */
int dequeue(Queue *queue, int *n){
    if(queue->rear==NULL) return -1; //error check if given an empty queue
    *n=queue->rear->next->item; //set the value of the integer ptr we were given to the value dequeued Node
    if(queue->rear->next==queue->rear){ //check if down to only one node
        free(queue->rear);
        queue->rear=NULL;
        queue->size=0;
        queue->sum=0;
        return 0;
    }
    Node *temp=queue->rear->next; //make temp node ptr that's set to the front of queue
    queue->rear->next=queue->rear->next->next; //advance to the next in queue
    queue->sum-=temp->item;
    free(temp); //free front
    queue->size--;
    return 0;
}
/* freeQueue():
 * Parameters: Takes a Queue ptr (Queue *queue)
 * Complexity: O(n)
 * Description: Frees all memory in a circular linked list as defined above. 
 */
void freeQueue(Queue *queue){
    if(queue->rear==NULL || queue==NULL) return;
    Node *temp;
    while(queue->rear->next!=queue->rear){
        temp=queue->rear->next; //temp equal front of queue
        queue->rear->next=queue->rear->next->next; //skip over temp
        free(temp);
    }
    free(queue->rear);
    queue->rear=NULL;
    queue->size=0;
    queue->sum=0;
}
/* getSum():
 * Parameters: Takes a Queue ptr (Queue *queue)
 * Complexity: O(1)
 * Description: Returns the sum of all the values in a circular linked list as defined above. 
 */
int getSum(Queue *queue){
    return queue->sum;
}
/* randInt():
 * Parameters: NULL
 * Complexity: O(1)
 * Description: Returns a random integer between the values MIN and MAX.
 */
int randInt(){
    return (rand()%(MAX-MIN+1)+MIN);
}