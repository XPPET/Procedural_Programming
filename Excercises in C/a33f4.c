/*
ics24199



*/

#include <stdio.h>

float culc(float a, float b , float c);//return avg

int main(){
float a,b,c,y;

printf("Enter a:");
scanf("%f",&a);

printf("Enter b:");
scanf("%f",&b);

printf("Enter c:");
scanf("%f",&c);
y= culc( a,  b , c);
if (y!=-1.0){
        printf("Avg=%.2f",y);
}
else{printf("no value [1,2]");
}
return 0;}











float culc(float a, float b , float c){
    float avg;

    if (a<1||a>2){
            if(b<1||b>2){
                if(c<1||c>2){
                    return -1.0;
                }}}


   return avg=(a+b+c)/3.0;

   }




