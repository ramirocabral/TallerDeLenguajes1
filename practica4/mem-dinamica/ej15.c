#include <stdio.h>
#include <stdlib.h>

int **reserveMemory(int n);
void initTriangule(int **matrix, int n);
void printMatrix(int **matrix, int n);
void freeMatrix(int **matrix, int n);

int main(){
    int n;
    printf("n:");
    scanf("%d", &n);

    int **matrix = reserveMemory(n);

    initTriangule(matrix,n);

    printMatrix(matrix,n);

    freeMatrix(matrix,n);

    return 0;
}

int **reserveMemory(int n){
    int **matrix = (int**)malloc(n*sizeof(int*));

    if(matrix == NULL)
        exit(1);

    for (int i=0; i<n; i++){
        matrix[i] = (int*)malloc(sizeof(int)*(i+1));
        if (matrix[i] == NULL)
            exit(1);
    }

    return matrix;
}

void initTriangule(int **matrix, int n){
    matrix[0][0] = 1;
    for (int i=1; i<n; i++){//for each row
        matrix[i][0] = matrix[i][i] = 1;
        for(int j=1; j<i;j++){//for each column
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
        }
    }
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

void freeMatrix(int **matrix, int n){
    for (int i=0; i<n; i++){
        free(matrix[i]);
    }
    free(matrix);
}