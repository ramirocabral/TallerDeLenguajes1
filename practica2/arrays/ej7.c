#include <stdio.h>
#include"arrayUtils.h"

int main(){
    int arr[10][12][30];
    int contMes,mesMenor,mes;
    int anios[10];
    int anioMenor;
    float menorProm,promAnio,contAnio;
    for (int i = 0; i < 10; i++) //recorro los anios
    {
        mesMenor = __INT32_MAX__;
        mes=0;
        promAnio = 0;
        menorProm = __FLT_MAX__;
        anioMenor = 0;
        for (int j = 0; j < 12; j++) //recorro los meses
        {
            contMes = 0; //precipitaciones del mes
            for (int k = 0; k < 30; k++) //recorro los dias
            {
                contMes = contMes + arr[i][j][k];
            }

            if (contMes < mesMenor)
            {
                mesMenor = contMes;
                mes = j;
            }

            contAnio+=contMes;

        }
        promAnio = contAnio / 12;

        if (promAnio < menorProm)
        {
            menorProm = promAnio;
            anioMenor = i;
        }

        anios[i] = mes;
    }

    //me da paja seguir

}