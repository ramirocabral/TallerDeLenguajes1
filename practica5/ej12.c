#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INDEX_SIZE 5000 //hardcodeado pero se puede hacer bien
#define BUFFER_SIZE 512


typedef struct{
    unsigned long int dni;
    unsigned int desp;
}entry;

typedef struct node{
    entry e;
    struct node *next;
}node;

typedef node *list;


void addValue(list *l, entry e);
void freeList(list *l);
const char* getfield(char* line, int num);
void printList(list l);
void loadFile(FILE *f, list l);

int main(){
    FILE *f1 = fopen("./resources/personas.csv","r");
    FILE *f2 = fopen("./resources/personas.idx","wb+");
    assert(f1 != NULL);
    assert(f2 != NULL);

    list l = NULL;

    unsigned int desp;
    char str[BUFFER_SIZE];
    entry act;
    unsigned long int aux;

    fgets(str,100,f1);                      //header line
    while(!feof(f1)){
        desp = ftell(f1);
        fgets(str,BUFFER_SIZE,f1);
        char *tmp = strdup(str);
        tmp = getfield(tmp,2);              //get the second field of the string
        act.dni = strtol(tmp,NULL,10);      //string to int hack
        act.desp = desp;
        addValue(&l,act);                   //insert to list
    }

    loadFile(f2,l);                         //load the data to the file

    freeList(&l);


    return 0;
}


void loadFile(FILE *f, list l){
    entry aux;
    int cant=0;
    while(l != NULL){
        aux = l->e;
        fwrite(&aux,sizeof(entry),1,f);
        l = (*l).next;
        cant ++;
    }
    printf("cant: %d\n",cant);
}

void addValue(list *l, entry e){
    list aux;
    aux = (list)malloc(sizeof(node));
    aux->e=e;
    list act = *l;
    list ant = act;
    while ((act != NULL) && ((act->e.dni) < e.dni)){
        ant = act;
        act = (*act).next;
    }
    (*aux).next = act;
    if (act == ant)
        *l = aux;
    else
        (*ant).next = aux;
}

void freeList(list *l){
    list aux;
    while (*l != NULL){
        aux = *l;
        *l = (*(*l)).next;
        free(aux);
    }
}

void printList(list l){                         //debugging
    while ((*l).next != NULL){
        printf("%d : %d -> ",l->e.desp,l->e.dni);
        l = (*l).next;
    }
    printf("%d",l->e.dni);
}

const char* getfield(char* line, int num)       //stackoverflow
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
