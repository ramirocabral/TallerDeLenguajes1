#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


void tirada(int* num1, int* num2, int* suma);


int main(){
    int num1,num2,suma,primer;
    bool ganador = false, perdedor=false;
    char asd;

    srand(time(NULL));

    printf("Bienvenido al juego de Copilot");
    scanf("%c",&asd);
    tirada(&num1,&num2,&suma);
    ganador = (suma == 7 || suma == 11);
    perdedor = (suma == 2 || suma == 12);
    primer = suma;

    while (!perdedor && !ganador){
        scanf("%c",&asd);
        tirada(&num1,&num2,&suma);
        perdedor = (suma == 2 || suma == 12);
        ganador = (suma == primer);
    }
    if (ganador)
        printf("Ganaste");
    else
        printf("Perdiste");
}

void tirada(int* num1, int* num2, int* suma){
    *num1 = rand() % 6 + 1;
    *num2 = rand() % 6 + 1;
    *suma = *num1 + *num2;
    printf("num1: %d, num2: %d, suma: %d \n",*num1,*num2,*suma);
}