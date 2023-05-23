#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct{
    unsigned int id;
    unsigned long int dni;
    char apellido [20];
    char nombre [20];
    char trabajo [30];
    char correo[50];
    char ciudad[20];
    char pais[20];
}   persona;

void imprimirPersona(FILE *personas, unsigned int desp);
int buscar(FILE *personas, FILE *indice,unsigned long int dni);


int main(){
    FILE *f1 = fopen("./resources/personas.csv","r");
    FILE *f2 = fopen("./resources/personas.idx","rb");

    assert(f1 != NULL);
    assert(f2 != NULL);

    int ok = buscar(f1,f2,12325238);

    fclose(f1);
    fclose(f2);

    return 0;
}


    //busqueda dicotomica dentro de indice, que esta ordenado por dni
    //devuelve 0 si no se encuentra, 1 si se encuentra
int buscar(FILE *personas, FILE *indice,unsigned long int dni){
    fseek(indice,0,SEEK_END);
    long int cant = ftell(indice) / 16;     //el tamaño de entry es 12 pero se guarda de a 16 bytes
    long int left, right, m;
    left = 0;
    right = cant;
    printf("cant: %ld\n",cant);
    m = (left + right)/2;
    unsigned long int aux;
    unsigned int desp;
    while(left <= right){
        fseek(indice,m*16,SEEK_SET);
        fread(&aux,sizeof(unsigned long int),1,indice);
        fread(&desp,sizeof(unsigned int),1,indice);
        if(aux == dni){
            imprimirPersona(personas,desp);
            return 1;
        }
        else if(aux < dni){
            left = m + 1;
        }
        else{
            right = m - 1;
        }
        m = (left + right)/2;
    }
    printf("no se encontro xd\n");
    return 0;
}


void imprimirPersona(FILE *personas, unsigned int desp){
    persona p;
    fseek(personas,desp,SEEK_SET);//little scanf hack to read values properly
    fscanf(personas,"%d;%u;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",&p.id,&p.dni,p.apellido,p.nombre,p.trabajo,p.correo,p.ciudad,p.pais);
    printf("id: %d\n",p.id);
    printf("dni: %d\n",p.dni);
    printf("apellido: %s\n",p.apellido);
    printf("nombre: %s\n",p.nombre);
    printf("trabajo: %s\n",p.trabajo);
    printf("correo: %s\n",p.correo);
    printf("ciudad: %s\n",p.ciudad);
    printf("pais: %s\n",p.pais);
}