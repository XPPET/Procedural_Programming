/*
ics24199

a. Ο σημερινός αριθμός αυτοκινήτων που κυκλοφορούν σε μια πόλη είναι 80000.
Αν ο αριθμός αυτός αυξάνεται με ρυθμό 7%,
να γραφεί πρόγραμμα που να υπολογίζει σε πόσα χρόνια ο αριθμός των αυτοκινήτων θα ξεπεράσει τις 160000.
Πόσα θα είναι τότε τα αυτοκίνητα;

Το πρόγραμμα να εμφανίζει τα έτη (long) και τον αριθμό των αυτοκινήτων (long) όταν θα ξεπεράσει το δοσμένο όριο.
Για τον υπολογισμό του ετήσιου αριθμού αυτοκινήτων να χρησιμοποιηθεί ο τύπος:
Αριθμός αυτοκινήτων = ceil(Αριθμός αυτοκινήτων *(1+Ρυθμός αύξησης))


a. The current number of cars in circulation in a city is 80000.
If this number grows at a rate of 7%,
to write a program that calculates in how many years the number of cars will exceed 160000.
How much will the cars be then?

The program should display the years (long) and the number of cars (long) when it exceeds the given limit.
To calculate the annual number of cars, use the formula:
Number of cars = ceil(Number of cars *(1+Rate of growth))

*/



#include <stdio.h>
#include <math.h>

int main() {
    int currentCars = 80000;
    double growthRate = 0.07;  // Ρυθμός αύξησης 7%

    int years = 0;

    while (currentCars <= 160000) {
        currentCars = ceil(currentCars * (1 + growthRate));
        years++;
    }

    printf("SE %d XRONIA, O ARITHMOS TWN AYTOKINHTVN THA XEPERASEI TIS 160000 KAI THA EINAI %d AYTOKINHTA.\n", years, currentCars);

    return 0;
}

