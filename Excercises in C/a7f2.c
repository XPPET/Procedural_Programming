/*
ics24199

Να γραφεί ένα πρόγραμμα C για τον υπολογισμό και την εμφάνιση της εβδομαδιαίας αμοιβής ενός
εργαζομένου ως εξής: Το πρόγραμμα θα διαβάζει τον κωδικό αριθμό (long) του εργαζομένου.
Αν ο κωδικός αριθμός είναι μεγαλύτερος ή ίσος του 1000, τότε το πρόγραμμα θα διαβάζει τον ετήσιο
μισθό του εργαζομένου (double) και θα υπολογίζει την εβδομαδιαία αμοιβή (double) του διαιρώντας
τον ετήσιο μισθό δια 52.
Αν ο κωδικός είναι μικρότερος του 1000, τότε το πρόγραμμα θα διαβάζει τις ώρες εβδομαδιαίας
εργασίας (int) του εργαζομένου, την αμοιβή ανά ώρα (double) και στη συνέχεια θα υπολογίζει την
εβδομαδιαία αμοιβή. Αν η εβδομαδιαία
εργασία είναι άνω των 40 ωρών, τότε για τις
ώρες πέρα των 40 ωρών η αμοιβή έχει
προσαύξηση 50%.

Write a C program to calculate and display the weekly pay of a
employee as follows: The program will read the code number (long) of the employee.
If the code number is greater than or equal to 1000, then the program will read the annual
employee's salary (double) and will calculate his weekly pay (double) by dividing
the annual salary by 52.
If the code is less than 1000, then the program will read the weekly hours
work (int) of the employee, the pay per hour (double) and then it will calculate it
weekly pay. If the weekly
work is more than 40 hours, then for the
hours beyond 40 hours the pay has
50% surcharge.
*/


#include <stdio.h>

int main()
{

long code;
double salary;
double hourly_pay;
int working_hours;
double wage;

printf("dwse ton kvdiko");
scanf("%ld",&code);

if (code>=1000)
{

    printf("dwse ton mistho");
    scanf("%lf",&salary );
    wage=salary/52;
}
else
{
    printf("dwse tis wres ebdomadiaias ergasias:");
    scanf("%d",&working_hours);

     printf("dwse tin amoibi ana wra:");
    scanf("%lf",&hourly_pay);

         if(working_hours<=40)
         {

           wage=working_hours*hourly_pay;

         }

               else
               {
                  wage=40*hourly_pay+(working_hours-40)*hourly_pay*1.5;
               }

}
printf("h ebdomadiaia amoibi einai: %g\n", wage);
return 0;

}
