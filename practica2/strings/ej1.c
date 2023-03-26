#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int cant=0;

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", str);
    while (strcmp(str,"ZZZ") != 0){
        if (strlen(str) == 5){
            cant++;
        }
        scanf("%s", str);
    }

    printf("La cantidad de cadenas de 5 caracteres es: %d", cant);
    return 0;
}