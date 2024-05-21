/*
ics24199

Ο ΦΠΑ ενός προϊόντος μπορεί να ανήκει στις παρακάτω κατηγορίες:
Κατηγορία     Ποσοστό ΦΠΑ
1                0.00
2                0.06
3                0.13
4                0.19
Να γραφεί πρόγραμμα το οποίο θα ζητάει να πληκτρολογούμε το (int) πλήθος, τη (double) τιμή μονάδας και τη (int)
κατηγορία ΦΠΑ για 5 προϊόντα. Το πρόγραμμα θα πρέπει να εμφανίζει το συνολικό κόστος της δαπάνης καθώς και
το σύνολο του ΦΠΑ για όλα τα προϊόντα που αγοράσαμε. Ο υπολογισμός του ΦΠΑ πρέπει να υλοποιείται από μια
συνάρτηση στην οποία θα μεταβιβάζεται το συνολικό ποσό ανά προϊόν καθώς και η κατηγορία στην οποία
ανήκει. Αν ο χρήστης δώσει λάθος κατηγορία ΦΠΑ, τότε η συνάρτηση θα εμφανίσει μήνυμα λάθους, και θα
επιστρέφει τιμή 0. Σε αυτή την περίπτ`ωση, στο συνολικό κόστος δαπάνης υπολογίζεται κανονικά το κόστος
του προϊόντος, το οποίο εισάχθηκε με λάθος ΦΠΑ.



The VAT of a product can belong to the following categories:
Category       VAT Rate
1               0.00
2               0.06
3               0.13
4               0.19
Write a program that asks us to enter the (int) quantity,
the (double) unit price, and the (int) VAT category for 5 products.
The program should display the total cost of the expense as well as the total VAT
for all the products we bought. The calculation of VAT should be implemented by a function to
which the total amount per product and the category it belongs to are passed. If the user
enters an incorrect VAT category, then the function should display an error message and return a
value of 0. In this case, the total expense cost will still include the cost of the product,
which was entered with the wrong VAT.


*/
#include <stdio.h>


double calculateVAT(double cost, int category) {
    double vatRate;

    switch (category) {
        case 1:
            vatRate = 0.00;
            break;
        case 2:
            vatRate = 0.06;
            break;
        case 3:
            vatRate = 0.13;
            break;
        case 4:
            vatRate = 0.19;
            break;
        default:
            printf("Lathos katigoria FPA\n");
            return 0.0;
    }


    double vat = cost * vatRate;
    return vat;
}

int main() {
    int i;
    double totalCost = 0.0;
    double totalVAT = 0.0;

    for (i = 1; i <= 5; i++) {
        int category;
        double unitCost;
        int quantity;

        printf("Dwse to plithos temaxiwn apo to proion %d :",i);
        scanf("%d", &quantity);
        printf("Dwse timi gia to proion %d :", i);
        scanf("%lf", &unitCost);
        printf("Dwse katigoria FPA gia to proion %d :",i);
        scanf("%d", &category);



        double cost = unitCost * quantity;
        double vat = calculateVAT(cost, category);

        totalCost += cost;
        totalVAT += vat;
    }

    printf("Synoliko kostos: %.2lf\n", totalCost+totalVAT);
    printf("Synoliko FPA: %.2lf\n", totalVAT);

    return 0;
}
