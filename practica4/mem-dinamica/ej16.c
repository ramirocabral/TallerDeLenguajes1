#include <stdio.h>
#include <stdlib.h>
#include "../../utils/arrayUtils.h"

int *divisors(int n, int *size);

int main(){
    int n, size=1;
    printf("n: ");
    scanf("%d",&n);

    int *arr = divisors(n,&size);

    printArray(arr,size);

    return 0;
}

int *divisors(int n, int *size){
    int *arr = (int*)malloc((*size)*(sizeof(int)));
    arr[0] = 1;
    for (int i=2; i<=n; i++){
        if (n%i == 0){
            (*size)++;
            arr = realloc(arr,((*size)*sizeof(int)));
            arr[(*size)-1] = i;
        }
    }
    return arr;
}