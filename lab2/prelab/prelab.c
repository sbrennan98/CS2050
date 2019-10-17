#include <stdio.h>
#include <stdlib.h>
#define N 8

int lessthan(int n, int *a, int *l, int *g, int c);
void initarray(int n, int *a);

int main(void)
{
    int n=N, compare=5, greater=0, lesser=0;
    int *array=malloc(n*sizeof(int)), *g= &greater, *l= &lesser;

    initarray(n, array);
    lessthan(n, array, l, g, compare);
    printf("n=%d compare=%d greater=%d lesser=%d", n, compare, *g, *l);

    return 0;
}
int lessthan(int n, int *a, int *l, int *g, int c)
{
    for(int i=0; i<n; i++) {
        if(a[i]<c) {
            *l+=1;
        }
        else if(a[i]>c) {
            *g+=1;
        }
    }
    return 0;
}
void initarray(int n, int *a)
{
    for(int i=0; i<n; i++) {
        a[i]=6;
    }
}