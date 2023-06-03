#include <stdio.h>
#include <stdlib.h>
#include "../utils/arrayUtils.h"

#define SIZE 1000

#define DEBUG 0

int pos(int *arr, int dim, int num);
int main(){
    int *arr = arrRandom(1000);
    printf("pos: %d\n", pos(arr, SIZE, 5));

}

int pos(int *arr, int dim, int num){
    int i;
    for(i=0; i<dim; i++){
        if(arr[i] == num){
            #if DEBUG
                printf("debug: %d\n", i);
            #endif
            return i;
        }
    }
    return -1;
}