#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define STR_SIZE 16
#define DRAW_STR_SIZE 32

void generateFiles(FILE **f){
    for (int i=0; i<10; i++){
        char filename[STR_SIZE];
        sprintf(filename,"./resources/file%d.txt",i);
        f[i] = fopen(filename,"r");
        assert(f[i] != NULL);
    }
}

void closeFiles(FILE **f){
    for (int i=0; i<10; i++){
        fclose(f[i]);
    }
}

unsigned int getSize(FILE *f){
    fseek(f,0,SEEK_END);
    unsigned int size = ftell(f) / STR_SIZE;
    fseek(f,0,SEEK_SET);
    return size;
}

char *randomWord(FILE *f, unsigned int size);
void printScreen(char *show, int turnos, char *incorrectas, FILE *bin, long int dim);
void welcome(int *diff);
void revelarLetras(char *str,char *show,char letter);
void generarBin(FILE *f, FILE *bin);
void imprimirBotija(FILE *bin, int turnos, long int dim);
long int getSizeBin(FILE *bin);

int main(){
    srand(time(NULL));
    FILE *ahorcado = fopen("./ahorcado/art.txt","r");
    FILE *bin = fopen("./ahorcado/art.idx","wb+");
    generarBin(ahorcado,bin);
    int dim = getSizeBin(bin);
    FILE *f[10];
    generateFiles(f);
    FILE *act;
    unsigned int size;

    int turnos = 0;
    unsigned int difficulty = 1;

    welcome(&difficulty);

    act = f[difficulty-1];
    size = getSize(act);   
    char *str = randomWord(act,size);
    char show[STR_SIZE];
    strcpy(show,str);
    for (int i=0; i<strlen(show); i++){
        show[i] = '_';
    }

    bool gameOver = false;
    while(!gameOver && turnos < 7){
        char letter;
        char incorrectas[7];
        printScreen(show,turnos,incorrectas,bin,dim);
        printf("Ingrese una letra: ");
        scanf(" %c",&letter);
        if (strchr(str,letter) != NULL){
            revelarLetras(str,show,letter);
        }
        else{
            incorrectas[turnos] = letter;
            turnos++;
        }
        if (turnos == 7){
            gameOver = true;
            system("clear");
            printf("\nPERDISTE BURRO!!!!!\n");
            printf("La palabra era: %s\n",str);
        }
        else if (strcmp(str,show) == 0){
            system("clear");
            printf("Ganaste!!!!!\n");
            gameOver = true;
        }
    }

    closeFiles(f);
    fclose(ahorcado);
    fclose(bin);
    return 0;
}

void welcome(int *diff){
    printf("                        EL AHORCADO                     \n");
    printf("    +----+\n    |    |\n    |    0\n    |   /|\\\n    |   /'\\\n    |\n    |\n    |========\n    ");
    char option;
    printf("[1] Jugar   \t[2] Dificultad    \t[x] Salir\n");
    scanf("%c",&option);
    if (option == '1'){
    }
    else if (option == '2'){
        printf("Ingrese la dificultad (1-10): ");
        scanf("%d",diff);
    }
    else{
        printf("Saliendo...\n");
        exit(0);
    } 
}

void printScreen(char *show, int turnos, char *incorrectas, FILE *bin, long int dim){
    imprimirBotija(bin,turnos,dim);
    printf("\t\t\t\t%s\n\n",show);
    printf("Letras incorrectas: [%s]\n",incorrectas);
}

char *randomWord(FILE *f, unsigned int size){
    unsigned int random = rand() % size;
    char *word = malloc(sizeof(char)*STR_SIZE);
    fseek(f,random*STR_SIZE,SEEK_SET);
    fscanf(f,"%s",word);
    return word;
}

void revelarLetras(char *str,char *show,char letter){
    for (int i=0; i<strlen(str); i++) if (str[i] == letter) show[i] = letter;
}

long int getSizeBin(FILE *bin){
    fseek(bin,0,SEEK_END);
    long int dim = ftell(bin) / DRAW_STR_SIZE;
    printf("%ld\n",dim);
    fseek(bin,0,SEEK_SET);
    return dim;
}

void imprimirBotija(FILE *bin, int turnos,long int dim){
    fseek(bin,turnos*8*DRAW_STR_SIZE,SEEK_SET);
    for (int i=0; i<8; i++){
        char str[DRAW_STR_SIZE];
        fread(str,sizeof(char),DRAW_STR_SIZE,bin);
        printf("%s\n",str);
    }
}

void generarBin(FILE *f, FILE *bin){
    char str[DRAW_STR_SIZE];
    fgets(str,DRAW_STR_SIZE,f);
    while(!feof(f)){
        str[strlen(str)-1] = '\0';
        fwrite(str,sizeof(char),DRAW_STR_SIZE,bin);
        fgets(str,DRAW_STR_SIZE,f);
    }
}