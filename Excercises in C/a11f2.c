/*
ics24199

Ο υπολογισμός των ταχυδρομικών τελών για αποστολή επιστολής πραγματοποιείται με τον εξής τρόπο:
για γράμματα από 1 ως 20 γραμμάρια 25 €.
για γράμματα από 20 ως 200 γραμμάρια 60 €
για γράμματα άνω των 200 γραμμαρίων χρεώνεται 0.4 € για κάθε γραμμάριο (π.χ. ένα γράμμα 250
γραμμαρίων χρεώνεται 0.4x250=100 €.).
Να γραφεί ένα πρόγραμμα για τον υπολογισμό και την εμφάνιση των ταχυδρομικών τελών (float) με
δεδομένο το βάρος ενός γράμματος (int).

The calculation of postal fees for sending a letter is carried out in the following way:
for letters from 1 to 20 grams €25.
for letters from 20 to 200 grams €60
for letters over 200 grams, €0.4 is charged for each gram (e.g. a letter of 250
grams is charged 0.4x250=€100.).
To write a program to calculate and display the postal fees (float) with
given the weight of a letter (int).

*/


#include <stdio.h>
int main()
{
int baros;
float taxudromika_telh;

printf("Dwse baros:");
scanf("%d",&baros);

if (baros>=1 && baros<=20)
  {
    taxudromika_telh=25.0;
  }
     else if (baros>20 && baros<=200)
      {
        taxudromika_telh=60.0;
      }

        else if (baros>200)
         {
          taxudromika_telh=0.4 * baros;

         }
           else
           {
             printf("Lathos baros");
             return 1; // otan dothei lathos baros
           }

   printf("Ta taxudromika telh einai : %.2f\n", taxudromika_telh); //%.2f giati theloume 2 dekadika noumera px.25.00 anti gia 25.0000
   return 0;
}
