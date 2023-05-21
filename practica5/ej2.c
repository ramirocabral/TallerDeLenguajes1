#include <stdio.h>
#include <stdlib.h>

void digit(int c, int *lower, int *upper, int *numbers);

int main(){
    int lower=0,upper=0,numbers=0;
    FILE *f;

    f = fopen("./resources/ej2.txt", "r");

    int c;
    if (f){
        c = fgetc(f);
        while(!feof(f)){
            digit(c, &lower, &upper, &numbers);
            c = fgetc(f);
        }
    }
    fclose(f);

    printf("Lower: %d\nUpper: %d\nNumbers: %d\n", lower, upper, numbers);

    return 0;

}

void digit(int c, int *lower, int *upper, int *numbers){
    if (c >= 'a' && c <= 'z'){
        (*lower)++;
    }else if (c >= 'A' && c <= 'Z'){
        (*upper)++;
    }else if (c >= '0' && c <= '9'){
        (*numbers)++;
    }
}
