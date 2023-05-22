#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    FILE *f1; 
    FILE *f2;

    f1 = fopen("./resources/ej7a.txt", "r");
    f2 = fopen("./resources/ej7b.txt", "w");

    assert(f1 != NULL);
    assert(f2 != NULL);

    char a[100];

    fgets(a,100,f1);
    while(!feof(f1)){
        fputs(a, f2);
        fgets(a,100,f1);
    }


    fclose(f1);
    fclose(f2);

    return 0;
}