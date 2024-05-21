#include <stdio.h>


int Digits(int num) {
    int reversedNum = 0;
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num = num / 10;
    }
    return reversedNum;
}

int main() {
    int num;

    while (1) {
        printf("Give a number ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        int reversed = Digits(num);
        printf(" %d, %d\n", num, reversed);
    }

    return 0;
}
