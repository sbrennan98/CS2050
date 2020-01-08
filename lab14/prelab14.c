/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Prelab_14       *
 *Date:     11/13/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct nodestruct{
    int key;
    struct nodestruct *left, *right, *dupe;
} tree;
//Function Prototypes
tree* initTree();
int insertRandom(tree* t);
int getHeight(tree* t);
int countNodes(tree* t);
int coinFlip();
int randInt();
void printTree(tree* t);

int main(void){
    srand(time(NULL));

    tree *t=initTree();
    for(int i=0; i<10000000; i++) insertRandom(t);

    //printTree(t);
    printf("\n%d\n", getHeight(t));
    printf("%d\n", countNodes(t));


    return 0;
}
tree* initTree(){
    tree *root;
    if((root=malloc(sizeof(tree)))==NULL) return NULL;
    root->key=randInt();
    root->left=NULL;
    root->right=NULL;
    root->dupe=NULL;
    return root;
}
int insertRandom(tree* t){
    if(t==NULL) return -1; //given a null tree
    if(coinFlip()==1){
        if(t->right!=NULL) insertRandom(t->right);
        else t->right=initTree();
    }
    else{
        if(t->left!=NULL) insertRandom(t->left);
        else t->left=initTree();
    }
    return 0;
}
int getHeight(tree* t){
    if(t==NULL) return -1; // given a null tree
    int leftHeight=getHeight(t->left);
    int rightHeight=getHeight(t->right);
    if(leftHeight>=rightHeight){
        return leftHeight+1;
    }
    return rightHeight+1;
}
int countNodes(tree *t){
    if(t==NULL) return 0;
    int leftSize=countNodes(t->left);
    int rightSize=countNodes(t->right);
    return (leftSize+rightSize+1);
}
int coinFlip(){
    return (rand()%2);
}
int randInt(){
    return (rand()%1001);
}
void printTree(tree* t){
    if(t==NULL) return;
    printTree(t->left);
    printf("%d\n", t->key);
    printTree(t->right);
}
void freeTree(tree* t){
    if(t==NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}