#include <stdio.h>
#include <stdlib.h>

void populate(int a[], int size) {
    srand(20);
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 10;
    }
}

void printArr(int a[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int checkTable(int a[], int size, int N, int positions[]) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == N) {
            positions[count] = i;
            count++;
        }
    }

    return count;
}

int main() {
    const int size = 50;
    int a[size];
    int N;


    populate(a, size);
    printArr(a, size);


    printf("Dose arithmo apo 0 ews to 9: ");
    scanf("%d", &N);

    int positions[size];

    int count = checkTable(a, size, N, positions);


    printf("O arithmos %d emfanizetai %d fores.\n", N, count);
    printf("Stis Theseis: ");
    printArr(positions, count);

    return 0;
}
