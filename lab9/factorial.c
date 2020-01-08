#include <stdio.h>

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}
int main(void){
    printf("Factorial of %d = %d\n", 10, factorial(10));
}