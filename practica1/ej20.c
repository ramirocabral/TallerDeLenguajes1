#include <stdio.h>


int damePar();

int main(){
    int n;

    printf("Introduce un numero: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("%d ", damePar());
    }
}


int damePar(){
    static int i = -2;
    i += 2;
    return i;
}

