/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_14          *
 *Date:     11/19/2019      *
 ****************************/
#include "lab14.h"

/* initTree()
 * Parameters: Takes an integer n that represents the value to be stored in the treeNode
 * Complexity: O(1)
 * Description: Returns a root with initialized value given by parameter n
 */
treeNode* initTree(int n){
    treeNode *root;
    if((root=malloc(sizeof(treeNode)))==NULL) return NULL;
    root->data=n;
    root->left=NULL;
    root->right=NULL;
    return root;
}
/* insertBT()
 * Parameters: Takes a treeNode ptr t, and an integer n
 * Complexity: O(log(n))
 * Description: Returns a root with initialized value given by parameter n, returns NULL if given a NULL treeNode
 */
treeNode* insertBT(treeNode* t, int n){
    if(t==NULL) return NULL; //given a null treeNode
    if(coinFlip()==1){
        if(t->right!=NULL) insertBT(t->right, n);
        else t->right=initTree(n);
    }
    else{
        if(t->left!=NULL) insertBT(t->left, n);
        else t->left=initTree(n);
    }
    return t;
}
/* countEvenKey()
 * Parameters: Takes a treeNode ptr t, and an int ptr n
 * Complexity: O(log(n))
 * Description: Counts the number of even integers stored in a treeNode ptr t, and places that number in int ptr n
 */
void countEvenKey(treeNode* t, int *n){ //incomplete
    if(t==NULL) return;
    
    countEvenKey(t->left, n);
    if((t->data%2)==0) *n+=1;
    countEvenKey(t->right, n);
}
/* coinFlip()
 * Parameters: VOID
 * Complexity: O(1)
 * Description: 50/50 chance of returning either 0 or 1
 */
int coinFlip(){
    return (rand()%2);
}
/* randInt()
 * Parameters: VOID
 * Complexity: O(1)
 * Description: Returns a random integer between numbers 0 & 1000
 */
int randInt(){
    return (rand()%1001);
}
/* printBT()
 * Parameters: Takes a treeNode ptr t
 * Complexity: O(n)
 * Description: Recursively prints every value in a binary tree in order from left to right
 */
void printBT(treeNode* t){
    if(t==NULL) return;
    printBT(t->left);
    printf("%d\n", t->data);
    printBT(t->right);
}
/* freeTree()
 * Parameters: Takes a treeNode ptr t
 * Complexity: O(n)
 * Description: Recursively loops through binary tree and frees the memory
 */
void freeTree(treeNode* t){
    if(t==NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}