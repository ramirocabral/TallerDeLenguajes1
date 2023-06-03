#include <stdio.h>
#include "./lib/istack.h"

int main(){
    int n;
    printf("enter number: ");
    scanf( "%d",&n);
    Stack s = s_create();
    while (n != 0){
        s_push(&s,n);
        printf("enter number: ");
        scanf( "%d",&n);
    }
    printf("pop\n");
    while(!s_empty(s)){
        n = s_pop(&s);
        printf("%d\n",n);
    }
    return 0;
}
