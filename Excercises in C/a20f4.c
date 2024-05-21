/*
ics24199

Να γραφεί πρόγραμμα το οποίο να ζητάει δύο χρονολογίες (π.χ. 2000, 2010) και να εμφανίζει τα δίσεκτα έτη
ανάμεσα σε αυτές τις χρονολογίες. Δίσεκτο είναι ένα έτος όταν διαιρείται ακριβώς με το 4. Όμως τα έτη που
διαιρούνται ακριβώς με το 100 δεν είναι δίσεκτα εκτός αν διαιρούνται ακριβώς με το 400. Για την απόφαση
αν ένα έτος είναι δίσεκτο ή όχι θα πρέπει να χρησιμοποιηθεί συνάρτηση στην οποία θα περνάει ως παράμε -
τρος η χρονολογία και θα επιστρέφει τιμή 1 αν το έτος είναι δίσεκτο, και τιμή 0 αν δεν είναι.


Write a program that requests two dates (e.g. 2000, 2010) and displays the leap years
between these dates. A leap year is when it is exactly divisible by 4. But the years that
exactly divisible by 100 are not bisectors unless they are exactly divisible by 400. For the decision
whether a year is a leap year or not a function should be used in which it will be passed as a param -
tros the date and will return a value of 1 if the year is a leap year, and a value of 0 if it is not.


*/

#include <stdio.h>
#include <stdbool.h>

void xrono_func(int x1, int x2);
bool isLeapYear(int year);

int main() {
    int x1, x2;

    printf("Apo etos: ");
    scanf("%d", &x1);

    printf("Eos etos: ");
    scanf("%d", &x2);

    xrono_func(x1, x2);

    return 0;
}

void xrono_func(int x1, int x2) {
    int i;

    printf("Disekta eti ana meso apo %d eos %d einai:\n", x1, x2);

    for (i = x1; i <= x2; i++) {
        if (isLeapYear(i)) {
            printf("%d \n", i);
        }
    }
    printf("\n");
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
