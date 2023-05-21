//no anda el hijo de puta

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARR_SIZE 64

char **storeWords(FILE *f, int *size);
bool isInWords(char **words, int size, char *word);

int main(){
    FILE *f;
    int size=0;
    
    f = fopen("./resources/palabras.txt","r");
    char word[ARR_SIZE];
    char **words = storeWords(f,&size);

    if (f){
        printf("Enter a word:");
        scanf("%s",word); 
        while(strcmp(word,"ZZZ") != 0){
            if (isInWords(words,size,word) == true){
                printf("The word IS in the dictionary\n");
            }
            else{
                printf("The word is not in the dictionary\n");
            }
            printf("Enter a word:");
            scanf("%s",word);
        }
    }
    fclose(f);

    return 0;
}

char **storeWords(FILE *f, int *size){
    char buffer[ARR_SIZE];
    int capacity = 1000;    
    char **words = malloc(capacity*sizeof(char*));

    while (fgets(buffer,ARR_SIZE,f) != NULL){
        if ((*size) >= capacity){
            capacity *= 2;
            words = realloc(words,capacity*sizeof(char*));
        }
        buffer[strcspn(buffer,"\n")] = '\0';
        words[(*size)] = strdup(buffer);
        (*size)++;
    }

    return words;
}

// bool isInWords(char **words, int size, char *word){
//     int left=0,right=size-1;
//     int m = (left+right)/2;
//     while (left<=right){
//         if (strcmp(words[m],word) == 0){
//             return true;
//         } else if (strcmp(words[m],word) < 0){
//             left = m+1;
//         } else {
//             right = m-1;
//         }
//         m = (left+right)/2;
//     }
//     return false;
// }

bool isInWords (char **words, int size, char *word){
    for (int i=0;i<size;i++){
        if (strcmp(words[i],word) == 0){
            return true;
        }
    }
    return false;
}
