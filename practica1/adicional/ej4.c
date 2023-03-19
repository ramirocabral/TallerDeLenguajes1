#include <stdio.h>


void suma(int num);
int sumar(int num);

int main(){
    int num;
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    suma(num);
    return 0;
}

void suma(int num){
    printf("%d \n",num);
    if (num / 10 > 0){
        num = sumar(num);
        suma(num);
    }
}



int sumar(int num){
    int suma = 0;
    while (num > 0){
        suma += num % 10;
        num = num / 10;
    }
    return suma;
}