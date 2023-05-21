#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *f;
    int n,max=-999,maxN=0;
    f = fopen("./resources/precipitaciones.txt","r");

    if (f){
        for (int i=1; i<=31; i++){
            fscanf(f, "%d-", &n);
            if (n > max){
                max = n;
                maxN = i;
            }

        }

        printf("day with more rainfall: %d", maxN);
    }

    fclose(f);

    return 0;
}