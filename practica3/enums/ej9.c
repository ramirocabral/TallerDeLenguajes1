#include <stdio.h>

typedef enum semana{DOMINGO = 1, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO} sem;

void imprimirDato(int dia){
    if (dia >= 1 && dia <= 7){
        printf("El dia de la semana es: %d ", dia);
    }
}

int main(){
    sem dia;
    dia = LUNES;
    imprimirDato(dia);
    return 0;
}
