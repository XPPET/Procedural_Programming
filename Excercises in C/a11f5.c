#include <stdio.h>
#include <math.h>
#define city 10
#define s 3

int main(){

int i,k;
double temp[city][s];
double average[city],natavg,devnat[city][s],mdev[city];

natavg=0;
for (k=0; k<city; k++)
{
    for( i=0; i<s; i++)
    {
        printf("Temp of City %d During %d 8-hour period:",k,i);
        scanf("%lf", &temp[k][i]);
        average[k]+=temp[k][i];
    }
    natavg+=average[k];
}
natavg/=(city*s);
//megisth apoklish
for (k=0; k<city; k++)
{
    for( i=0; i<s; i++)
    {
        devnat[k][i]=fabs(temp[k][i]-natavg);
    }
}


for (k=0; k<city; k++)
{
    mdev[k]=devnat[k][0];
    for( i=0; i<s; i++)
    {
        if(devnat[k][i]>mdev[k])
        {
            mdev[k]=devnat[k][i];
        }
    }
}

printf("Ethnikos mesos oros %.1lf\n",natavg);
for (k=0; k<city; k++)
{
    printf("City %d %.1lf %.1lf\n",k,(average[k]/s),mdev[k]);
}
return 0;
}

