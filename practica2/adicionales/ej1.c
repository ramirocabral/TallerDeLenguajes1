#include <stdio.h>
#include"arrayUtils.h"


int main(){
    int *arr = arrayRandom(10);

    printArray(arr,10);

    mergeSort(arr,10);

    printArray(arr,10);

    return 0;
}
