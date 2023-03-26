#include <stdio.h>

void inclusivo(char *str, char c1, char c2);


int main(){
    char str[] = "Aguante Boca Juniors - El CABJ";
    inclusivo(str, 'a', 'e');
    printf("%s", str);
}

void inclusivo(char *str, char c1, char c2){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == c1){
            str[i] = c2;
        }
    }
}
