#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int empID, ssn, position;
    float salary;
} Record;

int readRecordFile(Record ***array, char *filename); // reads the file, creates an array of pointers to records, and returns an integer the size of the array. If malloc fails return 0, if fopen fails return -1.
// void adjustSalaries(Record **employees, int n, int position, float x);
// void freeArray(Record ***array, int numElems);

int main(void){
    Record **array;
    int recordSize;
    if((recordSize=readRecordFile(&array, "employees.csv"))==-1){
        printf("*!ERROR! Could not open file.*\n");
        return -1;
    }
    else if(recordSize==0){
        printf("*!ERROR! Could not allocate memory.*\n");
        return -2;
    }
    printf("recordSize: %d\n", recordSize); // error checking
//    adjustSalaries();
//    freeArray(array, recordSize);
    return 0;
}
int readRecordFile(Record ***array, char *filename){
    FILE* fp;
    int size, i, j;
    Record record;

    if((fp=fopen(filename, "r"))==NULL){ //open file
        return -1;
    }
    fscanf(fp, "%d", &size); //obtain size of array
    
    array=malloc(size*sizeof(Record*));//create first dimension of array: 12 pointers to a record (Record*)
    for(i=0;i<size;i++){ //loop to allocate memory size of a Record
        array[i]=malloc(sizeof(Record)); //malloc returns address of memory large enough for a Record.
        fscanf(fp, "%d,%d,%d,%f", &record.empID, &record.ssn, &record.position, &record.salary);
        *array[i]=record;
    }
    printf("Good so far\n"); //error checking

    return size;
}
// void adjustSalaries(Record **employees, int n, int position, float x){
// }
// void freeArray(){
// }
