#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 256

int main(){
    FILE *f;
    f = fopen("./resources/vinos.csv", "r");
    assert(f != NULL);

    FILE *f2;
    f2 = fopen("./resources/ej6.txt", "w");

    char word[SIZE];                    //string auxiliar

    float min[8] = {__FLT_MAX__};       //vector de minimos
    float max[8] = {__FLT_MIN__};       //vector de maximos
    float avg[8] = {0};                //vector de total/promedio
    float act[8];
    int tot = 0;                       //cantidad de vinos leidos

    fgets(word, SIZE, f);               //primera linea
    while (!feof(f)){
        for (int i=0; i<8;i++){
            fscanf(f, "%f;", &act[i]);
            if (act[i] < min[i])
                min[i] = act[i];
            if (act[i] > max[i])
                max[i] = act[i];
            avg[i] += act[i];
        }
        tot++;
        fscanf(f,"%s", &word);            //leer el ultimo string para seguir
    }

    fclose(f);

    for (int i=0; i<8;i++)
        avg[i] /= tot;

    fprintf(f2,"Atributo    \tAcidez Fija\tAcidez Volatil\tAcido Citrico\tAzucares Residuales\tPH       \tSulfatos\tAlcohol \tCalidad\n");
    fprintf(f2,"Minimo      \t%.2f       \t%.2f          \t%.2f         \t%.2f               \t%.2f     \t%.2f    \t%.2f    \t%.2f\n", min[0], min[1], min[2], min[3], min[4], min[5], min[6], min[7]);
    fprintf(f2,"Maximo      \t%.2f       \t%.2f          \t%.2f         \t%.2f               \t%.2f     \t%.2f    \t%.2f    \t%.2f\n", max[0], max[1], max[2], max[3], max[4], max[5], max[6], max[7]);
    fprintf(f2,"Promedio    \t%.2f       \t%.2f          \t%.2f         \t%.2f               \t%.2f     \t%.2f    \t%.2f    \t%.2f\n", avg[0], avg[1], avg[2], avg[3], avg[4], avg[5], avg[6], avg[7]);
    fprintf(f2,"thegame.exe");

    return 0;

}