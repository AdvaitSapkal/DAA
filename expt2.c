#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void merge(int*arr,int* aux,int lo,int mid,int hi);
void merge_sort_inner(int* arr,int* aux,int lo, int hi);
void merge(int*arr,int* aux,int lo,int mid,int hi);
void swap(int *arr, int i, int j);
void quick_sort(int* arr,int len);
void quick_sort_inner(int* arr, int lo, int hi);
int partition(int* arr, int lo, int hi);

//merge sort
void merge_sort(int* arr, int len){
    int aux[len];
    merge_sort_inner(arr,aux,0,len-1);
}

void merge_sort_inner(int* arr,int* aux,int lo, int hi){

    if(hi<=lo)return;
    int mid=lo+(hi-lo)/2;
    merge_sort_inner(arr,aux,lo, mid);
    merge_sort_inner(arr,aux,mid+1,hi);
    merge(arr,aux,lo,mid,hi);

}

void merge(int*arr,int* aux,int lo,int mid,int hi){

    for(int i=lo;i<=hi;i++)aux[i]=arr[i];

    int i=lo,j=mid+1;
    for(int k=lo;k<=hi;k++){
        if     (i>mid)               arr[k]=aux[j++];
        else if(j>hi)                arr[k]=aux[i++];
        else if(aux[j]<aux[i])       arr[k]=aux[j++];
        else                         arr[k]=aux[i++];
    }
}

//quick sort

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quick_sort(int* arr,int len){
    quick_sort_inner(arr,0,len-1);
}

void quick_sort_inner(int* arr, int lo, int hi){
    if(lo>=hi)return;
    int j=partition(arr,lo,hi);
    quick_sort_inner(arr,lo,j-1);
    quick_sort_inner(arr,j+1,hi);
}

int partition(int* arr, int lo, int hi){
    int i=lo,j=hi+1;
    while(true){
        while(arr[++i]<arr[lo])if(i==hi)break;
        while(arr[--j]>arr[lo])if(j==lo)break;
        if(i>=j)break;
        swap(arr,i,j);
    }
    swap(arr,lo,j);
    return j;
}


int main(){

   int capacity=100000;

    // INPUT FILE GENERATION
    // //accessing the required file
    // FILE *fptr;
    // fptr=fopen("inputfinal.txt","w");
    // if(fptr!=NULL)printf("file accessed.\n");
    // else {printf("error in accessing file.\n");return -1;}
    // for(int i=0;i<capacity;i++)fprintf(fptr,"%d\n",rand());
    // fclose(fptr);

    //intitializing an array from the input file
    int buff_arr[capacity];
    FILE *fptr=fopen("inputfinal.txt","r");

    if(fptr!=NULL)printf("file accessed.\n");
    else {printf("error in accessing file.\n");return -1;}

    for(int i=0;i<capacity;i++)fscanf(fptr,"%d",&buff_arr[i]);
    fclose(fptr);

    //the subject array and clock variables
    int arr[capacity];
    clock_t start_t;
    clock_t end_t;

    for(int i=100;i<=capacity;i+=100){

        //filling for merge sort
        for(int j=0;j<i;j++)arr[j]=buff_arr[j];

        start_t=clock();
        merge_sort(arr,i);//merge sort
        end_t=clock();
        printf("%7d|%15.3lf|",i,((double)(end_t-start_t))/CLOCKS_PER_SEC); //time


        //filling for quick sort
        for(int k=0;k<i;k++)arr[k]=buff_arr[k];
        start_t=clock();
        quick_sort(arr,i);//quick sort
        end_t=clock();
        printf("%15.3f\n",((double)(end_t-start_t))/CLOCKS_PER_SEC); //time
    }
    
}