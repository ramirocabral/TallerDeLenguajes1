#include <stdio.h>
#include <stdlib.h>
#include "../../utils/matrixUtils.h"

void multiple3(int **matrix, int n, int m);

int main(){
    int n,m;

    printf("enter numbers of rows: ");
    scanf("%d",&n);
    printf("enter numbers of columnns: ");
    scanf("%d",&m);

    int **matrix = matrixReserveMemory(n,m);

    initMatrix(matrix,n,m);

    printMatrix(matrix,n,m);

    multiple3(matrix,n,m);

    freeMatrix(matrix,n,m);

    return 0;
}

void multiple3(int **matrix, int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (matrix[i][j]%3 == 0){
                printf("Pos: [%d][%d] = %d\n",i,j,matrix[i][j]);
            }
        }
    }
}

