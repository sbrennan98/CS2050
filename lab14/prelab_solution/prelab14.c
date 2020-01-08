#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main()
{
	srand(time(0));
	int num = 10;

	printf("init\n");
	Tree* tree = initTree();

	printf("Looping\n");
	for (int i = 0; i < num; i++) {
		if (i % (num/7) == 0) {
			printf("%f \n", 100 * (float)i/num);
		}
		insertRandom(tree);
	}

	printf("%i\n", getHeight(tree));
	printTree(tree);

	freeTree(tree);

	return 0;
}