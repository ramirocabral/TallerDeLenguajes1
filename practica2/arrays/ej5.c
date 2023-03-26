#include <stdio.h>
#include <stdlib.h>
#include"arrayUtils.h"

int main(){
    int matriz[3][3];
    int matriz2[3][3];
    int matriz3[3][3];

    matrizRandom((int *)matriz,3,3);
    printMatriz((int *)matriz,3,3);

    matrizRandom((int *)matriz2,3,3);
    printMatriz((int *)matriz2,3,3);

    sumarMatrices((int *)matriz,(int *)matriz2,(int *)matriz3,3,3);
    printMatriz((int *)matriz3,3,3);

}


void sumarMatrices(int *matriz1, int *matriz2, int *matriz3, int n, int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            *(matriz3+i*m+j)=*(matriz1+i*m+j)+*(matriz2+i*m+j);
        }
    }
}