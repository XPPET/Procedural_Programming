/*
ics24199

�� ������ ��������� ��� �������� ��� ������ ��������� (long) ��� ������� ��� ���������� �� �������
���������� ��� ���������� ��� ���� ���
��� �������� ���������� �� ��������� ��
�������� ������ ��������� (double).
�� ����������� ���� ���� ��������� ��� �� ��������� ��� �� ��������� ����� ���������� 0.30 ��� 0.80 �

Write a program that reads the number of letters (long) that a company sends to customers
internal and external which has and
then calculates and displays it
total shipping cost (double).
The postal fees of each letter for domestic and foreign are respectively 0.30 and 0.80 �

*/


#include <stdio.h>

int main()
//a8f1;
{
long arithmosapostolonex;
long arithmosapostolones;
double kostos;

printf("Dwse ton arithmo epistolwn eswterikou:");
scanf("%ld", &arithmosapostolones);

printf("Dwse ton arithmo epistolwn exwterikou:");
scanf("%ld", &arithmosapostolonex);

kostos=(arithmosapostolones*0.30)+(arithmosapostolonex*0.80);
printf("to synoliko kostos apostolis einai:");
printf("%g",kostos);

return 0;
}
