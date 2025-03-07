/*
ics24199

�� ������� ��������� ��� �� �������� ��� ������ ��� ��� ���� ���� �������� ������� ��������� ���
������� ������� �� ��� �������������. � ������� �� ������ �� ����� ��� �������� [0..2000] ��� ��
������� � ����������� ������� ��� �� ���������. � ������� ��� ��������� (������� ��� ����) ��
����������� ����� �� ����� �� ������� �� ����� (����� ���������� ���������).
�������
���� ������� ��� ��������� ������� �� ���� ������ ������� ������� �� ��� ������ ���, �� ����:

������� ���������      ������� ��������
1..300                        5%
301..500                     10%
501..1000                    15%
1001..2000                   20%

����������� ������:
��� ���� ������ �������� ������� ������, ���� ������� � ������� ����������� �� ������� ����. ������������,
��� ���� ������ �������:
� ���� ������ ���������� ��� ��� ���� ��� ���
� �������� ��� �� �������� �� ������ ��� 1000 ��� ��� 1500 ���� ������ ��� ���� 5 ���� ��� �������
����� ��� ���������. (������ ��� ����� ��� ��������� ���� ��� �������).�� �������� ������
������������� ��� ��� ����
��������_������ = ceil(������ ����/5)
��� ����������:
��� ��� ������ �� ������ 1200 ��� ���� 100�:
� � ������ ���� �� �����: 80�
� �� ���� ��� ��������: 20�
� �� ������: 17
��� ��� ������ �� ������ 100 ��� ���� 10�:
� � ������ ���� �� �����: 9.50�
� �� ���� ��� ��������: 0.50�
� �� ������: 1
�� ��������� �� ��������� ���� ����� �� ��������:
� �� ������ ������ ��� �� �������� � ������� (���� ��� �������) (�� 2 �������� �����)
� �� �������� ���� �������� (�� 2 �������� �����)
� �� ������ ��� ������
���������� ��������� ��� ������������:

Dwse ton kwdiko: 2005
Lathos Kwdikos (0-2000)
Dwse ton kwdiko: 1200
Dwse thn timh: 100
Dwse ton kwdiko: 231
Dwse thn timh: 10
Dwse ton kwdiko: 0
------------------
Teliko synolo: 89.50 Euro
Ekptwsh: 20.50 Euro
Pontoi: 18








Write a program that reads the code and price of an unknown number of products that someone
bought at a supermarket. The code should be in the range [0..2000], and the program should perform
the corresponding check. Data input (code and price) will continue until zero is entered as the code (see execution example).

Discount:
During the discount period, a discount is applied to each product according to its code, as follows:

Product Code Discount     Percentage
1..300                        5%
301..500                     10%
501..1000                    15%
1001..2000                   20%

Points Calculation:
For each product, some points are awarded, which the customer can redeem for various gifts. Specifically, for each product:

� one point is awarded regardless of its price, and
� additionally, for products with codes from 1000 to 1500, one point is awarded for every 5 Euros of the final value of the product.
(i.e., the value after the discount). Additional points are calculated by the formula:
additional_points = ceil(final_value/5)

For example:
For a product with code 1200 and price 100�:
� the final price will be: 80�
� the discount amount: 20�
� points: 17
For a product with code 100 and price 10�:
� the final price will be: 9.50�
� the discount amount: 0.50�
� points: 1

The program will display the following on the screen:
� the total amount the customer will pay (after the discount) (with 2 decimal places)
� the total discount amount (with 2 decimal places)
� the total points

Example execution of the program:
Enter the code: 2005
Incorrect Code (0-2000)
Enter the code: 1200
Enter the price: 100
Enter the code: 231
Enter the price: 10
Enter the code: 0

Total Amount: 89.50 Euros
Discount: 20.50 Euros
Points: 18


*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

double discount_percentage(int code);
int product_points(int code, double price);
int get_code();

int main()
{
    int code, points;
    double price, total, discountSum, final_price, discount;

    total=discountSum=0;
    points=0;
    while(code=get_code())
    {
        printf("Dwse thn timh: ");
        scanf("%lf",&price);
        discount=discount_percentage(code)*price;
        discountSum+=discount;
        final_price=price-discount;
        total+=final_price;
        points+= product_points(code, final_price);
    }
    printf("------------------------\n");
    printf("Teliko synolo: %.2f Euro \n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);
    return 0;
}
int get_code()
{
    int code;
    while (true)
    {
       printf("Dwse ton kwdiko: ");
       scanf("%d",&code);
       if(code>=0 && code<=2000)
       {
           return code;
       }
           printf("Lathos kwdikos (0-2000)\n");
    }
}
double discount_percentage(int code)
{
    if(code<=300)
    {
        return 0.05;
    }
    else if (code<=500)
    {
        return 0.1;
    }
    else if (code<=1000)
    {
        return 0.15;
    }
    else
    {
        return 0.2;
    }
}
int product_points(int code, double fprice)
{
    if (code>=1000 && code<=1500)
    {
        return 1+ceil(fprice/5);
    }
        return 1;
}
