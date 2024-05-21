#include <stdio.h>
#include <math.h>

#define CTS 10
#define S 3
void ReadData(int row, int col, double temper[][col]);
double CalculateAvegare (int row, int col, double temper[][col]);
void CalculateAvCity(int row, int col, double temper[][col], double average[row]);
void CalculateMaxDeviation(int row, int col, double temper[][col], double natavg, double mdeviation[row]);
void PrintResult(int row, double natavg, double mdeviation[row], double average[row]);

int main()
{
    double temper[CTS][S];/*={5.6,5.8,5.8,
6.9,6.5,6.8,
6.4,6.3,6.2,
6.5,3.2,6.5,
6.3,6.2,3.0,
3.6,3.5,3.0,
9.6,6.9,6.8,
3.2,3.2,3.0,
6.0,6.5,6.5,
6.4,6.4,6.7};*/
    double average[CTS], mdeviation[CTS];
    double natavg;
/*Read all Temperatures*/
ReadData(CTS,S,temper);
/*Calculating The Average of all Cities&Temps*/
natavg=CalculateAvegare(CTS,S,temper);
/*Calculating Average temp on each City*/
CalculateAvCity(CTS,S,temper,average);
/*Calculating Standard Deviation*/
CalculateMaxDeviation(CTS,S,temper,natavg,mdeviation);
/*Printing results*/
PrintResult(CTS,natavg,mdeviation,average);
    return 0;
}

void ReadData(int row, int col, double temper[][col])
{
    int i,j;
    for (i=0; i<row; i++)
		for (j=0; j<col; j++)
		  	{ printf("Temp of City %d During %d 8-hour period: ",i,j);
              scanf("%lf",&temper[i][j]);
              }
}

double CalculateAvegare (int row, int col, double temper[][col])
{
    int i,j;
    double natavg = 0;
    for (i=0; i<row; i++)
      for (j=0; j<col; j+=1)
         natavg += temper[i][j];
         natavg = natavg/(row*col);
    return natavg;
}

void CalculateAvCity(int row, int col, double temper[][col], double average[row])
{
    int i,j;
    for (i=0; i<row; i++)
    {
        average[i] = 0;
        for (j=0; j<col; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/col;
    }

}

void CalculateMaxDeviation(int row, int col, double temper[][col], double natavg, double mdeviation[row])
{
    int i,j;
    double devnat[row][col];
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);

	/*Calculating max Deviation*/
    for (i=0; i<row; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<col; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }
}

void PrintResult(int row, double natavg, double mdeviation[], double average[])
{
    int i;
    printf("%3.1f\n", natavg);
    for (i=0; i<row; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
}
