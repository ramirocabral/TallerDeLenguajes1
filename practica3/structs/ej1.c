#include <stdio.h>

typedef struct rectangulo{
    float base;
    float altura;
} rec;

void newRec (rec*);
float area (rec r);

int main(){
    rec a[10];
    float menor = __FLT_MAX__;
    float ar;
    int menorNum = 0;
    for (int i=0; i<10; i++){
        newRec(&a[i]);
        ar = area(a[i]);
        printf("El area del rectangulo %d es: %f \n", i,ar);
        if (ar < menor){
            menor = ar;
            menorNum = i;
        }
    }
    printf("El rectangulo con menor area es : %d", menorNum);
    return 0;
}

void newRec (rec *r){
    printf("Introduce la base del rectangulo: ");
    scanf("%f", &r->base);
    printf("Introduce la altura del rectangulo: ");
    scanf("%f", &r->altura);
}


float area (rec r){
    float a = r.base * r.altura;
    return a;
} 