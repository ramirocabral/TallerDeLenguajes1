#include <stdio.h>
#include <stdlib.h>
#include "../../utils/matrixUtils.h"

int main(){
    int x, y;
    int *m;

    printf("enter x value: ");
    scanf("%d", &x);
    printf("enter y value: ");
    scanf("%d", &y);

    m = (int*)malloc(x*y*sizeof(int));

    loadMatrixWithArray(m,x,y);

    printMatrixWithArray(m,x,y);

    freeMatrixWithArray(m);

    return 0;
}