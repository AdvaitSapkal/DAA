#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int* arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        int mini = i;
        for (int j = i + 1; j < len; j++)if (arr[j] < arr[mini])mini = j;
        swap(arr, i, mini);
    }
}

void insertion_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int curr = arr[i];
        for (int j = i-1; j >= 0; j--)if (arr[j] > curr)swap(arr, j, j+1); else break;
    }
}

int main(){

    //accessing the required file
    FILE *fptr;
    fptr=fopen("input.txt","w");
    if(fptr!=NULL)printf("file accessed.\n");
    else {printf("error in accessing file.\n");return -1;}

    //setting capacity and range to fill the file
    int capacity=100000;
    int range=100;

    for(int i=0;i<capacity;i++){
        putw(rand()%(range+1),fptr);
    }

    //initializing reciever array and clock variables
    int arr[capacity];
        int arr2[capacity];
    clock_t start_t;
    clock_t end_t;

    
    for(int i=100;i<=capacity;i+=100){

        //filling for selection sort
        for(int j=0;j<i;j++){
            arr[j]=getw(fptr);
        }
        start_t=clock();
        selection_sort(arr,i);//selection sort
        end_t=clock();
        printf("%7d|%10.3f|",i,(double)(end_t-start_t));

        /*rewind(fptr); //or can use fseek(fptr, 0, SEEK_SET); to reset pointer to start of file
        as we want same numbers for insertion sort too*/
        fseek(fptr, 0, SEEK_SET);
        
        //filling for insertion sort
        for(int k=0;k<i;k++){
            arr2[k]=getw(fptr);
        }
        start_t=clock();
        insertion_sort(arr2,i);//insertion sort
        end_t=clock();
        printf("%10.3f\n",(double)(end_t-start_t) );
    }

    //closing file
    fclose(fptr);
}