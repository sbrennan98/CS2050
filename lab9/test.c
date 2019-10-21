#include <stdio.h>

void PromptAndGetInteger(char *a, int *i);
void PromptAndGetFloat(char *b, float *f);
void PromptAndGetString(char *c, char s[11]); 
void PromptAndGetArray(char *d, int a[11]); 
void PrintArray(int a[11]);

int main(void){
    int i;
    float f; 
    char s[11];
    int a[11];

    printf("\n***********************\n");
    printf("* Welcome to Prelab 6 *\n");
    printf("***********************\n\n");

    PromptAndGetInteger("Please enter an integer and hit enter: ", &i); //passes a string(an array of char), and a pointer to int i. 
    PromptAndGetFloat("Please enter a float and hit enter: ", &f); //passes a string(an array of char), and a pointer to float f.
    PromptAndGetString("Please enter a string with no spaces and hit enter: ",s); //passes a string(an array of char), and a pointer to string s[].
    PromptAndGetArray("Please enter up to 10 positive integers: ",a); //", entering -1 to end" not needed: for loop can be programmed to terminate at ten integers. passes a string(an array of char), and a pointer to int a[].  

    printf("You entered %d,%f,%s\n",i,f,s);
    printf("\n***********************\n");
    PrintArray(a);
}

void PromptAndGetInteger(char *a, int *i){
    printf("%s",a); /* prints a string that is located at a */ 
    scanf("%d", i); /* scans in an in1teger */ //SCANF REQUIRES A POINTER. i IS ALREADY A POINTER SO NO & NEEDED.
}

void PromptAndGetFloat(char *b, float *f){
    printf("%s",b); /* prints a string that is located at b */ 
    scanf("%f", f); /* scans in an integer */ //SCANF REQUIRES A POINTER. f IS ALREADY A POINTER SO NO & NEEDED.
}
void PromptAndGetString(char *c, char s[11]){
    printf("%s", c); //%s required a pointer. c is a pointer
    scanf("%s", s); //SCANF REQUIRES A POINTER. s IS ALREADY A POINTER SO NO & NEEDED.
}
void PromptAndGetArray(char *d, int a[11]){
    printf("%s\n", d);
    int i; //Not necessary but for future reference to save lines of code, you can declare a for loop like so: for(int i=0; i<value; i+=2){} etc..
    for(i = 1; i < 11; i++){ //would be more effecient to declare i as 0 this way: for(int i=0; i<10; i++){} because then printf("array location %d: ", i) would work, you wouldn't have to subtract
        printf("Array location %d: ", i - 1);
        scanf("%d", &a[i]); 
        if(a[i] == -1){ //unnecessary because the for loop will close after ten inputs anyways.
            break;
        } 
    } 
} 
void PrintArray(int a[11]){
    int i;
    for(i = 1; i < 11; i++){ //would be more effecient to declare i as 0 this way: for(int i=0; i<10; i++){} there's actually a bug in the next line of code because you declared it this way:
        if(a[i] == -1){ //a[i] will reach a[11] which is past the scope of the array. This can result in a seg fault that can break your program. You'll learn more about this later, but in 2050, if you have a segfault you get an immediate 0.
        break;
        }
        printf("Entry %d = %d\n",i - 1, a[i]);
    } 
}