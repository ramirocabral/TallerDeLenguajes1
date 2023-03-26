#include <stdio.h>

float promedio(int[],int);
float minimo(int[],int);
float posMax(int[],int);

    int main(){
        int arr[5];

        printf("Ingrese 5 numeros: ");
        for (int i = 0; i < 5; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("El promedio es: %f, el minimo es: %f y la posicion del maximo es: %f",promedio(arr,5),minimo(arr,5),posMax(arr,5));

        return 0;
    }

    float promedio(int a[],int n){
        int i;
        float suma=0;
        for(i=0;i<n;i++){
            suma+=a[i];
        }
        return suma/n;
    }

    float minimo(int a[],int n){
        int i;
        float min = __FLT_MAX__;
        for(i=0;i<n;i++){
            if(a[i]<min){
                min=a[i];
            }
        }
        return min;
    }

    float posMax(int a[],int n){
        int pos=0;
        int max = __INT64_MAX__;
        for(int i=0;i<n;i++){
            if(a[i]>max){
                max=a[i];
                pos = i;
            }
        }
        return pos;
    }
