/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_9           *
 *Date:     10/15/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 10
typedef struct nodestruct{
    int item;
    struct nodestruct *next;
} Node;
typedef struct{
    int size;
    Node *head, *tail;
} List;
//Function Prototypes
List* initIntegerList();
int insertAtHead(int n, List *list);
int removeTail(List *list);
void emptyList(List *list);
void freeList(List **list);
void printList(List *list);
int randInt();

int main(void){
    srand(time(NULL));
    //Create an empty linked list and print out the current linked list.
    List *list=initIntegerList();
    printList(list);
    //Insert five random integers into the list using insertAtHead(). After each insertion, print out the current linked list.
    for(int i=0; i<5; i++){
        if((insertAtHead(randInt(), list))==-1) printf("Malloc failed.\n");
        printf("\nHead insertion: ");
        printList(list);
    }
    //Remove nodes at tail twice using removeTail(). After each deletion, print out the current list.
    for(int i=0; i<2; i++){
        printf("\nRemoving tail: Item value: %d ", removeTail(list));
        printList(list);
    }
    //Empty the linked list by using emptyList()
    emptyList(list);
    //Insert another random int node at head then print the list
    insertAtHead(randInt(), list);
    printf("\nHead insertion: ");
    printList(list);
    printf("\n");
    //
    freeList(&list);
    printf("List has been freed.\n");
    return 0;
}
/*randInt(): VOID
 *  -Returns a random integer number between the numbers MAX and MIN.
 */
int randInt(){
    return (rand()%(MAX-MIN+1)+MIN);
}
/*initIntegerList(): VOID
 *  -Returns a linked list with the head pointing to NULL, tail pointing to NULL, and size set to zero.
 */
List* initIntegerList(){
    List *list;
    if((list=malloc(sizeof(List)))==NULL) return NULL; //make list and error check
    list->head=NULL;
    list->size=0;
    list->tail=NULL;
    return list;
}
/*insertAtHead(): Takes a value of the new node, and a List pointer.
    -Creates a new Node and inserts it at the head of a given linked list. Returns -1 if malloc fails.
 */
int insertAtHead(int n, List *list){
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //malloc space so it exists outside of function & error check
    new->item=n; //finish making new Node
    if(list->head==NULL){ //check to see if the list is empty
        new->next=NULL; //set next ptr equal to null and initialize the list values
        list->size=1;
        list->head=new;
        list->tail=new;
        return 0;
    }
    new->next=list->head; //set the next ptr to the previous head
    list->head=new; //set new head of list
    list->size+=1;
    return 0;
}
/*removeTail(): Takes a List pointer.
    -Removes the tail of a linked list, and returns the value stored in the removed node.
 */
int removeTail(List *list){
    Node *temp=list->head, *temp2;
    int n;
    while(temp->next->next!=NULL){ //find second to last node
        temp=temp->next;
    }
    n=temp->next->item;
    temp2=temp->next;
    temp->next=temp->next->next; // set second to last ptr equal to null
    free(temp2);
    list->tail=temp;
    list->size-=1;
    return n;
}
/*emptyList(): Takes a List pointer.
    -Removes all nodes of a linked list, setting head and tail to null, and size to 0.
 */
void emptyList(List *list){
    Node *temp=list->head, *temp2;
    while(temp!=NULL){
        temp2=temp->next;
        free(temp);
        temp=temp2;
    }
    list->head=NULL;
    list->size=0;
    list->tail=NULL;
}
/*freeList(): Takes a pointer to a List pointer.
    -Removes all nodes of a linked list, sets the list to NULL, then frees the list.
 */
void freeList(List **list){
    emptyList(*list);
    *list=NULL;
    free(*list);
}
/*printList(): Takes a List pointer.
 *  -Prints the value of every node in a linked list.
 */
void printList(List *list){
    if(list->head==NULL){
        printf("\nList is empty.\n");
        return;
    }
    printf("List is: ");
    Node *temp=list->head;
    while(temp!=NULL){
        printf("%d, ", temp->item);
        temp=temp->next;
    }
}