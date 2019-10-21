/*Name:     Sean Brennan
 *PawPrint: slbvp6
 *Date:     08/20/2019
 *Lab:      Lab_1_Resubmission
 */

# include <stdlib.h>
# include <stdio.h>

int identifyEvenNum(int arr[], int size); // function prototype
int main(void)
{
    //variable declarations
    int size = 7;
    int array[7] = {7,18,9,20,16,5,8};
    
    //printf printing the value of the calling function indentifyEvenNum
    printf("Even numbers in the array: %d\n", identifyEvenNum(array, size));
    
    return 0;
}
int identifyEvenNum(int arr[], int size)
{
    int num = 0;
    
    //for loop to analyze each value in the array
    for(int i=0; i<size; i++)
    {
        //if remainder equals zero, the number is positive.
        if((arr[i] % 2)==0)
        {
            num++;
        }
    }
    return num;
}
