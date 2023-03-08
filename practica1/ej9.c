#include <stdio.h>

int main(){
    int a,b;
    char op;

    printf("Introduzca un numero a: ");
    scanf("%d",&a);
    printf("Introduzca un numero b: ");
    scanf("%d",&b);
    printf("Introduzca un operador: ");
    scanf(" %c",&op);

    switch (op){
        case '+': printf("a + b = %d",a+b);
        break;
        case '-': printf("a - b = %d",a-b);
        break;
        case 'x': printf("a * b = %d",a*b);
        break;
        case '/': printf("a / b = %d",a/b);
        break;
        default: printf("Operador no valido");
        break;
    }
}