/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_11          *
 *Date:     10/29/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
typedef struct nodestruct{
    int key;
    float priority;
    struct nodestruct *next;
} Node;
typedef struct{
    int size;
    Node *front, *rear;
} PQueue;
//Function Prototypes
PQueue* initPQ();
int insertPQ(int n, float f, PQueue *queue); //O(n). In Ascending order as in starts from the lowest value ends with the highest.
int deleteMinPQ(PQueue *queue, int *n); //O(1)
void reInitPQ(PQueue *queue);
void freePQ(PQueue *queue);
void printPQ(PQueue *queue);


int main(void){
    int n;
    PQueue *applicants=initPQ();

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
        deleteMinPQ(applicants, &n);
    }
    printPQ(applicants);

    freePQ(applicants);
}



/* initPQ():
 * Parameters: NULL
 * Complexity: O(1)
 * Description: Returns an empty priority queue(size, front, and rear values have been initialized to NULL/0). 
 */
PQueue* initPQ(){
    PQueue *queue;
    if((queue=malloc(sizeof(PQueue)))==NULL) return NULL; //Error check for malloc
    queue->size=0;
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}
/* insertPQ():
 * Parameters: Takes an integer to be the key of the new node, a float to be the priority of the new node, and a PQueue ptr (PQueue *queue)
 * Complexity: O(n)
 * Description: Inserts a new node into a priority queue in ascending order. Returns -1 if malloc fails, and 0 if all good 
 */
int insertPQ(int n, float f, PQueue *queue){ //convert to ascending
    Node *new, *temp=queue->front;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //error check for malloc
    new->key=n;
    new->priority=f;
    if(temp==NULL){ //check to see if empty
        queue->front=new;
        queue->rear=new;
        new->next=NULL;
        queue->size++;
        return 0;
    }
    if(new->priority<temp->priority){ //check to see if the first node is bigger in the first place
        new->next=temp;
        queue->front=new;
        queue->rear=new->next;
        queue->size++;
        return 0;
    }
    if(temp->next==NULL){ //check to see if temp->next actually exists or if the list is down to one Node
        if(new->priority>temp->priority){
            temp->next=new;
            new->next=NULL;
            queue->rear=new;
            queue->size++;
            return 0;
        }
        new->next=temp;
        queue->size++;
        return 0;
    }
    while(new->priority>=temp->next->priority){ //find correct order in queue. Stop searching when the next Node's priority is greater than that of the new Node.
        if(temp->next->next==NULL){ //check to see if new node is of greater priority than any other node in the list
            new->next=NULL;
            temp->next->next=new;
            queue->rear=new;
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
/* deleteMinPQ():
 * Parameters: Takes a PQueue ptr (PQueue *queue), and a pointer to an integer
 * Complexity: O(1)
 * Description: Deletes the smallest priority Node in a priority queue that is sorted in ascending order. Returns -1 if malloc fails, and 0 if all good 
 */
int deleteMinPQ(PQueue *queue, int *n){
    if(queue->front==NULL) return -1;
    Node *temp=queue->front;
    queue->front=queue->front->next;
    free(temp);
    queue->size--;
    return 0;
}
/* reInitPQ():
 * Parameters: Takes a PQueue ptr (PQueue *queue)
 * Complexity: O(n)
 * Description: Frees all memory in a PQueue except the address of the PQueue itself and initializes everything back to NULL.
 */
void reInitPQ(PQueue *queue){
    int throwaway;
    while(queue->front->next!=NULL){
        deleteMinPQ(queue, &throwaway);
    }
    free(queue->front);
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
}
/* freePQ():
 * Parameters: Takes a PQueue ptr (PQueue *queue)
 * Complexity: O(n)
 * Description: Frees all memory in a PQueue including the address of the PQueue itself and initializes everything back to NULL.
 */
void freePQ(PQueue *queue){
    int throwaway;
    while(queue->front->next!=NULL){
        deleteMinPQ(queue, &throwaway);
    }
    free(queue->front);
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
    free(queue);
}
/* printPQ():
 * Parameters: Takes a PQueue ptr (PQueue *queue)
 * Complexity: O(n)
 * Description: Prints every node currently in queue in order.
 */
void printPQ(PQueue *queue){
    Node *temp=queue->front;
    while(temp!=NULL){
        printf("Key: %d Priority: %.2f ->", temp->key, temp->priority);
        temp=temp->next;
    }
}