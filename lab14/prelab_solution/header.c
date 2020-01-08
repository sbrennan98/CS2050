# include <stdio.h>
# include <stdlib.h>
# include "header.h"

void insertRandom(Tree *tree) {
	int leftRight = rand() % 2;
	if (leftRight) {
		if (tree->less) {
			insertRandom(tree->less);
		}
		else {
			tree->less = initTree();
		}
	}
	else {
		if (tree->greater) {
			insertRandom(tree->greater);
		}
		else {
			tree->greater = initTree();
		}
	}
}

Tree* initTree() {
	Tree* newTree = malloc(sizeof(Tree));
	if (newTree != NULL
		) {
		newTree->less = NULL;
		newTree->greater = NULL;
	}
	return newTree;
}

void freeTree(Tree* t) {
	if (t == NULL) {
		return;
	}

	freeTree(t->less);
	freeTree(t->greater);
	free(t);
}

int getHeight(Tree* tree) {
	if (tree == NULL) {
		return 0;
	}

	int left = getHeight(tree->less);
	int right = getHeight(tree->greater);
	int greater = left > right ? left : right;

	return greater + 1;
}
void printTree(Tree* t){
	if(t==NULL) return;
    printTree(t->less);
    printTree(t->greater);
    printf("%d\n", t->value);
}