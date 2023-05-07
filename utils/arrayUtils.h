#ifndef arrayUtils

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *arrRandom(int n){
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%100;
    }
    return arr;
}   

//inicializa un array con valores random
void init(int *arr, int n){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        *(arr+i) = rand()%100;
    }
}



void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


//maximo elemento de un array
int max(int *arr, int n){
    int m = -999;

    for (int i=0;i<n;i++){
        if (*(arr + i) > m)
            m = *(arr + i);
    }

    return m;
}


void mergeSort (int *arr, int n){
    int *left = (int*)malloc(n/2*sizeof(int)); //determina las dos mitades
    int *right = (int*)malloc(n/2*sizeof(int));
    int i,j,k;
    for (i = 0; i < n/2; i++)
    {
        left[i] = arr[i];
    }
    for (j = 0; j < n/2; j++)
    {
        right[j] = arr[j+n/2];
    }
    mergeSort(left,n/2);
    mergeSort(right,n/2);
    i = 0;   //ordena los dos subarrays
    j = 0;
    k = 0;
    while (i < n/2 && j < n/2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n/2)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n/2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}


#define arrayUtils
#endif