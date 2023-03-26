#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* void upperString(char *str);
void numToStr (char *str, int num);
void revString(char *str); */
void numToText(char *str, int num);

int main(){
    char str[100];
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    numToText(str, num);

    printf("El numero %d en texto es: %s", num, str);
}


/* void upperString(char *str){
    int i = 0;
    while (str[i] != "\0")
    {
        if (str[i] >= "a" && str[i] <= "z")
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

void lowerString(char *str){
    int i = 0;
    while (str[i] != "\0")
    {
        if (str[i] >= "A" && str[i] <= "Z")
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}   

void numToStr (char *str, int num){
    int i = 0;
    while (num > 0)
    {
        str[i] = num % 10 + "0";
        num = num / 10;
        i++;
    }
    str[i] = "\0";
    revString(str);
}

void revString(char *str){
    int cant=strlen(str)-1;
    char aux;
    int i;
    for (i=0; i<=cant/2; i++){
        aux=str[i];
        str[i]=str[cant-i];
        str[cant-i]=aux;
    }
}
 */
void numToText(char *str, int num){
    char* single[] = {"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez","once","doce","trece","catorce","quince","dieciseis","diecisiete","dieciocho","diecinueve"};
    char* decenas[] = {"veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
    if (num < 20){
        strcpy(str, single[num]);
    }
    else if (num < 30){
        if (num == 20)
            strcpy(str, decenas[0]);
        else{
            strcpy(str, "veinti");
            strcat(str, single[num-20]);
        }
    }
    else{
        strcpy(str, decenas[(num/10)-2]);
        if (num % 10 != 0){
            strcat(str, " y ");
            strcat(str, single[num%10]);
        }
    }
}