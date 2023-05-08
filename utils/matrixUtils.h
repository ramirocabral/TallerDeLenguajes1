#ifndef matrixUtils
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **matrixReserveMemory(int n, int m){
    int** matrix = (int**)malloc(n*sizeof(int*));

    for (int i=0; i<n; i++){
        matrix[i] = (int *)malloc(m*sizeof(int));
    }

    return matrix;
}

void initMatrix(int **matrix,int n,int m){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            matrix[i][j] = rand()%100;
        }
    }
}


void matrixRandom3d(int *arr, int n, int m, int k){ 
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

void printMatrix(int **arr, int n, int m){
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeMatrix(int **arr, int n){
    for (int i=0; i<n; i++){
        free(arr[i]);
    }
    free(arr);
}

void loadMatrixWithArray(int *arr, int m, int n){
    srand(time(NULL));
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            *((arr+ i*m)+j) = rand()%100;
        }
    }
}

void printMatrixWithArray(int *arr, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int val = *((arr + i*m) + j);
            printf("[%d][%d] : %d\n",i,j,val);
        }
    }
}

void freeMatrixWithArray(int *arr){
    free(arr);
}

#define matrixUtils
#endif