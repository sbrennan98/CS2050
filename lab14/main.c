#include "lab14.h"

int main(void){
    srand(time(NULL));
    
    int n=0;
    treeNode *t=initTree(randInt());
    for(int i=0; i<1000; i++) insertBT(t, randInt());

    printBT(t);
    countEvenKey(t, &n);
    printf("\n%d\n", n);

    return 0;
}