#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define MIN 1
typedef struct nodestruct{
    int item;
    struct nodestruct *next;
} Node;

Node* initIntegerList();
int insertAtHead(Node *list, int value);
void freeList(Node *list);
void printList(Node *list);
int insertAscend(Node *list, int value); //insert into list in ascending order ERROR
int computeSum(Node *list);
int randInt();

int main(void){
    srand(time(NULL));
    //Create an empty linked list and print out the current linked list
    Node *list=initIntegerList();
    printList(list);
    computeSum(list);
    //Insert five random integers with value between 1 and 10 into the linked list using insertAscend(). After each insertion, print out the current linked list, and the current sum value.
    if(insertAscend(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAscend(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAscend(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAscend(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAscend(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    //Insert another five random integers with values between 1 and 10 into the linked list using insertAtHead(). After each insertion print out the current linked list, and the current sum value.
    if(insertAtHead(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAtHead(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAtHead(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAtHead(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    if(insertAtHead(list, randInt())==-1) printf("Error\n");
    printList(list);
    if(computeSum(list)==-1) printf("Error\n");
    //Free your linked list by using freeList() function
    freeList(list);
    printf("Linked list has been freed.\n");
}
/*initIntegerList(): VOID
 *  -Returns a linked list containing two dummy nodes, with the last dummy node set to zero.
 */
Node* initIntegerList(){
    //make two dummy nodes
    Node *node1, *node2;
    if(((node1=malloc(sizeof(Node)))==NULL) || ((node2=malloc(sizeof(Node)))==NULL)){ //Error check
        printf("Failed to initialize integer list.\n");
        return NULL;
    }
    node2->next=NULL; //set last dummy node equal to null
    node1->next=node2;//dummy node1 points to dummy node2 initially
    return node1;
}
/*insertAtHead(): Takes a linked list(pointer to the first dummy node of a linked list), and a value of the new node.
    -Creates a new Node and inserts it at the head of a given linked list. Returns -1 if malloc fails.
 */
int insertAtHead(Node *list, int value){
    printf("Head insertion: ");
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //make a new List node (with pointers as it must exist outside of this function)
    new->item=value; //set the value of the node
    new->next=list->next; //set new node to point to the previously first node (after dummy)
    list->next=new;
    return 0;
}
/*freeList(): Takes a linked list(pointer to the first dummy node of a linked list)
 *  -Frees all memory allocated in a linked list that contains dummy nodes.
 */
void freeList(Node *list){
    Node *temp;
    while(list->next!=NULL){
        temp=list->next;
        free(list);
        list=temp;
    }
    free(list);
}
/*printList(): Takes a linked list(pointer to the first dummy node of a linked list)
 *  -Prints every value of a linked list that contains dummy nodes
 */
void printList(Node *list){
    Node *loop=list->next; //skip dummy node
    if(loop->next==NULL){  //check to see if list is empty first
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while(loop->next!=NULL){ //stops before last dummy node
        printf("%d, ", loop->item);
        loop=loop->next;
    }
    printf("\n");
}
/*insertAscend(): Takes a linked list(pointer to the first dummy node of a linked list), and a value of a new Node
 *  -Inserts a given node in a linked list in ascending order. Returns -1 if malloc failed.
 */
int insertAscend(Node *list, int value){
    printf("Ascending insertion: ");
    Node *new;
    if((new=malloc(sizeof(Node)))==NULL) return -1; //error check
    new->item=value;//create new Node to be inserted
    Node *loop=list;
    while((loop->next->item<value)){ //find location to insert new Node
        if(loop->next->next==NULL){ //check if value is greater than whole list
            break;
        }
        loop=loop->next;
    }
    new->next=loop->next; //insert
    loop->next=new;
    return 0;
}
/*computeSum(): Takes a linked list(pointer to the first dummy node of a linked list)
 *  -Returns the sum of every node in a linked list.
 */
int computeSum(Node *list){
    int i=0;
    Node *loop=list->next; //skip dummy node
    if(loop->next==NULL) printf("Sum is 0.\n"); //check to see of list is empty first
    while(loop->next!=NULL){ //stops before last dummy node
        i+=loop->item;
        loop=loop->next;
    }
    return i;
}
/*randInt(): VOID
 *  -Returns a random integer number between the numbers MAX and MIN.
 */
int randInt(){
    return (rand()%(MAX-MIN+1)+MIN);
}