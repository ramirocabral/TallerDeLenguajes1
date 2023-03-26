#include <stdio.h>

void swap(int* a, int* b);


int main(){
    int arr[5] = {1,2,3,4,5};

    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < 4; i++){
        swap(&arr[i], &arr[4-i]);
    }

    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
}




void swap(int* a, int* b){
    int tmp;
    tmp = *a; // guarda el valor de a
    *a = *b; // almacena b en a
    *b = tmp; // almacena a en b
}