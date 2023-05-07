#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

typedef nodo *list;


list initList(){
    list aux = (list)malloc(sizeof(nodo));
    aux->next = NULL;
    return aux;
}

void freeList(list *l){
    list aux;
    while (*l != NULL){
        aux = *l;
        *l = (*(*l)).next;
        free(aux);
    }
}

void addatStart(list *l, int n){
    list nue = (list)malloc(sizeof(nodo));
    nue->value = n;
    (*nue).next = *l;
    *l=nue;
}

void addAtEnd(list *l, int n){
    list aux;
    aux = (list)malloc(sizeof(nodo));
    aux->value = n;
    (*aux).next = NULL;
    if (*l != NULL){
        list act = *l;
        while ((*act).next != NULL)
            act = (*act).next;
        (*act).next = aux;
    }
    else
        *l = aux;
}

int sizeOfList(list l){
    int size = 0;
    while(l != NULL){
        size++;
        l = (*l).next;
    }
    return size;
}

void printList(list l){
    while ((*l).next != NULL){
        printf("%d -> ",l->value);
        l = (*l).next;
    }
    printf("%d",l->value);
}

int main(){
    list l = initList(5);
    addAtEnd(&l,6);
    addAtEnd(&l,7);
    addAtEnd(&l,8);
    addatStart(&l,4);
    printList(l);
    printf("\n");
    printf("size: %d\n",sizeOfList(l));
    return 0;
    freeList(&l);
    printList(l);
    return 0;
}