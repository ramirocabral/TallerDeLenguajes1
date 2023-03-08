#include <stdio.h>

void leerNumeros(int n, double* max, double* min);


int main(){
    int n;
    double max, min;
    printf("Ingrese un numero:");
    scanf(" %d",&n);
    leerNumeros(n, &max, &min);
    printf("El maximo es: %f \n",max);
    printf("El minimo es: %f \n",min);
    return 0;
}

void leerNumeros(int n, double* max, double* min){
    int x;
    double my_max = 99999, my_min=-9999;
    for (int i=0; i<n; i++){
        printf("Ingrese un numero:");
        scanf(" %d", &x);
        if (x > my_max){
            my_max = x;
        }
        if (x < my_min){
            my_min = x;
        }
    }
    *max = my_max;
    *min = my_min;
}
