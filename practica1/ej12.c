#include <stdio.h>
#include <math.h>

int main(){
    double p2,p3,raiz;
    for (int i = 1 ; i<=10 ; i++){
        p2 = pow(i,2);
        p3 = pow(i,3);
        raiz = sqrt(i);
        printf("%d^2 = %f",i,p2);
        printf("%5d^3 = %f \n",i,p3);
        printf("sqrt(%d) = %f \n",i,raiz);
    }
    return 0;
}