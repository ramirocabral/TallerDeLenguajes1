#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define CANT 26
#define STR_SIZE 16

typedef struct{
    char word[STR_SIZE];
    double dif;
}   entry;

double getSize(char *buffer, double *freq);

int main(){
    double freq[CANT] = {12.53,1.42,4.68,5.86,13.68,0.69,1.01,0.70,6.25,0.44,0.01,4.97,3.15,6.71,8.68,2.51,0.88,6.87,7.98,4.63,3.93,0.90,0.02,0.22,0.90,0.52};

    FILE *f1 = fopen("./resources/palabras.txt","r");
    FILE *f2 = fopen("./resources/ej1.idx","wb");

    assert(f1 != NULL && f2 != NULL);

    char buffer[STR_SIZE];
    double dif;
    entry aux;
    
    fseek(f1,0,SEEK_SET);
    fscanf(f1,"%s",buffer);
    while(!feof(f1)){
        buffer[strlen(buffer)] = '\0';
        printf("%s-",buffer);
        dif = getSize(buffer,freq);
        if (dif){
            strcpy(aux.word,buffer);
            aux.dif = dif;       
            fwrite(&aux,sizeof(entry),1,f2);
        }
        fscanf(f1,"%s",buffer);
    }
    
    fclose(f1);
    fclose(f2);

    return 0;
}


double getSize(char *buffer,double *freq){
    double dif=0;
    int length = strlen(buffer);
    if (length < 4 || length > 14) return 0;
    for (int i=0; i<length; i++){
        dif += freq[buffer[i]-'a'] * freq[buffer[i]-'a'];
    }
    
    return dif;
}