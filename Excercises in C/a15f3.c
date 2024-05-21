/*
ics24199

Να γραφεί πρόγραμμα το οποίο να εμφανίζει όλους τους αριθμούς (int) από το 1 μέχρι το 100.
Οι αριθμοί να εμφανίζονται ανά δεκάδες σε κάθε γραμμή της οθόνης. Η πρώτη γραμμή, π.χ., από το 1 μέχρι το 10,
η δεύτερη από το 11 μέχρι το 20 κ.ο.κ. Τα δεδομένα κάθε γραμμής είναι στοιχημένα στα δεξιά ανά 4 χαρακτήρες.

Write a program that displays all the numbers (int) from 1 to 100.
The numbers are displayed in tens on each line of the screen.
The first line, for example, from 1 to 10, the second from 11 to 20 and so on.
Each line's data is right-aligned by 4 characters.
*/


#include <stdio.h>

int main() {
    int start = 1;
    int end = 10;

    while (start <= 100) {
        for (int i = start; i <= end; i++) {
            printf("%4d ", i);
        }
        printf("\n");
        start += 10;
        end += 10;
    }

    return 0;
}

