/*
ics24199

Οι αριθμοί για τους οποίους το άθροισμα των κύβων των ψηφίων τους είναι ίσο με τον ίδιο τον αριθμό
λέγονται αριθμοί Αrmstrong (π.χ. 153 = 13 +53 +33). Να γραφεί πρόγραμμα που θα περιλαμβάνει τα
παρακάτω:

a) την συνάρτηση Sum_Cube που θα δέχεται έναν ακέραιο αριθμό (μεταξύ του 1 και του 999)
και θα επιστρέφει το άθροισμα των κύβων των ψηφίων του.

b) την συνάρτηση IsArmstrong που θα δέχεται έναν ακέραιο αριθμό και θα επιστρέφει την
τιμή true ή false ανάλογα με το αν ο αριθμός είναι Αrmstrong ή όχι αντίστοιχα.
Το κυρίως πρόγραμμα θα βρίσκει και θα εμφανίζει ποιοι είναι αριθμοί Αrmstrong στο διάστημα
(1-999).



The numbers for which the sum of the cubes of their digits is equal to the number itself
are called Armstrong numbers (e.g. 153 = 13 +53 +33). Write a program that will include
below:

a) the function Sum_Cube which will accept an integer (between 1 and 999)
and will return the sum of the cubes of its digits.

b) the function IsArmstrong which will accept an integer and return it
value true or false depending on whether the number is Armstrong or not respectively.
The main program will find and display what the Armstrong numbers are in space
(1-999).

*/

#include <stdio.h>
#include <stdbool.h>
int Cube(int num);
int Sum_Cube(int a);
bool isArmstrong(int num);

int main(){

int i;
for(i=1;i<=999;i++){

 if (isArmstrong(i)) printf("%d\n",i);


}

return 0;
}

int Cube(int num){
int i;
int pront;
pront=1;
for (i=1;i<=3;i++){
    pront=pront*num;
}

return pront;
}

int Sum_Cube(int a){

int digit1,digit2,digit3;
int Sum_Cube_digit;

digit3=a/100;
digit2=(a%100)/10;
digit1=a%10;
Sum_Cube_digit=Cube(digit1)+Cube(digit2)+Cube(digit3);
return Sum_Cube_digit;
}


bool isArmstrong(int num){
if (Sum_Cube(num)==num){
    return true;

}
return false;

}

