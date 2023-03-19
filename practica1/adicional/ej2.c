#include <stdio.h>


void convertir(int num);

/*
int main(){
    int num,binario[8],i=0;
    printf("Ingrese un numero decimal: ");
    scanf("%d",&num);
    while (num > 0){
        printf("%d",num);
        binario[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("El numero binario es: ");
    for (int j=i-1; j >= 0 ; j--){
        printf("%d",binario[j]);
    }
    return 0;
}
*/

//pasar un numero decimal a binario recursivamente

int main(){
    int num;
    printf("Ingrese un numero decimal: ");
    scanf("%d",&num);
    printf("El numero binario es: ");
    convertir(num);
    return 0;
}

void convertir(int num){
    if (num > 0){
        convertir(num / 2);
        printf("%d",num % 2);
    }
}