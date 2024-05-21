/*
ics24199

Να γραφεί συνάρτηση που θα δέχεται τρεις παραμέτρους και
-Αν η τιμή της πρώτης παραμέτρου είναι 1, να επιστρέφει ως τιμή το άθροισμα των δύο άλλων παραμέτρων.
-Αν η τιμή της πρώτης παραμέτρου είναι 2, να επιστρέφει ως τιμή το γινόμενο των άλλων δυο παραμέτρων.

-Αν η τιμή της πρώτης παραμέτρου είναι 3, να επιστρέφει ως τιμή τον μέσο όρο των άλλων δυο
παραμέτρων.
-Αν η τιμή της πρώτης παραμέτρου δεν είναι ούτε 1, ούτε 2, ούτε 3, να εμφανίζει στην οθόνη μήνυμα λάθους
“Αντικανονική κλήση συνάρτησης” και να σταματάει το πρόγραμμα με κωδικό εξόδου 1 (θα καλέσετε τη
συνάρτηση exit(1) για να τερματιστεί η εκτέλεση του προγράμματος).
Να επιλέξετε εσείς τον τύπο της συνάρτησης και τον τύπο των παραμέτρων της. Να αναπτυχθεί πρόγραμμα
στο οποίο η συνάρτηση main() θα καλεί την συνάρτηση που αναπτύξατε και θα εμφανίζει τα αποτελέσματά
της για τιμές δεύτερης και τρίτης παραμέτρου 5 και 10, και τιμές πρώτης παραμέτρου 1, 2, 3 και 10.



Write a function that accepts three parameters and:

If the value of the first parameter is 1, it returns the sum of the other two parameters.
If the value of the first parameter is 2, it returns the product of the other two parameters.
If the value of the first parameter is 3, it returns the average of the other two parameters.
If the value of the first parameter is neither 1, nor 2, nor 3, it displays an error message
"Invalid function call" on the screen and terminates the program with exit code 1 (you will call the exit(1)
function to terminate program execution).

You can choose the type of the function and the type of its parameters.
Develop a program in which the main() function calls the function you developed and displays its results for second
and third parameter values ​​5 and 10, and first parameter values ​​1, 2, 3, and 10.
*/

#include <stdio.h>



void exit(int status) {

    exit(status);
}


float calculate(int operation, float param1, float param2) {
    float result;

    if (operation == 1) {
        result = param1 + param2;
    } else if (operation == 2) {
        result = param1 * param2;
    } else if (operation == 3) {
        result = (param1 + param2) / 2;
    } else {
        printf("Antikanonikh klhsh synarthshs\n");
        exit(1);
    }

    return result;
}

int main() {
    int operation;
    float param1, param2;


    scanf("%d", &operation);


    scanf("%f", &param1);


    scanf("%f", &param2);

    float result = calculate(operation, param1, param2);

    if (operation==1){

    printf("Athr: %f\n",result);}


      else if (operation==2){
        printf("Gin: %f\n",result);}

                   else if(operation==3){
                    printf("Mo: %f\n",result);
                   }
                   else {printf(" %f\n",result);}

















    return 0;
}
