#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int sum = 0;
    int foundDigit = 0;

    printf("Insert a string: ");
    fgets(input, sizeof(input), stdin);

    printf("Digits: ");
    for (int i = 0; input[i] != '\0' && i < 99; i++) {
        if (isdigit(input[i])) {
            foundDigit = 1;
            printf("%c ", input[i]);
            sum += input[i] - '0';
        }
    }

    if (foundDigit) {
        printf("\nSum = %d\n", sum);
    } else {
        printf("No digits in input.\n");
    }

    return 0;
}
