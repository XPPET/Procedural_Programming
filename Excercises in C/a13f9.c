#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    char name[41];
    double balance;
    double interest;
    int yearOpened;
};

const int MAX_CLIENTS = 100;

void readAccounts(const char* fileName, struct Account accounts[], int* count) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    *count = 0;
    while (fscanf(file, "%40s %lf %lf %d",
                  accounts[*count].name,
                  &accounts[*count].balance,
                  &accounts[*count].interest,
                  &accounts[*count].yearOpened) == 4) {
        (*count)++;
    }

    fclose(file);
}

void compareAccounts(struct Account newAccounts[], int newCount,
                     struct Account oldAccounts[], int oldCount) {
    printf("Clients in List New not in Old\n");
    for (int i = 0; i < newCount; i++) {
        int found = 0;
        for (int j = 0; j < oldCount; j++) {
            if (strcmp(newAccounts[i].name, oldAccounts[j].name) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("- %s %.2lf\n", newAccounts[i].name, newAccounts[i].balance);
        }
    }
}

void calculateAndPrintTax(struct Account accounts[], int count, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    double totalBalance = 0.0;
    for (int i = 0; i < count; i++) {
        totalBalance += accounts[i].balance;
    }

    printf("Expected Tax %s %.2lf\n", fileName, 0.4 * totalBalance);

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s, %.2lf, %.6lf, %d\n",
                accounts[i].name, accounts[i].balance,
                accounts[i].interest, accounts[i].yearOpened);
    }

    fclose(file);
}

struct Account findMaxBalanceAccount(struct Account accounts[], int count) {
    struct Account maxAccount = accounts[0];
    for (int i = 1; i < count; i++) {
        if (accounts[i].balance > maxAccount.balance) {
            maxAccount = accounts[i];
        }
    }
    return maxAccount;
}

int main() {
    struct Account newAccounts[MAX_CLIENTS];
    struct Account oldAccounts[MAX_CLIENTS];
    int newCount, oldCount;

    readAccounts("bank_new.dat", newAccounts, &newCount);
    readAccounts("bank_old.dat", oldAccounts, &oldCount);

    compareAccounts(newAccounts, newCount, oldAccounts, oldCount);

    calculateAndPrintTax(newAccounts, newCount, "mztfgm.dat");
    calculateAndPrintTax(oldAccounts, oldCount, "mztfgm_old.dat");

    struct Account maxNewAccount = findMaxBalanceAccount(newAccounts, newCount);
    struct Account maxOldAccount = findMaxBalanceAccount(oldAccounts, oldCount);

    printf("Max in New: %s %d\n", maxNewAccount.name, maxNewAccount.yearOpened);
    printf("Max in Old: %s %d\n", maxOldAccount.name, maxOldAccount.yearOpened);

    return 0;
}
