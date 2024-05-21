/*
ics24199

Υπολογισμός των ταχυδρομικών τελών για αποστολή μικροδέματος με "χρονοεπίδοση" πραγματοποιείται
με τον εξής τρόπο:
Πάγιο τέλος 12€ (επιβάρυνση όλων των μικροδεμάτων ανεξαρτήτως λοιπών τελών).
Επιπλέον χρέωση:
για δέματα από 1ως 20 γραμμάρια 5€ ανά γραμμάριο
για δέματα από 20 ως 100 γραμμάρια χρέωση 7€ ανά γραμμάριο για κάθε γραμμάριο επιπλέον των 20
για δέματα άνω 100 γραμμαρίων χρέωση 10€ ανά γραμμάριο για κάθε γραμμάριο επιπλέον των 100
Τα μικροδέματα εξωτερικού επιβαρύνονται με προσαύξηση 12% αν αποστέλλονται προς χώρα της ΕΕ
(Ευρωπαϊκής Ένωσης) ή με 15% προς τις λοιπές χώρες. Η επιβάρυνση για κάθε μικροδέμα υπολογίζεται
σύμφωνα με τον τύπο:
                     (πάγιο + χρέωση) * ποσοστό προσαύξησης %
Να γραφεί ένα πρόγραμμα για τον υπολογισμό και την εμφάνιση των ταχυδρομικών τελών με δεδομένο το
βάρος (int) ενός μικροδέματος και τη χώρα αποστολής, 0: αποστολή προς χώρα της ΕΕ, 1: αποστολή
προς χώρα εκτός της ΕΕ (int). Τα δεδομένα που πρέπει να εμφανίζει το πρόγραμμα είναι το βάρος του
μικροδέματος (int), η επιπλέον χρέωση (int), η επιβάρυνση (float) και τα ταχυδρομικά τέλη της
αποστολής (float).

Calculation of postage for sending a small parcel with "express delivery" is done as follows:
Base fee 12€ (charged for all small parcels regardless of other fees).
Additional charges:
for parcels from 1 to 20 grams, 5€ per gram
for parcels from 20 to 100 grams, a charge of 7€ per gram for each gram beyond 20
for parcels over 100 grams, a charge of 10€ per gram for each gram beyond 100
International parcels are subject to a surcharge of 12% if sent to an EU country (European Union) or 15% to other countries.
The surcharge for each parcel is calculated according to the formula:
                   (base fee + charge) * surcharge percentage %
Write a program to calculate and display the postage based on the weight (int)
 of a small parcel and the destination country, 0: destination to an EU country, 1: destination outside the EU (int).
The data that the program should display are the weight of the parcel (int), the additional charge (int), the surcharge (float),
and the postage for the shipment (float).
*/


#include <stdio.h>

int main() {
    int weight; // Βάρος του μικροδέματος σε γραμμάρια
    int country; // Χώρα αποστολής (0 για ΕΕ, 1 για εκτός ΕΕ)
    float baseFee = 12.0; // Πάγιο τέλος
    float charge = 0.0; // Επιπλέον χρέωση
    float increasePercentage = 0.0; // Ποσοστό προσαύξησης
    float totalPostage = 0.0; // Συνολικά ταχυδρομικά τέλη

    // Εισαγωγή βάρους και χώρας από τον χρήστη
    printf("Dwse baros: ");
    scanf("%d", &weight);
    printf("Dwse ton kwdiko ths xwras apostolhs: ");
    scanf("%d", &country);

    // Υπολογισμός της επιπλέον χρέωσης βάσει του βάρους
    if (weight >= 1 && weight <= 20) {
        charge = 5.0 * weight;
    } else if (weight > 20 && weight <= 100) {
        charge = 100.0 + 7.0 * (weight - 20);
    } else if (weight > 100) {
        charge = 100.0 + 7.0 * 80 + 10.0 * (weight - 100);
    }

    // Υπολογισμός της ποσοστιαίας προσαύξησης
    if (country == 0) { // ΕΕ
        increasePercentage = 12.0;
    } else if (country == 1) { // Εκτός ΕΕ
        increasePercentage = 15.0;
    }
 // Υπολογισμός της επιβάρυνσης χρησιμοποιώντας τον τύπο
    float extraCharge = (baseFee + charge) * (increasePercentage / 100.0);
    // Υπολογισμός των συνολικών ταχυδρομικών τελών
    totalPostage = (baseFee + charge) * (1 + increasePercentage / 100);

    // Εμφάνιση των αποτελεσμάτων
    printf("To baros einai: %d\n", weight);
    printf("H epipleon xrewsh einai: %d\n", (int)charge); // Μετατροπή σε int για εμφάνιση ως ακέραιος
    printf("H epibarynsh einai : %.2f \n", extraCharge);
    printf("Ta taxudromika telh einai : %.2f \n", totalPostage);

    return 0;
}
