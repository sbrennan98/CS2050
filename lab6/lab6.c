/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_6           *
 *Date:     09/24/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int empID, age;
    float salary;
} Record;
//Program Function Prototypes
int readRecordFile(Record ***array, char *filename);
void freeRecordArray(Record ***array, int numElems);
int findSalary(Record **array, int salaryLow, int salaryHigh, int size);

int main(void){
    Record **array;
    int recordSize;
    if((recordSize=readRecordFile(&array, "employee.csv"))==-1){ //create & "initialize" a Record pointer array by using readRecordFile function.
        printf("*!ERROR! Could not open file.*\n");
        return -1;
    }
    else if(recordSize==0){
        printf("*!ERROR! Could not allocate memory.*\n");
        return -2;
    }
    printf("%d\n", findSalary(array, 10000, 50000, recordSize)); //search the number of employees whose salaries are greater than 10000 and less than 50000 and print

    freeRecordArray(&array, recordSize); //free all allocated memories
    return 0;
}
/* readRecordFile(): Takes a ***array & the name of a file to open
 *  -Opens a given filename and error checks, obtains size of array, creates the array of Records, reads data from given file into array, returns size of the array */
int readRecordFile(Record ***array, char *filename){
    FILE* fp;
    int size, i;

    if((fp=fopen(filename, "r"))==NULL){ //open file
        return -1;
    }
    fscanf(fp, "%d", &size); //obtain size of array
    
    //FORGOT MALLOC ERROR CHECKS
    *array=malloc(size*sizeof(Record*));//create first dimension of array: 12 pointers to a record (Record*)
    for(i=0;i<size;i++){ //loop to allocate memory size of a Record
        (*array)[i]=malloc(sizeof(Record)); //malloc returns address of memory large enough for a Record.
        fscanf(fp, "%d,%f,%d", &(*((*array)[i])).empID, &(*((*array)[i])).salary, &(*((*array)[i])).age); //initialize array element values
    }
    //FORGOT MALLOC ERROR CHECKS ABOVE
    return size;
}
/* freeRecordArray: Takes a ***array, and the number of elements(size) of the array.
 *  -Frees the memory of the second dimensions of the array, then finally the last dimension effectively freeing all allocated memory */
void freeRecordArray(Record ***array, int numElems){
    for(int i=0; i<numElems; i++){
        free((*array)[i]);
    }
    free(*array);
}
/* findSalary: takes a **array, the minimum salary, the maximum salary, and the size of the array.
 *  -Returns the amount of employees in the Record array that have a salary above salaryLow and below salaryHigh.*/
int findSalary(Record **array, int salaryLow, int salaryHigh, int size){
    int salaries=0;
/************************************************************************************************************
 * NOTES FOR MYSELF FOR LATER THAT YOU CAN IGNORE                                                           *
 * printf("%d, %f, %d\n", (*array)[4]).empID, (*array)[4].salary, (*array)[4].age); <---- THIS IS WRONG    *
 * printf("%d, %f, %d\n", (*(array)[4]).empID, (*(array)[4]).salary, (*(array)[4]).age); <---- THIS IS RIGHT*
 * printf("%d, %f, %d\n", array[4]->empID, array[4]->salary, array[4]->age); <---- ALTERNATIVE FORM         *
 ************************************************************************************************************/
    for(int i=0; i<size; i++){
        if(((*(array)[i]).salary)<salaryHigh && ((*(array)[i]).salary)>salaryLow){
            salaries++;
        }
    }
    return salaries; //With the given file, the number should be 3982.
}

