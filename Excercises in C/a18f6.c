#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(int arr[30][3], int seed) {
    srand(seed);

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = rand() % 21;
        }
    }
}

void printTab_2d(int arr[30][3]) {
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void FindStudents(int arr[30][3], int *succeedCount, float *succeedPercentage, int *failCount, float *failPercentage) {
    *succeedCount = 0;
    *failCount = 0;

    for (int i = 0; i < 30; ++i) {
        float mo = (arr[i][0] + arr[i][1] + arr[i][2]) / 3.0;

        if (mo > 18.5) {
            (*succeedCount)++;
        } else if (mo < 9.5) {
            (*failCount)++;
        }
    }

    *succeedPercentage = (*succeedCount / 30.0) * 100;
    *failPercentage = (*failCount / 30.0) * 100;
}

int main() {
    int arr[30][3];
    int seed;

    printf("Give seed:");
    scanf("%d", &seed);

    populate(arr, seed);

    printTab_2d(arr);

    int succeedCount, failCount;
    float succeedPercentage, failPercentage;

    FindStudents(arr, &succeedCount, &succeedPercentage, &failCount, &failPercentage);

    printf("Succeed: %d, %.1f%%\n", succeedCount, succeedPercentage);
    printf("Fail: %d, %.1f%%\n", failCount, failPercentage);

    return 0;
}
