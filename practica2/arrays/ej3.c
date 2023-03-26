#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"arrayUtils.h"

int main(){
    int matriz[3][3];
    int n;

    for (int i = 0; i < 3; i++)
    {
        memcpy(matriz[i], arrRandom(3), sizeof(int) * 3);
    }

    for (int i = 0; i < 3; i++)
    {
        printArray(matriz[i], 3);
    }

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++){
            matriz[i][j] = matriz[i][j] * n;
        }
    }

printf("Matriz Resultante:\n");

    for (int i = 0; i < 3; i++)
    {
        printArray(matriz[i], 3);
    }



    return 0;
}