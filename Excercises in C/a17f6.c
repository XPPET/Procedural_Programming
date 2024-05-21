#include <stdio.h>


void ReadData(int arr[3][4]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("Give element %d, %d ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}


void printTab_2d(int arr[3][4]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void FindMaxRowMinCol(int arr[3][4], int row, int col, int *maxRow, int *minCol) {
    *maxRow = arr[row][0];
    for (int j = 1; j < 4; ++j) {
        if (arr[row][j] > *maxRow) {
            *maxRow = arr[row][j];
        }
    }

    *minCol = arr[0][col];
    for (int i = 1; i < 3; ++i) {
        if (arr[i][col] < *minCol) {
            *minCol = arr[i][col];
        }
    }
}

int main() {
    int arr[3][4];

    ReadData(arr);

    printTab_2d(arr);

    int row, col;
    printf("Give row ");
    scanf("%d", &row);

    printf("Give column ");
    scanf("%d", &col);

    int maxRow, minCol;

    FindMaxRowMinCol(arr, row, col, &maxRow, &minCol);

    printf("max=%d, min=%d\n", maxRow, minCol);

    return 0;
}
