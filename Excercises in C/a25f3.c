/*
ics24199

Να γραφεί πρόγραμμα το οποίο θα διαβάζει έναν ακέραιο αριθμό,
έστω number, ο οποίος θα πρέπει να ελέγχεται ώστε να ισχύει 0≤ number ≤ 1000.
Μετά τον έλεγχο θα υπολογίζει και θα εμφανίζει το άθροισμα των διαδοχικών όρων 1+2+…number.
Ο υπολογισμός του αθροίσματος θα γίνεται με 2 τρόπους:
α) με επαναληπτική δομή
β) με τον παρακάτω τύπο του αθροίσματος διαδοχικών όρων, και θα εμφανίζει και τα 2 αποτελέσματα
1(1)2ninni=+=Σ.

Write a program that will read an integer,
let number, which should be checked to hold 0≤ number ≤ 1000.
After checking it will calculate and display the sum of consecutive terms 1+2+…number.
The sum will be calculated in 2 ways:
a) with a repetitive structure
b) with the sum of consecutive terms formula below, and it will display both results
1(1)2ninni=+=S.

*/

#include <stdio.h>

int main() {
    int number;
    int sumLoop = 0;
    int sumFormula = 0;
    int validInput = 0;

    while (!validInput) {
        printf("Give an integer [0..1000]: ");
        scanf("%d", &number);

        if (number >= 0 && number <= 1000) {
            validInput = 1; // ok eisodos
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // me epanalipsi
    for (int i = 1; i <= number; i++) {
        sumLoop += i;
    }

    // me typo
    sumFormula = (number * (number + 1)) / 2;

    printf("The Sum of 0+1+2...+number is %d %d", sumLoop, sumFormula);


    return 0;
}
