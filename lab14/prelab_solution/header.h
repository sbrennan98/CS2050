# include <stdio.h>
# include <stdlib.h>

typedef struct tree {
	int value;
	struct tree *less, *greater;
} Tree;

void insertRandom(Tree*);
Tree* initTree(); 
void freeTree(Tree*);
int getHeight(Tree*);
void printTree(Tree*);