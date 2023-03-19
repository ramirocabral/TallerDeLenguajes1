#include <stdio.h>

int main(){
    float pi = 3;
    int j;
    for (int i = 1,  j = 4; i < 100; i++, j += 2){
        if (i % 2 == 0){
            pi = pi - (4.0 / (j*(j-1)*(j-2)));
        }else{
            pi = pi + (4.0 / (j*(j-1)*(j-2)));
        }
    }
    printf("El valor de pi es: %f",pi);
    return 0;
}