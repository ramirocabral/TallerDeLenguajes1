#include <stdio.h>
#include <stdlib.h>
#include "../utils/linkedList.h"

int main(){
    int n;
    list l = NULL;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n != 0){
        addAtEnd(&l,n);
        printf("Enter a number:");
        scanf("%d",&n);
    }
    printList(l);

    list inv = NULL;
    list aux = l;
    while(aux != NULL){
        addatStart(&inv, aux->value);
        aux = (*aux).next;
    }
    printf("\n");
    printList(inv);

    freeList(l);
    freeList(inv);
    return 0;
}