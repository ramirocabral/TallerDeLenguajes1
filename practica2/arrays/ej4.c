#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"arrayUtils.h"

void printMatrix(int matriz[5][5], int n, int m);

int main(){
    int matriz[5][5];
    int matriz2[5][5];

    for (int i = 0; i < 5; i++)
    {
        memcpy(matriz[i], arrRandom(5), sizeof(int) * 5);
    }

    printMatrix(matriz, 5, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz2[i][j] = matriz[j][i];
        }
    }

    printMatrix(matriz2, 5, 5);

    return 0;


}
