/*
ics24199

�� ������ ��������� �� ����� �� ��������� ����� ���� �������� (int) ��� �� 1 ����� �� 100.
�� ������� �� ������������ ��� ������� �� ���� ������ ��� ������. � ����� ������, �.�., ��� �� 1 ����� �� 10,
� ������� ��� �� 11 ����� �� 20 �.�.�. �� �������� ���� ������� ����� ���������� ��� ����� ��� 4 ����������.

Write a program that displays all the numbers (int) from 1 to 100.
The numbers are displayed in tens on each line of the screen.
The first line, for example, from 1 to 10, the second from 11 to 20 and so on.
Each line's data is right-aligned by 4 characters.
*/


#include <stdio.h>

int main() {
    int start = 1;
    int end = 10;

    while (start <= 100) {
        for (int i = start; i <= end; i++) {
            printf("%4d ", i);
        }
        printf("\n");
        start += 10;
        end += 10;
    }

    return 0;
}

