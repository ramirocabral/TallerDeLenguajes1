#include <stdio.h>
#include "./lib/imat.h"


int main(){
    int n;
    scanf("%d",&n);
    while (n!=0){
        if (par(n)){
            printf("%d\n",cuadrado(n));
            printf("%d\n",cubo(n));
        }
        else
            printf("%d\n",factorial(n));
        scanf("%d",&n);
    }
    return 0;
}