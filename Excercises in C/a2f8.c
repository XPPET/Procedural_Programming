#include <stdio.h>

#define MAX_APARTMENTS 20

// ���� ��� ��� �������� �������
struct MonthlyData {
    float heatingExpenses;
    float commonExpenses;
};

// ���� ��� �� �������� ���� �������
struct Apartment {
    int number;
    char name[25];
    int squareMeters;
    int heaters;
};

// ���� ��� �� �������� ����
struct TotalAmounts {
    float totalHeating;
    float totalCommon;
    float totalSquareMeters;
};

// ��������� ��� �� �������� ��� ������� ��� �������������
int ReadNumApparts() {
    int numApartments;
    printf("Dwse to plh8os twn diamerismatwn: ");
    scanf("%d", &numApartments);
    return numApartments;
}

// ��������� ��� �� �������� ��� �������� �������
struct MonthlyData ReadMonthData() {
    struct MonthlyData data;
    printf("Dwse to mhniaio poso thermansis: ");
    scanf("%f", &data.heatingExpenses);
    printf("Dwse to mhniaio poso koinoxrhstwn: ");
    scanf("%f", &data.commonExpenses);
    return data;
}

// ��������� ��� �� �������� ��� ��������� ���� �������������
void ReadEnoikoiData(struct Apartment apartments[], int numApartments) {
    for (int i = 0; i < numApartments; ++i) {
        apartments[i].number = i + 1;  // �������� ������ ������� �������������
        printf("Dwse onomatepwnymo: ");
        scanf("%s", apartments[i].name);
        printf("Dwse t.m: ");
        scanf("%d", &apartments[i].squareMeters);
        printf("Dwse fetes: ");
        scanf("%d", &apartments[i].heaters);
    }
}

// ��������� ��� ���� ������������
struct TotalAmounts Calculations(struct Apartment apartments[], int numApartments, struct MonthlyData monthlyData) {
    struct TotalAmounts totals = {0};

    for (int i = 0; i < numApartments; ++i) {
        float heatingPerApartment = (float)apartments[i].heaters / totals.totalHeating * monthlyData.heatingExpenses;
        float commonPerApartment = (float)apartments[i].squareMeters / totals.totalSquareMeters * monthlyData.commonExpenses;

        printf("%-3d %-25s %-4d %-6d %-10.2f %-10.2f %-10.2f\n",
               apartments[i].number, apartments[i].name, apartments[i].squareMeters,
               apartments[i].heaters, heatingPerApartment, commonPerApartment, heatingPerApartment + commonPerApartment);

        totals.totalHeating += heatingPerApartment;
        totals.totalCommon += commonPerApartment;
        totals.totalSquareMeters += apartments[i].squareMeters;
    }

    return totals;
}

// ��������� ��� ��� �������� ��� ���������� ���������� ��������
void DisplayPaymentStatus() {
    printf("\n%-3s %-25s %-4s %-6s %-10s %-10s %-10s\n",
           "�/�", "ONOMATEPWNYMO", "�.�.", "F���S", "P�S� THER�.", "P�P� ����.", "S���L�");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

    // ��� �� ��������� �� �������� ��� ��������� Calculations ��� �� ���������� �� ������������

    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("S���L�: %-10.2f %-10.2f %-10.2f\n", 0.0, 0.0, 0.0);
}

int main() {
    int numApartments;
    struct MonthlyData monthlyData;
    struct Apartment apartments[MAX_APARTMENTS];

    // �������� ������� �������������
  numApartments = ReadNumApparts();

    // �������� �������� �������
    monthlyData = ReadMonthData();

    // �������� ��������� ���� �������������
    ReadEnoikoiData(apartments, numApartments);

    // ����������� ��� �������� ���������� ���������� ��������
    DisplayPaymentStatus();

    return 0;
}
