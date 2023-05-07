#include <stdio.h>
#include <stdlib.h>

float *reserve(int n);
void init(float *arr, int n);
float prom(float *arr, int n);

int main(){
    int n;
    printf("enter the number of floats stored in the array:\n");
    scanf("%d",&n);

    float *arr = reserve(n);

    init(arr,n);

    printf("average: %f",prom(arr,n));

    free(arr);

    return 0;
}


float *reserve(int n){
    float *p = (float *)malloc(n*sizeof(float));
    return p;
}

void init(float *arr, int n){
    float f;
    for (int i=0; i<n; i++){
        printf("Enter number %d :\n",i);
        scanf("%f",&f);
        *(arr+i) = f;
    }
}

float prom(float *arr, int n){
    float tot = 0;
    for (int i=0; i<n; i++){
        tot+=*(arr+i);
    }
    return (tot/n);
}