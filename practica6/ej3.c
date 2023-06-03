#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 4){
        int a = atoi(argv[1]);
        int b = atoi(argv[3]);
        switch (*argv[2]){
            case '+':
                printf("%d",a+b);
                break;
            case '-':
                printf("%d",a-b);
                break;
            case '*':
                printf("%d",a*b);
                break;
            case '/':
                printf("%d",a/b);
                break;
            default:
                printf("wrong operator");
                break;
        }
    }
    else
        printf("wrong number of arguments");
    return 0;
}