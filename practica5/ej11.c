#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    FILE *f1 = fopen("./resources/ej9.dat", "rb");
    fseek(f1,0,SEEK_END);
    long int size = ftell(f1);
    fseek(f1,0,SEEK_SET);

    printf("size of strings: %lu\n", sizeof(char)*16);
    printf("size of unsigned int: %lu\n", sizeof(unsigned int));
    printf("size of long double: %lu\n", sizeof(long double));
    printf("Size in bytes: %u", size);
    fclose(f1);
    return 0;
}