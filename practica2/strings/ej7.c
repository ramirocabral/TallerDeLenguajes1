#include <stdio.h>
#include <string.h>

int esPalindroma(char *str){
    for (int i = 0; i < strlen(str)/2; i++){
        if (str[i] != str[strlen(str)-i-1]){
            return 0;
        }
    }
    return 1;
}

int esPalindroma2(char *str){
    for (int i=0; i < strlen(str)/2;i++){
        if (*(str+i) != *(str+strlen(str) - i -1 )){
            return 0;
        }
    }
    return 1;
}


int main(){
    char str[100] = "rador";
    printf("%d",esPalindroma(str));
    printf("%d",esPalindroma2(str));
    return 0;
}
