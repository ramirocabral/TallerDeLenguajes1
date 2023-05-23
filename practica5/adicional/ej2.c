#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define STR_SIZE 16

typedef struct{
    char word[STR_SIZE];
    double dif;
}entry;

void generateFiles(FILE **f);
void loadData(entry *aux,FILE **files, int size);
void quicksort(entry *aux,int first,int last);
void print(entry *aux,int size);
void closeFiles(FILE **f);


int main(){
    FILE *f1 = fopen("./resources/ej1.idx","rb");
    assert(f1 != NULL);

    fseek(f1,0,SEEK_END);
    int size = ftell(f1) / sizeof(entry);
    fseek(f1,0,SEEK_SET);
    entry *aux = malloc(sizeof(entry)*size);
    fread(aux,sizeof(entry),size,f1);
    quicksort(aux,0,size-1);
    FILE *files[10];
    generateFiles(files);
    loadData(aux,files,size);   //dividir las palabras cargadas en 10 archivos distintos

    fclose(f1);
    free(aux);
    closeFiles(files);
    return 0;
}

void generateFiles(FILE **f){
    for (int i=0; i<10; i++){
        char filename[STR_SIZE];
        sprintf(filename,"./resources/file%d.txt",i);
        f[i] = fopen(filename,"w");
        assert(f[i] != NULL);
    }
}

void loadData(entry *aux,FILE **files, int size){
    int dim = size/10;
    for (int i=0; i<10; i++){
        for (int j=0; j<dim; j++){
            fwrite(&aux[i*dim+j].word,sizeof(char),STR_SIZE,files[i]);
        }
    }
}
            //fwrite(aux[i].word,sizeof(char),STR_SIZE,files[i]);

void quicksort(entry *aux,int first,int last){
    int i, j, pivot;
    entry temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

    while(i<j){
        while(aux[i].dif <= aux[pivot].dif && i < last)
            i++;
        while(aux[j].dif > aux[pivot].dif)
            j--;
        if(i<j){
            temp=aux[i];
            aux[i]=aux[j];
            aux[j]=temp;
        }
    }
    temp=aux[pivot];
    aux[pivot]=aux[j];
    aux[j]=temp;
    quicksort(aux,first,j-1);
    quicksort(aux,j+1,last);
   }
}

void print(entry *aux,int size){
    for (int i=0; i<size; i++){
        printf("%s\n %lf\n",aux[i].word,aux[i].dif);
    }
}

void closeFiles(FILE **f){
    for (int i=0; i<10; i++){
        fclose(f[i]);
    }
}