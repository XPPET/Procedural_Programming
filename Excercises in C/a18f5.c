#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTHS 12
#define DAYS_PER_MONTH 30

void generateCharges(int charges[MONTHS][DAYS_PER_MONTH]);
int findMaxCharge(int charges[MONTHS][DAYS_PER_MONTH]);
void findMaxChargeDays(int charges[MONTHS][DAYS_PER_MONTH], int maxCharges[MONTHS]);
void printCharges(int charges[MONTHS][DAYS_PER_MONTH]);
void printMaxCharge(int maxCharge);
void printMaxChargeDays(int maxCharges[MONTHS]);

int main() {
    srand(20); // Orizoume to seed tou srand gia na exoume tous idious pseudotyxaious arithmous se kathe ektelesei

    int charges[MONTHS][DAYS_PER_MONTH];
    int maxCharges[MONTHS];

    generateCharges(charges);

    printf("a) Xreooseis olon ton minon:\n");
    printCharges(charges);

    int maxCharge = findMaxCharge(charges);

    printf("\nb) Megisti xreosi olou tou etous:\n");
    printMaxCharge(maxCharge);

    findMaxChargeDays(charges, maxCharges);

    printf("\nc) Hmeres me megisti xreosi gia kathe mina:\n");
    printMaxChargeDays(maxCharges);

    return 0;
}

void generateCharges(int charges[MONTHS][DAYS_PER_MONTH]) {
    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS_PER_MONTH; j++) {
            charges[i][j] = rand() % 24; // Tyxaioi arithmoi apo 0 ews 23
        }
    }
}

int findMaxCharge(int charges[MONTHS][DAYS_PER_MONTH]) {
    int maxCharge = charges[0][0];

    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS_PER_MONTH; j++) {
            if (charges[i][j] > maxCharge) {
                maxCharge = charges[i][j];
            }
        }
    }

    return maxCharge;
}

void findMaxChargeDays(int charges[MONTHS][DAYS_PER_MONTH], int maxCharges[MONTHS]) {
    for (int i = 0; i < MONTHS; i++) {
        maxCharges[i] = 1; // Αρχικοποίηση σε μία τυχαία ημέρα
        for (int j = 0; j < DAYS_PER_MONTH; j++) {
            if (charges[i][j] == findMaxCharge(charges)) {
                maxCharges[i] = j + 1; // Καταχώρηση της ημέρας με τη μέγιστη χρέωση
            }
        }
    }
}

void printCharges(int charges[MONTHS][DAYS_PER_MONTH]) {
    for (int i = 0; i < MONTHS; i++) {
        printf("Month %d: ", i + 1);
        for (int j = 0; j < DAYS_PER_MONTH; j++) {
            printf("%d ", charges[i][j]);
        }
        printf("\n");
    }
}

void printMaxCharge(int maxCharge) {
    printf("%d\n", maxCharge);
}

void printMaxChargeDays(int maxCharges[MONTHS]) {
    for (int i = 0; i < MONTHS; i++) {
        printf("Month %d: Day %d\n", i + 1, maxCharges[i]);
    }
}
