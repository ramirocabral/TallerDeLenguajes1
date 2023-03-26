#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int cant=0;

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", str);
    while (strcmp(str,"XXX") != 0){
        if (str[strlen(str) - 1] == 'o'){
            cant++;
        }
        scanf("%s", str);
    }

    printf("La cantidad de cadenas que terminan en 'o' es: %d", cant);

    return 0;
}