#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool realizarCuenta();

int main(){
    srand(time(NULL));
    int resueltas = 0;
    for (int i=0; i<4; i++){
        if (realizarCuenta()){
            resueltas++;
        }
    }
    switch(resueltas){
        case 0:
            printf("E");
            break;
        case 1:
            printf("D");
            break;
        case 2:
            printf("C");
            break;
        case 3:
            printf("B");
            break;
        case 4:
            printf("A");
            break;
    }
}


bool realizarCuenta(){
    int a,b,res;
    a = rand()%100;
    b = rand()%100;
    printf("%d + %d = ", a, b);
    scanf("%d", &res);
    return res == a+b;
}