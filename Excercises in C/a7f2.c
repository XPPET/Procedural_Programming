/*
ics24199

�� ������ ��� ��������� C ��� ��� ���������� ��� ��� �������� ��� ������������ ������� ����
����������� �� ����: �� ��������� �� �������� ��� ������ ������ (long) ��� �����������.
�� � ������� ������� ����� ����������� � ���� ��� 1000, ���� �� ��������� �� �������� ��� ������
����� ��� ����������� (double) ��� �� ���������� ��� ����������� ������ (double) ��� ����������
��� ������ ����� ��� 52.
�� � ������� ����� ���������� ��� 1000, ���� �� ��������� �� �������� ��� ���� ������������
�������� (int) ��� �����������, ��� ������ ��� ��� (double) ��� ��� �������� �� ���������� ���
����������� ������. �� � �����������
������� ����� ��� ��� 40 ����, ���� ��� ���
���� ���� ��� 40 ���� � ������ ����
���������� 50%.

Write a C program to calculate and display the weekly pay of a
employee as follows: The program will read the code number (long) of the employee.
If the code number is greater than or equal to 1000, then the program will read the annual
employee's salary (double) and will calculate his weekly pay (double) by dividing
the annual salary by 52.
If the code is less than 1000, then the program will read the weekly hours
work (int) of the employee, the pay per hour (double) and then it will calculate it
weekly pay. If the weekly
work is more than 40 hours, then for the
hours beyond 40 hours the pay has
50% surcharge.
*/


#include <stdio.h>

int main()
{

long code;
double salary;
double hourly_pay;
int working_hours;
double wage;

printf("dwse ton kvdiko");
scanf("%ld",&code);

if (code>=1000)
{

    printf("dwse ton mistho");
    scanf("%lf",&salary );
    wage=salary/52;
}
else
{
    printf("dwse tis wres ebdomadiaias ergasias:");
    scanf("%d",&working_hours);

     printf("dwse tin amoibi ana wra:");
    scanf("%lf",&hourly_pay);

         if(working_hours<=40)
         {

           wage=working_hours*hourly_pay;

         }

               else
               {
                  wage=40*hourly_pay+(working_hours-40)*hourly_pay*1.5;
               }

}
printf("h ebdomadiaia amoibi einai: %g\n", wage);
return 0;

}
