#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **reserveMemory(int n);
void printMatrix(int **matrix, int n);
void initMatrix(int **matrix, int n);
void freeMatrix(int **matrix, int n);

int main(){
    int n;
    printf("n: ");
    scanf(" %d",&n);

    int **matrix = reserveMemory(n);

    initMatrix(matrix, n);

    printMatrix(matrix,n);

    freeMatrix(matrix,n);

    return 0;
}   

int **reserveMemory(int n){
    int **matrix = (int**)malloc(n*sizeof(int*));

    if (matrix == NULL)
        exit(1);

    for (int i=0; i<n ; i++){
        matrix[i] = (int*)malloc(sizeof(int)*(i+1));
        if (matrix[i] == NULL)
            exit(1);
    }

    return matrix;
}

void printMatrix(int **matrix, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j < (i+1); j++){
            int val = matrix[i][j];
            printf("[%d][%d] : %d  -  ",i,j,val);
        }
        printf("\n");
    }
}

void initMatrix(int **matrix, int n){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        for (int j=0; j < (i+1); j++){
            matrix[i][j] = rand()%15;
        }
    }
}

void freeMatrix(int **matrix, int n){
    for (int i=0; i<n; i++){
        free(matrix[i]);
    }
    free(matrix);
}