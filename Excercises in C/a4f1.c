/*
ics24199

���� ������� ������� �� ���� ��������� ����������� �����
purchaseAmount � ��� �� ������� saleAmount �. �� �� ����
saleAmount ��������� ��� ��� ������ ���� purchaseAmount ��� ��
������� ������� rate ��� ������� ��� ��� ������� �����
purchaseAmount, �� ����� ��������� ��� �� ���������� ��� �� ���������:
�) �� ������ ��� ������� profit (double), �) �� ���������� ���� saleAmount (double).
�� �������� ������� �� ����� �� �����:
purchaseAmount (��������� ����� long)
rate (��������� ����� int, ��� �� ������� ������� ����� 10% ���� �������������� 10)

A merchant bought at a wholesale price goods of value
purchaseAmount � and sold them saleAmount �. If the amount
saleAmount is derived from net purchaseAmount and the
merchant's rate of profit on net worth
purchaseAmount, be a program that calculates and displays:
a) the trader's profit profit (double), b) the amount collected saleAmount (double).
The input data should be in the form:
purchaseAmount (variable of type long)
rate (variable of type int, if the profit rate is 10% then we type 10)
*/


#include <stdio.h>
int main(){
long purchaseamount;
int rate;
double profit;
double saleamount;

printf("dose kathari axia:");
scanf("%ld",&purchaseamount);
printf("dose pososto kerdous:");
scanf("%d",&rate);

//profit=purchaseamount*(rate/100);
//allos tropos;
profit=purchaseamount*((double)rate/100);
saleamount=purchaseamount+profit;

printf("kerdos: %g\n",profit);
printf("synoliko poso: %g\n", saleamount);

return 0;
}
