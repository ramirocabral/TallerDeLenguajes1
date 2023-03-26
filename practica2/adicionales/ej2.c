#include <stdio.h>
#include"arrayUtils.h"

#define CANT_DATOS 10

void opcion1(int datos[]);
void opcion2(int *datos);
void opcion3(int *datos);
void opcion4(int datos[]);
void opcion5(int datos[]);
void opcion6(int *datos);
void opcion7(int datos[]);
void opcion8(int *datos);

int main(){
    int datos[CANT_DATOS] = {1,2,3,4,5,6,7,8,9,10};

    printf("Original: ");
    printArray(datos, CANT_DATOS);
    opcion8(datos);
    printf("Opcion 8: ");
    printArray(datos, CANT_DATOS);
    return 0;
}




void opcion1(int datos[]){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 datos[i] = datos[i]*0.5;
 }
}
//divide en 2

void opcion2(int *datos){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 (*(datos++))= (*datos)/2;  //siguiente direccion dividida en 2
 }
}
//a lo que apunta datos = (se suma uno a datos) dato(de la sig dir) / 2
//ultimo dato = basura



void opcion3(int *datos){
 int i;
 for (i=0; i<CANT_DATOS; i++, datos++){
 *datos= *datos*0.5;
 }
}
//divide en 2


void opcion4(int datos[]){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 *datos++= *datos/2;
 }
}
//mismo que el 2

void opcion5(int datos[]){
 int i;
 for (i=0; i<CANT_DATOS; i++, datos--){
 *datos++= *datos++*0.5;
 }
}
//misma mierda

void opcion6(int *datos){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 *datos= *datos++*0.5;
 }
}
//divide en 2 redondea para abajo = god

void opcion7(int datos[]){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 datos[i]= *(datos+i)*0.5;
 }
}
//por que harias esto?

void opcion8(int *datos){
 int i;
 for (i=0; i<CANT_DATOS; i++){
 *(datos+i)= datos[i]/2;
 }
}
//a este hay que matarlo directamente