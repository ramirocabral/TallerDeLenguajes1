#include <stdio.h>
#include <stdlib.h>
#include "../../utils/arrayUtils.h"

int main(){
    int n;
    printf("enter the number os elements in the array:");
    scanf("%d",&n);
    double *arr = (double *)malloc(n*sizeof(double));

    double total = 0;
    for (int i=0; i<n;i++){
        double elem;
        printf("enter element %d: ",i);
        scanf("%lf",&elem);
        total = total + elem;
        *(arr+i) = elem;
    }

    printf("average: %lf",total/((double)n));

    free(arr);

    return 0;
}