
#include<stdio.h>
#define product 5
#define seller 4
void calculateSales(int row ,int col,int price[],int sales[][col],int salesPerson[]);
void calculateProductSales(int row, int col, int sales[][col], int productSale[]);
void maxArray(int row, int tab[], int *max, int *pos);
void printArray(int row, int tab[]);

int main(){

int i,j;
int price[product] = {250,150,320,210,920};
int sales[seller][product]={ {10, 4, 5, 6, 7},
                             {7, 0, 12, 1, 3},
                             {4, 19, 5, 0, 8},
                             {3, 2,  1, 5, 6} };
int salesPerson[seller], productSale[product], income, maxp;

calculateSales(seller ,product ,price ,sales ,salesPerson);
calculateProductSales(seller ,product ,sales ,productSale);
/*-------------------------------------------------*/
printf("SalesMan-Sales\n");
printArray(seller, salesPerson);
/*-------------------------------------------------*/
maxArray(seller, salesPerson, &income, &maxp);
printf("Best SalesMan was %d with %d sales \n",maxp,income);
/*-------------------------------------------------*/
printf("Product-Items\n");
printArray(product, productSale);
/*-------------------------------------------------*/
maxArray(product, productSale, &income, &maxp);
printf("Best product was %d with %d items \n",maxp,income);
/*-------------------------------------------------*/
return 0;
}

void calculateSales(int row ,int col ,int price[] ,int sales[][col], int salesPerson[])
{
    int i,j;
    for (i=0; i<row; i++)
    {
        salesPerson[i]=0;
        for(j=0; j<col; j++)
        {
            salesPerson[i]+=sales[i][j]*price[j];
        }
    }
}

void calculateProductSales(int row, int col, int sales[][col], int productSale[])
{
    int i,j;
    for (j=0; j<col; j++)
    {
        productSale[j]=0;
        for(i=0; i<row; i++)
        {
            productSale[j]+=sales[i][j];
        }
    }
}

void maxArray(int row, int tab[], int *max, int *pos)
{
    int i;
    *max=tab[0];
    *pos=0;
    for(i=1; i<row; i++)
    {
        if(tab[i] > *max)
        {
            *max=tab[i];
            *pos=i;
        }
    }
}

void printArray(int row, int tab[])
{
    int i;
    for (i=0; i<row; i++)
    {
        printf("%d\t %d\n",i,tab[i]);
    }
}


