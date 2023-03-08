#include <stdio.h>
#include <stdbool.h>


bool esPrimo(int n);

int main(){
    int cantPrimos=0,n;
    while (cantPrimos < 5){
        printf("Ingrese un numero:");
        scanf("%d",&n);
        if (esPrimo(n)){
            cantPrimos++;
            printf("%d es primo \n",n);
        }
    }
}


bool esPrimo(int n){
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}