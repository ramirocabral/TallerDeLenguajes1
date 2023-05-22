#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    FILE *f1, *f2;

    f1 = fopen("./resources/ej8.txt","w");
    f2 = fopen("./resources/ej8.dat","wb");

    assert(f1 != NULL);
    assert(f2 != NULL);


    char a;
    printf("Ingrese numero del 0 al 9: ");
    scanf("%c",&a);
    while(a != 'x'){
        fputc(a,f1);
        fwrite(&a,sizeof(char),1,f2);
        printf("Ingrese numero del 0 al 9: ");
        scanf("%c",&a);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}