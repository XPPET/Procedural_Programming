/*
ics24199

Ένας φορέας διοργανώνει έναν έρανο για φιλανθρωπικούς σκοπούς.
Στόχος του είναι να συλλέξει το ποσό τουλάχιστον των 100.000€.
Να γραφεί πρόγραμμα το οποίο να ζητάει το ποσό που διαθέτει το κάθε άτομο το
οποίο συμμετέχει στον έρανο.
Η επαναληπτική διαδικασία θα σταματάει όταν συμπληρωθεί το ποσό των 100.000€ (μεγαλύτερο ή ίσο).
Τέλος το πρόγραμμα θα εμφανίζει το πλήθος (int) των ατόμων που συμμετείχαν στον έρανο,
το μεγαλύτερο (int) αλλά και το μικρότερο (int) ποσό που δόθηκε.

An organization organizes a fundraiser for charity.
His goal is to collect at least €100,000.
Write a program that requests the amount available to each person
which participates in the fundraiser.
The repeat process will stop when the amount of €100,000 (greater or equal) is reached.
Finally, the program will display the number (int) of people who participated in the fundraiser,
the largest (int) and smallest (int) amount given.

*/

#include <stdio.h>

int main() {
    int targetAmount = 100000;
    int totalAmount = 0;
    int minDonation = -1;
    int maxDonation = -1;
    int numDonors = 0;

    while (totalAmount < targetAmount) {
        int donation;
        printf("Dwse poso: ");
        scanf("%d", &donation);

        if (donation < 0) {
            printf("Lathos.\n");//periptvsh lathous
        } else {
            totalAmount += donation;
            numDonors++;

            if (donation < minDonation || minDonation == -1) {
                minDonation = donation;
            }

            if (donation > maxDonation) {
                maxDonation = donation;
            }
        }
    }

    printf("Plythos atomwn: %d\n",numDonors);
    printf("Synoliko poso: %d\n", totalAmount);
    printf("Megalytero poso: %d\n", maxDonation);
    printf("Mikrotero poso: %d\n", minDonation);


    return 0;
}
