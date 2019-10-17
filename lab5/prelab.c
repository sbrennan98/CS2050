/*
1. Open a file
2. Read an integer giving the number of employee records in the file
3. Allocate an array of employee records (structs) to hold the records in the file
4. Read the records into the allocated array where an employee record is declared as:
    typedef struct {
        int empID, ssn, position;
        float salary;
    } Record;
*/
/****************************
 *Name:     Sean Brennan    *
 *PawPrint: slbvp6          *
 *Lab:      Prelab_5        *
 *Date:     09/13/2019      *
 ****************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int empID, ssn, position;
    float salary;
} Record;

void* createArray(int num, int size);
Record scanFile(FILE* fp);
int getTotalEmp(FILE* fp);
void setEmpArray(FILE* fp, Record* employee);

int main(void){
    Record* employee;
    FILE* fp;
    if((fp=fopen("employees.dat", "r+"))==NULL){ //error check
        printf("*!Error! Couldn't open file.*\n");
        return -1;
    }
    if((employee=createArray(getTotalEmp(fp), sizeof(Record)))==NULL){
        printf("*!Error! Couldn't Allocate memory.*\n");
        return -1;
    }
    setEmpArray(fp, employee);
    printf("Employee[1]:\nempID: %d\nSSN: %d\nPosition#: %d\nSalary: $%2.f", employee[1].empID, employee[1].ssn, employee[1].position, employee[1].salary);

    fclose(fp); //close file
    free(employee);
    return 0;
}
Record scanFile(FILE* fp){     //read file, set values to struct, return struct
    Record record;
    fscanf(fp, "%d %d %d %f", &record.empID, &record.ssn, &record.position, &record.salary);
    return record;
}
int getTotalEmp(FILE* fp){
    int total;
    fscanf(fp, "%d", &total);
    rewind(fp);
    return total;
}
void* createArray(int num, int size){
    void* array;
    array=malloc(num*size);
    return array;
}
void setEmpArray(FILE* fp, Record *employee){
    int total=getTotalEmp(fp);
    fscanf(fp, "%*[^\n]\n", NULL);//skip first line
    for(int i=0; i<total; i++){
        employee[i]=scanFile(fp);
    }
    rewind(fp);
}