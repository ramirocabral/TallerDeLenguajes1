#include <stdio.h> 

#define DIM 5

int main(){
    printf("Hola");
    int arr[DIM];

    for (int i=0; i < DIM; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&arr[i]);
    }

    int cant1=0, cant2=0;

    for (int i=0; i < DIM; i++){
        if (((arr[i] % 2) == 0) && ((i % 2) == 1))
            cant1++;
        else if (((arr[i] % 2) == 1) && ((i % 2) == 0))
            cant2++;
    }

    printf("Cantidad de numeros pares en posiciones impares: %d, cantidad de numeros impares en posiciones pares: %d", cant1, cant2);

    return 0;

}