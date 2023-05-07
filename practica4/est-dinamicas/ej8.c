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

    printf("enter the fucking number:");
    scanf("%d",&n);

    printf("\n");

    removeTraverse(l,n);
    printList(l);

    freeList(&l);
    return 0;
}