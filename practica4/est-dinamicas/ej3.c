#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *reservar(int n);
void init(int *arr, int n);
int max(int *arr, int n);

int main(){
    int *arr;
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    arr = reservar(n);

    init(arr,n);

    printf("max number: %d", max(arr,n));

    free(arr);

    return 0;
}

int *reservar(int n){
    int *p = (int *)malloc(n * sizeof(int));
    return p;
}

void init(int *arr, int n){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        *(arr+i) = rand()%100;
    }
}

int max(int *arr, int n){
    int m = -999;

    for (int i=0;i<n;i++){
        if (*(arr + i) > m)
            m = *(arr + i);
    }

    return m;
}