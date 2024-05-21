#include <stdio.h>
#include <string.h>




int main() {
    char word1[100], word2[100];

    printf("Insert two words to find the common characters\n");

    printf("Word 1: ");
    scanf("%s", word1);

    printf("Word 2: ");
    scanf("%s", word2);

    common(word1, word2);
    common_once(word1, word2);

    return 0;
}




void common(const char *word1, const char *word2) {
    printf("Common Characters: ");
    for (int i = 0; word1[i] != '\0'; i++) {
        for (int j = 0; word2[j] != '\0'; j++) {
            if (word1[i] == word2[j]) {
                printf("%c", word1[i]);
                break;
            }
        }
    }
    printf("\n");
}



void common_once(const char *word1, const char *word2) {
    printf("Unique Common Characters: ");
    for (int i = 0; word1[i] != '\0'; i++) {
        for (int j = 0; word2[j] != '\0'; j++) {
            if (word1[i] == word2[j]) {
                int isRepeated = 0;
                for (int k = 0; k < i; k++) {
                    if (word1[i] == word1[k]) {
                        isRepeated = 1;
                        break;
                    }
                }
                if (!isRepeated) {
                    printf("%c", word1[i]);
                }
                break;
            }
        }
    }
    printf("\n");
}

