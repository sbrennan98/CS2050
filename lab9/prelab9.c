#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList{
    int item;
    struct linkedList *head, *tail, *next;
} Node;

//ADD ERROR CHECKS FOR MALLOC! ALL FUNCTIONS NEED TO BE O(1)
Node* initIntegerList(); //Return empty list
int insertAtHead(int value, Node *list); //Insert k at head
int insertAtTail(int value, Node *list); //Insert k at tail
void freeList(Node *list); //Use removeHead to free the entire list
int removeHead(Node *list); //Remove head and return its key
int getListSize(Node *list); //Return number of elements in list
void printHead(Node *list); //Print the key stored in head
void moveHeadToTail(Node *list); //Move key at head to tail

int main(void){
    Node *list;
    if((list=initIntegerList())==NULL) return -1;
    printf("List size: %d\n", getListSize(list));
    insertAtTail(20, list);
    insertAtTail(10, list);
    insertAtHead(30, list);
    printHead(list);
    printf("List size: %d\n", getListSize(list));
    printf("Removed key: %d\n", removeHead(list));
    printf("List size: %d\n", getListSize(list));
    printHead(list);
    insertAtHead(30, list);
    printHead(list);
    moveHeadToTail(list);
    printHead(list);
    printf("%d\n", list->tail->item);
    
    //freeList(list);
}
Node* initIntegerList(){
    Node *node1, *node2;
    if(((node1=malloc(sizeof(Node)))==NULL) || ((node2=malloc(sizeof(Node)))==NULL)){ //Error check
        printf("Failed to initialize integer list.\n");
        return NULL;
    }
    node2->next=NULL; //set last dummy node equal to null
    node1->next=node2;//dummy node1 points to dummy node2 initially
    node1->item=0;//initialize dummy node's int value to 0
    node1->head=node1;
    node1->tail=node1;//tail value needs to point to the node before the last dummy node
    return node1;
}
int insertAtHead(int value, Node *list){
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //make a new List node (with pointers as it must exist outside of this function)
    list->item+=1; //increase stored list size in dummy node
    new->item=value; //set the value of the node
    new->next=list->next; //set new node to point to the previously first node (after dummy)
    list->next=new;
    list->head=new;
    return 0;
}
int insertAtTail(int value, Node *list){
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //make a new List node (with pointers as it must exist outside of this function)
    new->item=value;
    list->item+=1;//increase stored list size in dummy node

    new->next=list->tail->next;//set the next value in new to the next value of the tail(dummy node)
    list->tail->next=new;//set the next value of the previous tail to the new node
    list->tail=new;//set the new tail to new
    return 0;
}
void freeList(Node *list){ // Not O(1) but also not a function in the prelab requirements so w/e
    Node *temp=list;
    while(list->next!=NULL){
        if(list->item==0){
            free(list->next);
            break;
        }
        removeHead(list);
    }
    free(list);
}
int removeHead(Node *list){
    if(list->item==0){ //list is empty
        printf("*!ERROR! List is empty, cannot remove head*\n");
        return -1;
    }
    int i;
    Node *temp;
    temp=list->next; //skip dummy node
    i=temp->item;
    list->next=list->next->next; //skip head
    free(temp); //free head
    list->item-=1; // reduce list size
    return i;
}
int getListSize(Node *list){
    return list->item;
}
void printHead(Node *list){ //prints garbage if list is empty.
    printf("%d\n", list->next->item);
}
void moveHeadToTail(Node *list){
    Node *temp;
    temp=list->next;//set temp equal to head
    list->next=list->next->next;//set new head as the node after old head
    temp->next=list->tail->next;//set head->next equal to tail dummy node
    list->tail->next=temp;//set tail->next equal to the new tail
    list->tail=temp;//set the tail ptr in head dummy node to new tail
}