#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc == 5){
        int sum = 0;
        for (int i=1; i<argc; i++){
            sum += atoi(argv[i]);
        }
        float prom = (float)sum/4;
        printf("%f",prom);
    }
    else
        printf("wrong number of arguments");
    return 0;
}