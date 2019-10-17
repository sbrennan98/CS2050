/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Lab_5           *
 *Date:     09/17/2019      *
 ****************************/
//Header Files & Preprocessor
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int empID, age;
    float salary;
} Record;
//Program Functions
void* createArray(int n, int elemsize);
int getArraySize(void *array);
void freeArray(void *array);
int getSize(FILE* fp);
void initRecordArray(FILE* fp, Record *array);
Record scanFile(FILE* fp);
int getMaxAge(Record *array);

int main(void){
    FILE* fp;
    Record *employees;
    if((fp=fopen("employee.csv", "r+"))==NULL){ //1.Open the given csv file & error check
        printf("*!Error! Couldn't open file.*\n");
        return -1;
    }
    if((employees=createArray(getSize(fp), sizeof(Record)))==NULL){  //2.Read an integer giving the number of employee records from the first line of the csv file(getSize). & 3.Allocate an array of employee records (structs) to hold the records in the file like described before. & error check
        printf("*!ERROR! Couldn't allocate memory.*\n");
        return -1;
    }
    initRecordArray(fp, employees); //4.Read the records into the allocated array.
    printf("Array size is %d, and the maximum age is %d.\nLast employee has ID %d, age %d, and salary $%.2f.\n", getArraySize(employees), ((int*)employees)[-1], employees[getArraySize(employees)-1].empID, employees[getArraySize(employees)-1].age, employees[getArraySize(employees)-1].salary); //5.Print out the size of the array, the maximum age among all employees, and the information of the last employee in array.

    freeArray(employees); //6.Free the created array using your “freeArray” function.
    fclose(fp); //close file
    return 0;
}
/* createArray(): Takes the number of indeces, and the size of the element.
 *  -Creates an array of any data type that hides space for two integers before it. */
void* createArray(int n, int elemSize){
    void *array;
    array=malloc((n*elemSize)+(2*sizeof(int)));
    array=((int*)array)+2; //make hidden space for two integers
    ((int*)array)[-2]=n;//set size of array
    return array;
}
/* getArraySize(): Takes a void array.
 *  -Returns the size of an array created by createArray by returning the value stored in ((int*)array)[-2]. */
int getArraySize(void *array){
    return ((int*)array)[-2];
}
/* freeArray(): Takes a void array.
 *  -Frees an array created by createArray to include the hidden space allocated for two integers. */
void freeArray(void *array){
    free(((int*)array)-2);
}
/* getSize(): Takes a FILE pointer.
 *  -Returns the size needed for an array by scanning the first line of a file for an integer. */
int getSize(FILE* fp){
    int size;
    rewind(fp); //reset pointer
    fscanf(fp, "%d", &size);
    rewind(fp); //reset pointer
    return size;
}
/* initRecordArray(): Takes a FILE pointer, and a Record pointer.
 *  -Initializes a Record array by reading from a csv file and writing the data into an array. */
void initRecordArray(FILE* fp, Record *array){
    fscanf(fp, "%*[^\n]\n", NULL);//skip first line of file
    for(int i=0; i<getArraySize(array);i++){
        array[i]=scanFile(fp);
    }
    rewind(fp); //reset pointer
    ((int*)array)[-1]=getMaxAge(array);//set max age
}
/* scanFile(): Takes a FILE pointer.
 *  -Scans data from one line in a csv file into a Record and returns that Record. */
Record scanFile(FILE* fp){
    Record record;
    fscanf(fp, "%d,%f,%d", &record.empID, &record.salary, &record.age);
    return record;
}
/* getMaxAge(): Takes a Record pointer.
 *  -Scans an array of Records and finds the largest value of age contained in the array. */
int getMaxAge(Record *array){
    int max=0;
    for(int i=0; i<getArraySize(array); i++){
        if(max<array[i].age){
            max=array[i].age;
        }
    }
    return max;
}