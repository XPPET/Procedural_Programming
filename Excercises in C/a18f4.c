/*
ics24199

Να γραφεί συνάρτηση η οποία θα εμφανίζει δέκα φορές τη φράση "Κατανοήστε τη γλώσσα C". Επίσης, να
γραφεί και μια δεύτερη έκδοση της ίδιας συνάρτησης η οποία θα εμφανίσει την ίδια φράση, αλλά το πλήθος
των φορών θα της μεταβιβάζεται ως παράμετρος. (Οι συναρτήσεις θα δηλωθούν τύπου void δεδομένου ότι
δεν επιστρέφουν τιμή.). Να αναπτυχθεί πρόγραμμα στο οποίο η συνάρτηση main() θα καλεί διαδοχικά τις
δύο συναρτήσεις και θα εμφανίζει τα αποτελέσματά τους.


Write a function that will display the phrase "Understand the C language" ten times. Also, yes
a second version of the same function is written which will display the same phrase but the count
times will be passed to it as a parameter. (Functions will be declared of type void since
do not return a value.). Develop a program in which the main() function will call them sequentially
two functions and will display their results.


*/

#include <stdio.h>

void func1();
void func2(int x);
void func3(int a , int b);


int main(){
    int x,a,b;


   func1();



   printf("Give a number ");
   scanf("%d %d",&a,&b);
   func3(a,b);



   scanf("%d",&x);
   func2(x);



   return 0;
}

void func1()
{int i;
   for (i=1;i<=10;i++){
   printf("learn C\n");
                   }
}


void func2(int x){
    int i;
    for(i=1;i<=x;i++){
     printf("learn C\n");}

}


void func3(int a,int b){
    int i;

    if(b==1){
        for(i=1;i<=a;i++){
            printf("*-");
        }
        }
       else if(b==2){
        for(i=1;i<=a;i++){
        printf("*-\n");
        }
       }
    else {printf("wrong type");}

    }








