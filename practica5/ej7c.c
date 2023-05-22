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

    fseek(f1, 0, SEEK_END);
    int cant = ftell(f1);
    fseek(f1, 0, SEEK_SET);

    char a[cant+1];

    fread(a, sizeof(char), cant, f1);
    fwrite(a, sizeof(char), cant, f2);

    fclose(f1);
    fclose(f2);

    return 0;
}