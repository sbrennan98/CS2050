#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList{ //MUST DECLARE STRUCT TYPEDEF LIKE THIS BECAUSE IT'S SELF-REFERENTIAL
    int i;
    struct linkedList *next;
} List;

//NO DUMMY NODES IN THIS VERSION
List* initIntegerList();
void insertAtHead(List **list, int value); //Need to pass ** so the value of the head can be changed. //ADD ERROR CHECKS FOR MALLOC!!!
void insertAtTail(List *list, int value);
void freeList(List *list);
void printList(List *list);
int getInt();

int main(void){
    List *list=initIntegerList();
    insertAtHead(&list, getInt());
    insertAtHead(&list, getInt());
    insertAtHead(&list, getInt());
    insertAtTail(list, getInt());
    printList(list);
}
List* initIntegerList(){
    return NULL;
}
void insertAtHead(List **list, int value){ //** used so the original can be modified
    List *new=malloc(sizeof(List));
    new->i=value;
    new->next=*list;
    *list=new;
} //ADD ERROR CHECKS FOR MALLOC!!!
void insertAtTail(List *list, int value){
    List *new=malloc(sizeof(List));
    new->i=value;
    while(list->next!=NULL){ //scan through linked list and find last node
        list=list->next;
    }
    new->next=list->next;
    list->next=new;
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
    while(list->next!=NULL){
        printf("%d, ", list->i);
        list=list->next;
    }
    printf("%d.\n", list->i);
}
int getInt(){
    int i;
    printf("Enter an integer:\n");
    scanf("%d", &i);
    return i;
}