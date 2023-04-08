#include <stdio.h>

#define SIZE 1

typedef struct direccion{
    char calle[50];
    char ciudad[30];
    int codigoPostal;
    char pais[40];
} dir;

typedef struct alumno{
    char apellido[50];
    char nombre[50];
    char legajo[8];
    float promedio;
    dir domicilio;
} alu;

void initAlu(alu*);

int main(){
    float mejorProm = __FLT_MIN__;
    char mejorAp[50];
    char mejorNom[50];
    alu a[SIZE];
    for (int i=0; i<SIZE; i++){
        initAlu(&a[i]);
        if (a[i].promedio > mejorProm){
            mejorProm = a[i].promedio;
            strcpy(mejorAp, a[i].apellido);
            strcpy(mejorNom, a[i].nombre);
        }   
    }
    //imprimir los datos del alumno
    for (int i=0; i<SIZE; i++){
        printf("Apellido: %s", a[i].apellido);
        printf("Nombre: %s", a[i].nombre);
        printf("Legajo: %s", a[i].legajo);
        printf("Promedio: %f", a[i].promedio);
        printf("Calle: %s", a[i].domicilio.calle);
        printf("Ciudad: %s", a[i].domicilio.ciudad);
        printf("Codigo Postal: %d", a[i].domicilio.codigoPostal);
        printf("Pais: %s", a[i].domicilio.pais);
    }
    return 0;
}

void initAlu(alu *a){
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", &a->apellido);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", &a->nombre);
    printf("Ingrese el legajo del alumno: ");
    scanf("%s", &a->legajo);
    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    printf("Ingrese la calle del domicilio del alumno: ");
    scanf("%s", &a->domicilio.calle);
    printf("Ingrese la ciudad del domicilio del alumno: ");
    scanf("%s", &a->domicilio.ciudad);
    printf("Ingrese el codigo postal del domicilio del alumno: ");
    scanf("%d", &a->domicilio.codigoPostal);
    printf("Ingrese el pais del domicilio del alumno: ");
    scanf("%s", &a->domicilio.pais);
}