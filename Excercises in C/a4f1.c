/*
ics24199

Ένας έμπορος αγόρασε σε τιμή χονδρικής εμπορεύματα αξίας
purchaseAmount € και τα πούλησε saleAmount €. Αν το ποσό
saleAmount προκύπτει από την καθαρή αξία purchaseAmount και το
ποσοστό κέρδους rate του εμπόρου επί της καθαρής αξίας
purchaseAmount, να γίνει πρόγραμμα που να υπολογίζει και να εμφανίζει:
α) το κέρδος του εμπόρου profit (double), β) το εισπραχθέν ποσό saleAmount (double).
Τα δεδομένα εισόδου να έχουν τη μορφή:
purchaseAmount (μεταβλητή τύπου long)
rate (μεταβλητή τύπου int, εάν το ποσοστό κέρδους είναι 10% τότε πληκτρολογούμε 10)

A merchant bought at a wholesale price goods of value
purchaseAmount € and sold them saleAmount €. If the amount
saleAmount is derived from net purchaseAmount and the
merchant's rate of profit on net worth
purchaseAmount, be a program that calculates and displays:
a) the trader's profit profit (double), b) the amount collected saleAmount (double).
The input data should be in the form:
purchaseAmount (variable of type long)
rate (variable of type int, if the profit rate is 10% then we type 10)
*/


#include <stdio.h>
int main(){
long purchaseamount;
int rate;
double profit;
double saleamount;

printf("dose kathari axia:");
scanf("%ld",&purchaseamount);
printf("dose pososto kerdous:");
scanf("%d",&rate);

//profit=purchaseamount*(rate/100);
//allos tropos;
profit=purchaseamount*((double)rate/100);
saleamount=purchaseamount+profit;

printf("kerdos: %g\n",profit);
printf("synoliko poso: %g\n", saleamount);

return 0;
}
