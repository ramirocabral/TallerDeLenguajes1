#include <stdio.h>
#include"arrayUtils.h"

int main(){
    int num,dig;
    int cont[9] = {0};

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while(num != 0){
        dig = num % 10;
        cont[dig-1]++;
        num = num / 10;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("El digito %d aparece %d veces en el numero ingresado \n", i+1, cont[i]);
    }

    return 0;
}