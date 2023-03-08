#include <stdio.h>


int factorial(int n);
int factorial2 (int n);

int main(){
    int n;
    printf("Ingrese un numero:");
    scanf("%d",&n);
    printf("El factorial de %d es: %d",n,factorial2(n));
    return 0;
}


int factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    return (n * factorial(n - 1));
}

int factorial2 (int n){
    for (int i = (n - 1); i > 0; i--){
        n = n * i;
    }
    return n;
}
