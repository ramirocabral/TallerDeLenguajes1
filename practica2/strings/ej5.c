#include <stdio.h>

void str_cpy(char *str1, char *str2);

int main(){
    char str1[] = "aaaaaaaaaaaaaaaaaaaaa";
    char str2[] = "Papadopoulos";
    str_cpy(str1,str2);
    printf("%s",str1);
    return 0;
}


void str_cpy(char *str1, char *str2){
    int i;
    for(i=0; str2[i] != '\0';i++){
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}