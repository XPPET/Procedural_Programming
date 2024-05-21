#include <stdio.h>
#include <stdlib.h>


#define M 5
#define N 4

void populate(int a[M][N]) {
    srand(30);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 21; // Τυχαίος αριθμός από 0 έως 20
        }
    }
}

void print_2d(int a[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void FindMaxMinRow(int a[M][N], int rowSize, int rowIndex, int *max, int *min) {
    *max = a[rowIndex][0];
    *min = a[rowIndex][0];

    for (int j = 1; j < rowSize; j++) {
        if (a[rowIndex][j] > *max) {
            *max = a[rowIndex][j];
        }
        if (a[rowIndex][j] < *min) {
            *min = a[rowIndex][j];
        }
    }
}

int main() {
    int a[M][N];
    int rowIndex, max, min;

    populate(a);

    print_2d(a);

    while (1) {
        printf("\nGive line number ", M - 1);
        scanf("%d", &rowIndex);

        if (rowIndex == -1) {
            break;
        }

        if (rowIndex < 0 || rowIndex >= M) {
            printf("Wrong\n");
            continue;
        }

        FindMaxMinRow(a, N, rowIndex, &max, &min);

        printf( "%d ,%d\n", max,min);

    }

    return 0;
}
