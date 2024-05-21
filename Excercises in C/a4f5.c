#include <stdio.h>
#include <math.h>

int main(){
    int proion1=25000,proion2=15000,proion3=32000,proion4=21000,proion5=9200;
    int A[4][5]={{10,4,5,6,7},{7,0,12,1,3},{4,9,5,0,8},{3,2,1,5,6}};
    int B[4];
    int i,j;
    long eipraxeis;
    double promhtheia;
    int posothta;

printf("EISPRAXEIS: ");

for (i=0;i<4;i++){
        eipraxeis=0;
    for (j=0;j<5;j++){
        if(j==0){eipraxeis=eipraxeis+A[i][j]*proion1;}
        else if(j==1){eipraxeis=eipraxeis+A[i][j]*proion2;}
         else if (j==2){eipraxeis=eipraxeis+A[i][j]*proion3;}
          else if(j==3){eipraxeis=eipraxeis+A[i][j]*proion4;}
           else {eipraxeis=eipraxeis+A[i][j]*proion5;}
    }

  printf("%ld ",eipraxeis);
  B[i]=eipraxeis;

}

printf("\nPROMHTEIES: ");
 for(i=0;i<4;i++){
    promhtheia=B[i]*10/100;
    printf("%.2lf ",promhtheia);
 }


 printf("\nPOSOTHTES: ");
for (j=0;j<5;j++){
        posothta=0;
    for(i=0;i<4;i++){
        posothta=posothta+A[i][j];
    }
    printf("%d ",posothta);
}






return 0;}
