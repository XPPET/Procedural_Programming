#include <stdio.h>

int main(){

int A[10][3], i,j,sum;
int apotyxontes=0,epityxontes=0;
long posoapo,posoepi,MO;



for(i=0;i<10;i++){
        printf("Mathitis %d\n",i+1);

for(j=0;j<3;j++){

  printf("Mathima %d:",j+1);
  scanf("%d",&A[i][j]);

   }

 }


for(i=0;i<10;i++){
       sum=0;

for(j=0;j<3;j++){

 sum=sum+A[i][j];

   }
MO=sum/3;
if(MO<9.5){apotyxontes=apotyxontes+1;}
 else if(MO>18.5){epityxontes=epityxontes+1;}
 }


posoapo=apotyxontes/10.0*100.0;
posoepi=epityxontes/10.0*100.0;

printf("APOTYXONTES: %d %.2lli%% \n", apotyxontes,posoapo);
printf("ARISTOUXOI: %d %.2lli%%", epityxontes,posoepi);



return 0;}
