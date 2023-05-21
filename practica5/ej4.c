#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f;
    float tot=0;
    int cod;
    float bet;
    f = fopen("./resources/apuestas.txt","r");

    if (f){
        fscanf(f,"%d|%f;", &cod, &bet);
        while (!feof(f)){
            tot+=bet;
            fscanf(f,"%d|%f;", &cod, &bet);
        }

        printf("amount of money bet: %f", tot);
    }

    return 0;
}