/*
ics24199

�� ������ ��������� ��� �� ���������� ��� �� ��������� �� ���� (int) ���� ������� ���� ������� ��� ���
�������� ���� :
� = (1.12� + 65)1.2 + 7.0
���� � ����� �� ����� ��� �� kgr (int) ��� �� ���� (int) ��� ������������ �� cm.
��������: ��� �� ��������������� �������� �� ��������������� �� ��������� ceil ��� �����������
math.

Write a program that will calculate and display the height (int) of a child when given by
following formula:
Y = (1.12B + 65)1.2 + 7.0
where B is his weight in kgr (int) and his height (int) is calculated in cm.
Hint: for rounding you can use the ceil function of the library
math.

*/


#include <stdio.h>
#include <math.h>


int main()
{
int baros;
int height;

printf("dose to baros:");
scanf("%d",&baros);

//typos;
height=((1.12*baros+65)*1.2+7.0);

printf("to ypsos einai : %d\n",height);

return 0;

}
