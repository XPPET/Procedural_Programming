/*
ics24199

Να γραφεί πρόγραμμα που θα υπολογίζει και θα εμφανίζει το ύψος (int) ενός παιδιού όταν δίνεται από τον
ακόλουθο τύπο :
Υ = (1.12Β + 65)1.2 + 7.0
όπου Β είναι το βάρος του σε kgr (int) και το ύψος (int) του υπολογίζεται σε cm.
Υπόδειξη: για τη στρογγυλοποίηση μπορείτε να χρησιμοποιήσετε τη συνάρτηση ceil της βιβλιοθήκης
math.

Write a program that will calculate and display the height (int) of a child when given by
following formula:
Y = (1.12B + 65)1.2 + 7.0
where B is his weight in kgr (int) and his height (int) is calculated in cm.
Hint: for rounding you can use the ceil function of the library
math.

*/


#include <stdio.h>
#include <math.h>


int main()
{
int baros;
int height;

printf("dose to baros:");
scanf("%d",&baros);

//typos;
height=((1.12*baros+65)*1.2+7.0);

printf("to ypsos einai : %d\n",height);

return 0;

}
