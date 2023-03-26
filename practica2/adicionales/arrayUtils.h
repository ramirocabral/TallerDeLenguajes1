#ifndef arrayUtils

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *arrayRandom(int n){
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

void printMatrix(int matriz[5][5], int n, int m){
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

//i need a mergesort method

void mergeSort(int *arr, int n){
    if (n < 2)
    {
        return; //array de size == 1; no hay que ordenarlo
    }
    int mid = n/2;   //creamos las dos mitades
    int *l = (int*)malloc(mid*sizeof(int));
    int *r = (int*)malloc((n-mid)*sizeof(int));
    for (int i = 0; i < mid; i++)
    {
        l[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        r[i-mid] = arr[i];
    }
    mergeSort(l,mid);
    mergeSort(r,n-mid);
    merge(arr,l,mid,r,n-mid); //ordena los dos sub-arrays
    free(l);
    free(r);
}

void merge (int *arr, int *l, int leftCount, int *r, int rightCount){
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    while (i < leftCount && j < rightCount)
    {
        if (l[i] < r[j])
        {
            arr[k++] = l[i++];
        }else{
            arr[k++] = r[j++];
        }
    }
    while (i < leftCount)
    {
        arr[k++] = l[i++];
    }
    while (j < rightCount)
    {
        arr[k++] = r[j++];
    }
}

#define arrayUtils
#endif