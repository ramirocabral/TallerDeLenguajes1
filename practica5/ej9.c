#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 16
#define CANT 2

typedef struct{
    char name[SIZE];
    char lastName[SIZE];
    unsigned int age;
    unsigned int titles;
    unsigned int ranking;
    long double netWorth;
}player;


void procesarRanking(char *r1, char *r2, unsigned int *n1, player p);
void procesarTitulos(char *t1, char *t2, unsigned int *n2, player p);


int main(){
    FILE *f1;

    f1 = fopen("./resources/ej9.dat", "wb+");
    assert(f1 != NULL);

    player arr[CANT];
    for (int i=0; i<CANT; i++){
        printf("name of the player: ");
        scanf("%s", arr[i].name);
        printf("last name of the player: ");
        scanf("%s", arr[i].lastName);
        printf("age of the player: ");
        scanf("%u", &arr[i].age);
        printf("titles of the player: ");
        scanf("%u", &arr[i].titles);
        printf("ranking of the player: ");
        scanf("%u", &arr[i].ranking);
        printf("net worth of the player: ");
        scanf("%Lf", &arr[i].netWorth);
        printf("--------------------\n");
    }

    fwrite(arr, sizeof(player), CANT, f1);

    fseek(f1, 0, SEEK_SET);

    player p;
    char r1[SIZE], r2[SIZE];
    char t1[SIZE], t2[SIZE];
    unsigned int n1=999,n2=-999;   
    
    for (int i=0; i<CANT; i++){
        fread(&p,sizeof(player),1,f1);
        procesarRanking(r1, r2, &n1, p);
        procesarTitulos(t1, t2, &n2, p);
    }

    fclose(f1);

    printf("best ranking: %s %s\n", r1, r2);
    printf("player with most titles: %s %s\n", t1, t2);

    return 0;
}

void procesarRanking(char *r1, char *r2, unsigned int *n1, player p){
    if (p.ranking < (*n1)){
        (*n1) = p.ranking;
        strcpy(r1, p.name);
        strcpy(r2, p.lastName);
    }
}

void procesarTitulos(char *t1, char *t2, unsigned int *n2, player p){
    if (p.titles > (*n2)){
        (*n2) = p.titles;
        strcpy(t1, p.name);
        strcpy(t2, p.lastName);
    }
}

