#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANT 50

typedef struct car{
    char palo[8];
    int num;
}carta;

void initMazo(carta mazo[]);
void imprimirMazo(carta mazo[]);
void barajarMazo(carta mazo[]);

int main(){
    carta mazo[CANT];
    initMazo(mazo);
    imprimirMazo(mazo);
    barajarMazo(mazo);
    printf("\n");
    imprimirMazo(mazo);
    return 0;
}


void initMazo(carta mazo[]){
    const char *palos[] = {"espada", "basto", "oro", "copa"};
    for (int i=0; i<4;i++){ //palos
        for (int j=0; j<12; j++){ //1 al 12 de cada palo
            mazo[i*12+j].num = j+1;
            strcpy(mazo[i*12+j].palo, palos[i]);
        }
    }
    //comodines
    mazo[48].num = 0;
    strcpy(mazo[48].palo, "comodin");
    mazo[49].num = 0;
    strcpy(mazo[49].palo, "comodin");
}

void imprimirMazo(carta mazo[]){
    for (int i=0; i<CANT; i++){
        if (mazo[i].num == 0) 
            printf("%s, ", mazo[i].palo);
        else
            printf("%s %d, ", mazo[i].palo, mazo[i].num);
        if (mazo[i].num == 12) printf("\n");
    }
}

void barajarMazo(carta mazo[]){ //copilot 
    srand(time(NULL));
    carta aux;
    int pos;
    for (int i=0; i<CANT; i++){
        pos = rand() % CANT;
        aux = mazo[i];
        mazo[i] = mazo[pos];
        mazo[pos] = aux;
    }
}