#include <stdio.h>
#include <stdbool.h>

typedef struct identificacion{
    char pasaporte[20];
    int DNI;
} ident;

typedef struct est{
    char apellido[20];
    char nombre[20];
    char legajo[20];
    ident id;
    bool extranjero; // lo necesito para saber el tipo al imprimir
} estudiante;


int imprimirEst(estudiante es);

int main(){
    estudiante es;
    char op[2];
    printf("Apellido:");
    scanf("%s", es.apellido);
    printf("Nombre:");
    scanf("%s", es.nombre);
    printf("Legajo:");
    scanf("%s", es.legajo);
    printf ("Es extranjero? (s/n):");
    scanf("%s", op);
    if (op[0] == 's'){
        es.extranjero = true;
        printf("Pasaporte:");
        scanf("%s", es.id.pasaporte);

    } else {
        es.extranjero = false;
        printf("DNI:");
        scanf("%d", &es.id.DNI);
    }

    imprimirEst(es);
    return 0;
}

int imprimirEst(estudiante es){
    printf("Apellido: %s", es.apellido);
    printf("Nombre: %s", es.nombre);
    printf("Legajo: %s", es.legajo);
    if (es.extranjero){
        printf("Pasaporte: %s", es.id.pasaporte);
    } else {
        printf("DNI: %d", es.id.DNI);
    }
}