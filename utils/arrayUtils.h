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

void matrizRandom(int *arr, int n, int m){ 
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            *((arr + i*n) + j) = rand()%100;
        }
    }
}

void matrizRandom3d(int *arr, int n, int m, int k){ 
    int i,j,l;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (l = 0; l < k; l++)
            {
                *((arr + i*n*m) + j*m + l) = rand()%100;
            }
        }
    }
}

void printMatriz(int *arr, int n, int m){
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", *((arr + i*n) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMatrix(int matriz[5][5], int n, int m){  //bullshit
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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