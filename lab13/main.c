//Include lab12.h header file for test program below
#include "lab12.h"

int main(void){

    srand(time(NULL));

    int size = 1000;
    PQueue *PQ = initPQ(size);
    printPQ(PQ);

    for (int i = 0; i < size + 2; i++){
        if (insertPQ(PQ, rand() % size) == 0){
            if ((i + 1) % (size / 10) == 0){
                printf("\n%dth insertion succeeded.\n",i+1);
                printPQ(PQ);
            }
        } else {
            printf("\n%dth insertion failed.\n",i+1);
        }
    }

    for (int i = 0; i < 10; i++){
        int query = rand() % size;
        int idx = findIdx(PQ, query);
        if (idx == -1){
            printf("\nBinary Search!\n%d doesn't exist in queue.\n", query);
        } else {
            printf("\nBinary Search!\n%d exists in queue at index %d.\n", query, idx);
        }
    }

    int removedValue;
    for (int i = 0; i < size + 2; i++){
        if (DeQueue(PQ, &removedValue) == 0){
            if ((i + 1) % (size / 10) == 0){
                printf("\n%dth deletion succeeded. Value %d got removed.\n",i+1,removedValue);
                printPQ(PQ);
            }
        } else {
            printf("\n%dth insertion failed.\n",i+1);
        }
    }

    freePQ(PQ);
    printf("\nPQ has been freed. Test done\n");

    return 0;

}