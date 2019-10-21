#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList{ //MUST DECLARE STRUCT TYPEDEF LIKE THIS BECAUSE IT'S SELF-REFERENTIAL
    int i;
    struct linkedList *next;
} List;

List* initIntegerList();
void insertAtHead(List *list, int value); //ADD ERROR CHECKS FOR MALLOC!!!
void insertAtTail(List *list, int value);
void freeList(List *list);
void printList(List *list);
int getInt();

int main(void){
    //ADD STUFF HERE TO TEST LOGIC
    List *list=initIntegerList(list);
    insertAtHead(list, getInt());
    insertAtHead(list, getInt());
    insertAtHead(list, getInt());
    insertAtTail(list, getInt());
    printList(list);
    freeList(list);
}
List* initIntegerList(){
    List *node1=malloc(sizeof(List)); //Make two dummy nodes
    List *node2=malloc(sizeof(List));
    node2->next=NULL; //set last dummy node equal to null
    node1->next=node2;
    return node1;
}
void insertAtHead(List *list, int value){
    List *new=malloc(sizeof(List)); //make a new List node (with pointers as it must exist outside of this function)
    new->i=value; //set the value of the node
    new->next=list->next; //set new node to point to the previously first node (after dummy)
    list->next=new;
}
void insertAtTail(List *list, int value){ //bug
    List *new=malloc(sizeof(List)); //make a new List node (with pointers as it must exist outside of this function)
    new->i=value;
    while(list->next->next!=NULL){ //find second to last node of list because dummy node exists
        list=list->next;
    }
    new->next=list->next; //set new node to point towards end dummy node
    list->next=new; //set old last node to point to new last node
}
void freeList(List *list){ //DON'T ACCESS ANY MEMORY THAT'S ALREADY BEEN FREED
    List *temp;
    while(list->next!=NULL){
        temp=list->next;
        free(list);
        list=temp;
    }
    free(list);
}
void printList(List *list){
    List *loop=list->next; //skip dummy node
    while(loop->next!=NULL){
        printf("%d, ", loop->i);
        loop=loop->next;
    }
}
int getInt(){
    int i;
    printf("Enter an integer:\n");
    scanf("%d", &i);
    return i;
}