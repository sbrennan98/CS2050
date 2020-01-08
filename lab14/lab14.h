/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_14          *
 *Date:     11/19/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node{
    int data;
    struct node *left, *right;
} treeNode;
//Function Prototypes
treeNode* initTree(int);
treeNode* insertBT(treeNode*, int);
int coinFlip();
int randInt();
void printBT(treeNode*);
void freeTree(treeNode*);
void countEvenKey(treeNode*, int *);