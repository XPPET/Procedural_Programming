/*
ics24199

b. ���������� �� ��������� ��� �rithmo_�ytok (long) ����������,
��� ���������� �� ������ ����� Rythmos ��� ��������� ��� ������� ���� �rio (long),
�������� �� ����� �� ������� � �������.

�� ��������� �� ��������� �� ��� (long) ��� ��� ������ ��� ����������� (long) ���� �� ��������� �� ������� ����.
��� ��� ���������� ��� ������� ������� ����������� �� �������������� � �����:
������� ����������� = ceil(������� ����������� *(1+������ �������))


b. Generalize the program for �rithmo_�ytok (long) cars,
which grow at an annual rate of Rythmos and exceed a given limit �rio (long),
data to be entered by the user.

The program should display the years (long) and the number of cars (long) when it exceeds the given limit.
To calculate the annual number of cars, use the formula:
Number of cars = ceil(Number of cars *(1+Rate of growth))

*/

#include <stdio.h>
#include <math.h>

int main() {
    long initialCars;
    double growthRate;
    long limit;
    long years = 0;

    printf("dwse ton arxiko arithmo aytokinitwn: ");
    scanf("%ld", &initialCars);
    printf("dwse ton etysio rythmo auxishs ");
    scanf("%lf", &growthRate);
    printf("dwse to orio: ");
    scanf("%ld", &limit);

    while (initialCars <= limit) {
        initialCars = ceil(initialCars * (1 + growthRate));
        years++;
    }

    printf("xronia: %ld\n", years);
    printf("arithmos aytokinitwn: %ld\n", initialCars);

    return 0;
}
