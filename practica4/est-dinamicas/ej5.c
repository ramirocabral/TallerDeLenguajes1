#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void process(int *min, int *mayus, char *arr);

int main(){
    char *arr = (char *)malloc(SIZE * sizeof(char));

    for(int i=0; i<10; i++){
        int min=0, mayus=0;
        printf("enter a sentence:");
        gets(arr);
        process(&min,&mayus,arr);
        printf("Lowercase: %d \nUppercase: %d \n",min,mayus);
    }

    free(arr);

    return 0;

}

void process(int *min, int *mayus, char *arr){
    for (int i=0; i<strlen(arr); i++){
        char charac = *(arr+ i);
        if (charac == ' ')
            continue;
        if ((charac >= 'A') && (charac <= 'Z'))
            (*mayus)++;
        else
            (*min)++;
    }
}

