#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char word[MAX_LENGTH];
    int letter_count[26] = {0};

    printf("Introduce una palabra: ");
    scanf("%s", word);

    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        char current_letter = word[i];
        if (current_letter >= 'a' && current_letter <= 'z') {
            int index = current_letter - 'a';
            letter_count[index]++;
        }
    }

    printf("La cantidad de veces que aparece cada letra en la palabra es:\n");
    for (int i = 0; i < 26; i++) {
        if (letter_count[i] > 0) {
            printf("%c: %d\n", 'a' + i, letter_count[i]);
        }
    }

    return 0;
}