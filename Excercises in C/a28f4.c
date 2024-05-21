/*
ics24199

Να γράψετε πρόγραμμα που θα διαβάζει τον κωδικό και την τιμή ενός αγνώστου πλήθους προϊόντων που
αγόρασε κάποιος σε ένα πολυκατάστημα. Ο κωδικός θα πρέπει να είναι στο διάστημα [0..2000] και να
γίνεται ο αντίστοιχος έλεγχος από το πρόγραμμα. Η είσοδος των δεδομένων (κωδικός και τιμή) θα
συνεχίζεται μέχρι να δοθεί ως κωδικός το μηδέν (δείτε παράδειγμα εκτέλεσης).
Έκπτωση
Στην περίοδο των εκπτώσεων γίνεται σε κάθε προϊόν έκπτωση ανάλογα με τον κωδικό του, ως εξής:

Κωδικός προϊόντος      Ποσοστό έκπτωσης
1..300                        5%
301..500                     10%
501..1000                    15%
1001..2000                   20%

Υπολογισμός Πόντων:
Για κάθε προϊόν δίνονται κάποιοι πόντοι, τους οποίους ο πελάτης εξαργυρώνει με διάφορα δώρα. Συγκεκριμένα,
για κάθε προϊόν δίνεται:
• ένας πόντος ανεξάρτητα από την τιμή του και
• επιπλέον για τα προϊόντα με κωδικό από 1000 έως και 1500 ένας πόντος για κάθε 5 Ευρώ της τελικής
αξίας του προϊόντος. (δηλαδή της αξίας που προκύπτει μετά την έκπτωση).Οι επιπλέον πόντοι
υπολογίζονται από τον τύπο
επιπλέον_πόντοι = ceil(τελική αξία/5)
Για παράδειγμα:
Για ένα προϊόν με κωδικό 1200 και τιμή 100€:
• η τελική τιμή θα είναι: 80€
• το ποσό της έκπτωσης: 20€
• οι πόντοι: 17
Για ένα προϊόν με κωδικό 100 και τιμή 10€:
• η τελική τιμή θα είναι: 9.50€
• το ποσό της έκπτωσης: 0.50€
• οι πόντοι: 1
Το πρόγραμμα θα εμφανίζει στην οθόνη τα ακόλουθα:
• το τελικό σύνολο που θα πληρώνει ο πελάτης (μετά την έκπτωση) (με 2 δεκαδικά ψηφία)
• το συνολικό ποσό έκπτωσης (με 2 δεκαδικά ψηφία)
• το σύνολο των πόντων
Παράδειγμα εκτέλεσης του προγράμματος:

Dwse ton kwdiko: 2005
Lathos Kwdikos (0-2000)
Dwse ton kwdiko: 1200
Dwse thn timh: 100
Dwse ton kwdiko: 231
Dwse thn timh: 10
Dwse ton kwdiko: 0
------------------
Teliko synolo: 89.50 Euro
Ekptwsh: 20.50 Euro
Pontoi: 18








Write a program that reads the code and price of an unknown number of products that someone
bought at a supermarket. The code should be in the range [0..2000], and the program should perform
the corresponding check. Data input (code and price) will continue until zero is entered as the code (see execution example).

Discount:
During the discount period, a discount is applied to each product according to its code, as follows:

Product Code Discount     Percentage
1..300                        5%
301..500                     10%
501..1000                    15%
1001..2000                   20%

Points Calculation:
For each product, some points are awarded, which the customer can redeem for various gifts. Specifically, for each product:

• one point is awarded regardless of its price, and
• additionally, for products with codes from 1000 to 1500, one point is awarded for every 5 Euros of the final value of the product.
(i.e., the value after the discount). Additional points are calculated by the formula:
additional_points = ceil(final_value/5)

For example:
For a product with code 1200 and price 100€:
• the final price will be: 80€
• the discount amount: 20€
• points: 17
For a product with code 100 and price 10€:
• the final price will be: 9.50€
• the discount amount: 0.50€
• points: 1

The program will display the following on the screen:
• the total amount the customer will pay (after the discount) (with 2 decimal places)
• the total discount amount (with 2 decimal places)
• the total points

Example execution of the program:
Enter the code: 2005
Incorrect Code (0-2000)
Enter the code: 1200
Enter the price: 100
Enter the code: 231
Enter the price: 10
Enter the code: 0

Total Amount: 89.50 Euros
Discount: 20.50 Euros
Points: 18


*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

double discount_percentage(int code);
int product_points(int code, double price);
int get_code();

int main()
{
    int code, points;
    double price, total, discountSum, final_price, discount;

    total=discountSum=0;
    points=0;
    while(code=get_code())
    {
        printf("Dwse thn timh: ");
        scanf("%lf",&price);
        discount=discount_percentage(code)*price;
        discountSum+=discount;
        final_price=price-discount;
        total+=final_price;
        points+= product_points(code, final_price);
    }
    printf("------------------------\n");
    printf("Teliko synolo: %.2f Euro \n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);
    return 0;
}
int get_code()
{
    int code;
    while (true)
    {
       printf("Dwse ton kwdiko: ");
       scanf("%d",&code);
       if(code>=0 && code<=2000)
       {
           return code;
       }
           printf("Lathos kwdikos (0-2000)\n");
    }
}
double discount_percentage(int code)
{
    if(code<=300)
    {
        return 0.05;
    }
    else if (code<=500)
    {
        return 0.1;
    }
    else if (code<=1000)
    {
        return 0.15;
    }
    else
    {
        return 0.2;
    }
}
int product_points(int code, double fprice)
{
    if (code>=1000 && code<=1500)
    {
        return 1+ceil(fprice/5);
    }
        return 1;
}
