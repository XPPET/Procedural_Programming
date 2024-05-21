#include <stdio.h>
float CalculatingMaxValues (float max, int row, float price[]);
void FindingInterestingValues (float max, int row, float price[], float interesting[]);
void Printing(int size);
void PrintingPrice(float max, int row, float price[]);
void PrintingInterestingPrice(int ni, float interesting[]);




int main(){

float stock_prices[10] = {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
float deriv_prices[5] = {30.5, 21.4, 89.8, 20.1, 10.0};
float cds_prices[11] = {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1 ,30.4};
int risk[11] = {90,10,20,30,50,60,30,30,30,10,10};
float deriv_day_data[5][10] = {
                {30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
                {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
                {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
                {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
                {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}};

float interesting_stock[10];
int ni_stock;
float interesting_cds[11];
int ni_cds;
int i;
float max_stock, max_deriv, max_cds, EvaluationPrice;

/*----------------------------------------------------------------------------------------*/
/* Calculating Max Values */
max_stock=CalculatingMaxValues (max_stock, 10, stock_prices);
max_deriv=CalculatingMaxValues (max_deriv, 5, deriv_prices);
max_cds=CalculatingMaxValues (max_cds, 11, cds_prices);
/*----------------------------------------------------------------------------------------*/
/* Finding Interesting Values */
FindingInterestingValues (max_stock, 10, stock_prices, interesting_stock);
FindingInterestingValues (max_cds, 11, cds_prices, interesting_cds);
/*----------------------------------------------------------------------------------------*/
/* Printing */
printf("Stock Prices.\n");
Printing(30);
PrintingPrice(max_stock, 10, stock_prices);
printf("Interesting Stock Prices:");
PrintingInterestingPrice(10, interesting_stock);
Printing(10);
/* Derivatives */
printf("Derivative Prices.\n");
Printing(30);
PrintingPrice(max_deriv, 5, deriv_prices);
Printing(10);
/* Cds Prices */
printf("CDS Prices.\n");
Printing(30);
PrintingPrice(CalculatingMaxValues (max_cds, 11, cds_prices), 10, cds_prices);
printf("Interesting CDS Prices:");
PrintingInterestingPrice(10, interesting_cds);
Printing(10);
/*----------------------------------------------------------------------------------------*/

for(i=0; i<11; i++)
{
    if (cds_prices[i]<20  && risk[i]<50)
    {
      EvaluationPrice = 20;
    }
    else if (cds_prices[i]>=20  && risk[i]<80)
    {
      EvaluationPrice =  10 + (cds_prices[i] * risk[i])/100;
    }
    else
    {
       EvaluationPrice = 100 + (cds_prices[i] * risk[i])/100;
    }
    printf("CDS Assessment: cds %.2f Risk %d Value %.2f\n", cds_prices[i], risk[i] ,EvaluationPrice);
}
/*----------------------------------------------------------------------------------------*/

//---askhsh3----
printf("----------------------\nDerivative Low High\n");
    for (int i = 0; i < 5; i++) {
        int above_close, below_close;
        high_low(deriv_day_data, i, &above_close, &below_close);
        printf("Devirative %d, high %d / low %d values\n", i, above_close, below_close);
    }




return 0;
}

float CalculatingMaxValues (float max, int row, float price[])
{
    int i;
    max = price[0];
    for(i=1;i<11;i++)
     if (price[i] > max) {max = price[i];}
     return max;
}

void FindingInterestingValues (float max, int row, float price[], float interesting[])
{
    int i;
    int ni=0;
    for(i=0;i<10;i++)
      if (price[i] > max/ 2)
          {interesting[ni++] = price[i];}
}

void PrintingPrice(float max, int row, float price[])
{
    int i;
   printf("Max Price:: %4.2f \n",max);
    for(i=0;i<row;i++)
      printf("%s(%3.2f) ",(max == price[i] ? "-Max-" : ""),price[i]);
   printf("\n");


}

void PrintingInterestingPrice(int ni, float interesting[])
{
    int i;
    for(i=0; i<ni; i++)
    printf("[%4.2f] ",interesting[i]);
   printf("\n");

}

void Printing(int size)
{
    int i;
    for(i=0;i<size;i++) printf("-");
   printf("\n");
}

//..........................;  higjt_low




#include <stdio.h>


void high_low(int deriv_day_data[5][10], int derivative_index, int *above_close, int *below_close) {
    // Η τιμή κλεισίματος βρίσκεται στην τελευταία θέση (index 9)
    int closing_price = deriv_day_data[derivative_index][9];


    *above_close = 0;
    *below_close = 0;

    // Εξέταση των τιμών κατά τη διάρκεια της ημέρας
    for (int i = 0; i < 9; i++) {
        if (deriv_day_data[derivative_index][i] > closing_price) {
            (*above_close)++;
        } else if (deriv_day_data[derivative_index][i] < closing_price) {
            (*below_close)++;
        }
    }
}



