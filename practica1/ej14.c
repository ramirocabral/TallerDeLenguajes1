#include <stdio.h>

int invertir(int n);

int main(){
    int n;
    printf("Ingrese un numero:");
    scanf("%d",&n);
    printf("El numero invertido es: %d",invertir(n));
    return 0;
}

int invertir(int n){
    int invertido = 0;
    while (n > 0){
        invertido = invertido * 10 + n % 10;
        n = n / 10;
    }
    return invertido;
}