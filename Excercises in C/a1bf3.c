/*
ics24199

b. Γενικεύστε το πρόγραμμα για Αrithmo_Αytok (long) αυτοκίνητα,
που αυξάνονται με ετήσιο ρυθμό Rythmos και ξεπερνούν ένα δοσμένο όριο Οrio (long),
στοιχεία τα οποία θα εισάγει ο χρήστης.

Το πρόγραμμα να εμφανίζει τα έτη (long) και τον αριθμό των αυτοκινήτων (long) όταν θα ξεπεράσει το δοσμένο όριο.
Για τον υπολογισμό του ετήσιου αριθμού αυτοκινήτων να χρησιμοποιηθεί ο τύπος:
Αριθμός αυτοκινήτων = ceil(Αριθμός αυτοκινήτων *(1+Ρυθμός αύξησης))


b. Generalize the program for Αrithmo_Αytok (long) cars,
which grow at an annual rate of Rythmos and exceed a given limit Εrio (long),
data to be entered by the user.

The program should display the years (long) and the number of cars (long) when it exceeds the given limit.
To calculate the annual number of cars, use the formula:
Number of cars = ceil(Number of cars *(1+Rate of growth))

*/

#include <stdio.h>
#include <math.h>

int main() {
    long initialCars;
    double growthRate;
    long limit;
    long years = 0;

    printf("dwse ton arxiko arithmo aytokinitwn: ");
    scanf("%ld", &initialCars);
    printf("dwse ton etysio rythmo auxishs ");
    scanf("%lf", &growthRate);
    printf("dwse to orio: ");
    scanf("%ld", &limit);

    while (initialCars <= limit) {
        initialCars = ceil(initialCars * (1 + growthRate));
        years++;
    }

    printf("xronia: %ld\n", years);
    printf("arithmos aytokinitwn: %ld\n", initialCars);

    return 0;
}
