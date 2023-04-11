#include <stdio.h>

struct hor{
    unsigned int hora:5;
    unsigned int minuto:6;
    unsigned int segundo:5;
};

typedef union horario{
    struct hor h1;
    unsigned int h2;
} hora;

int main(){

    hora h;

    printf("Introduce la hora: ");
    scanf("%d", &h.h2);

    printf("%d",h);    
}