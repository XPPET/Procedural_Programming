/*
ics24199

Να γραφεί ένα πρόγραμμα το οποίο θα υπολογίζει και θα εμφανίζει το GPA της επίδοσης ενός μαθητή
σύμφωνα με τον παρακάτω πίνακα
  %                  GPA
100-86               4.0
85-61                3.0
60-41                2.0
40-31                1.0
Μικρότερο του 31     0.0

Δίνονται τα παρακάτω στιγμιότυπα εκτέλεσης
Enter your marks?86
GPA=4.00
Enter your marks?30
GPA=0.00
Enter your marks?55
GPA=2.00



Write a program that will calculate and display the GPA of a student's performance
according to the table below
  %           GPA
100-86        4.0
85-61         3.0
60-41         2.0
40-31         1.0
Less than 31  0.0

The following execution snapshots are given
Enter your marks? 86
GPA=4.00
Enter your marks? 30
GPA=0.00
Enter your marks? 55
GPA=2.00

*/

#include <stdio.h>

int main() {
    int marks;
    float gpa;

    printf("Enter your marks: ");
    scanf("%d", &marks);

    if (marks >= 86 && marks <= 100) {
        gpa = 4.0;
    } else if (marks >= 61 && marks <= 85) {
        gpa = 3.0;
    } else if (marks >= 41 && marks <= 60) {
        gpa = 2.0;
    } else if (marks >= 31 && marks <= 40) {
        gpa = 1.0;
    } else {
        gpa = 0.0;
    }

    printf("GPA=%.2f\n", gpa);

    return 0;
}
