#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int empID, age;
    float salary;
} Record;

int readRecordFile(char *filename, Record ***array);

int main(void){
    Record **array;
    char *filename = "employee.csv";
    int size=readRecordFile(filename, &array);
    printf("Salary is %f\n", array[5]->salary);
}
int readRecordFile(char *filename, Record ***array){
    FILE* fp;
    if((fp=fopen(filename, "r"))==NULL){
        return -1;
    }
    int size;
    fscanf(fp, "%d\n", &size);
    if((*array=malloc(size*sizeof(Record*)))==NULL){
        fclose(fp);
        return 0;
    }
    for(int i=0; i<size; i++){
        if((((*array)[i])=malloc(sizeof(Record)))==NULL){
            fclose(fp);
            for(int j=0; j<i; j++){
                free((*array)[j]);
                (*array)[j]=NULL;
            }
            free(*array);
            *array=NULL;
        }
        fscanf(fp, "%d,%f,%d\n", &((*array)[i])->empID, &((*array)[i])->salary, &((*array)[i])->age); //segfault here
    }
    fclose(fp);
    return size;

}