#include <stdio.h>
#include <stdlib.h>
#include "../../utils/linkedList.h"

void generateLists(list l,list *odd,list *even);

int main(){
    int n;
    list l = NULL;
    printf("Enter a number:");
    scanf(" %d",&n);
    while(n != 0){
        addValue(&l,n);
        printf("Enter a number:");
        scanf(" %d",&n);
    }

    printList(l);
    printf("\n");

    list odd=NULL;
    list even=NULL;
    generateLists(l,&odd,&even);

    printList(odd);
    printf("\n");

    printList(even);
    printf("\n");

    freeList(&l);
    freeList(&odd);
    freeList(&even);

    return 0;
}

void generateLists(list l,list *odd,list *even){
    while (l != NULL){
        if (l->value % 2 == 0)
            addValue(even,l->value);
        else
            addValue(odd,l->value);
        l = (*l).next;
    }
}