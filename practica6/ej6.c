#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14 //close enough
#define AREA_CIRCULO(r) PI * (r) * (r)

void imprimir(int * v, int size){
    int i;
    for (i=0; i<size; i++){
    printf("v[%d]= %d", i, v[i]);
}
}
int main(){
    for (int i=0; i<10; i++){
        printf("%d : %f\n",i+1,AREA_CIRCULO(rand()%10));
    }
    return 0;
}