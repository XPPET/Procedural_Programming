#include <stdio.h>

#define MAX_APARTMENTS 20

// Δομή για τις μηνιαίες δαπάνες
struct MonthlyData {
    float heatingExpenses;
    float commonExpenses;
};

// Δομή για τα στοιχεία κάθε ενοίκου
struct Apartment {
    int number;
    char name[25];
    int squareMeters;
    int heaters;
};

// Δομή για τα συνολικά ποσά
struct TotalAmounts {
    float totalHeating;
    float totalCommon;
    float totalSquareMeters;
};

// Συνάρτηση για το διάβασμα του πλήθους των διαμερισμάτων
int ReadNumApparts() {
    int numApartments;
    printf("Dwse to plh8os twn diamerismatwn: ");
    scanf("%d", &numApartments);
    return numApartments;
}

// Συνάρτηση για το διάβασμα των μηνιαίων δαπανών
struct MonthlyData ReadMonthData() {
    struct MonthlyData data;
    printf("Dwse to mhniaio poso thermansis: ");
    scanf("%f", &data.heatingExpenses);
    printf("Dwse to mhniaio poso koinoxrhstwn: ");
    scanf("%f", &data.commonExpenses);
    return data;
}

// Συνάρτηση για το διάβασμα των στοιχείων κάθε διαμερίσματος
void ReadEnoikoiData(struct Apartment apartments[], int numApartments) {
    for (int i = 0; i < numApartments; ++i) {
        apartments[i].number = i + 1;  // Αυτόματη αύξηση αριθμού διαμερίσματος
        printf("Dwse onomatepwnymo: ");
        scanf("%s", apartments[i].name);
        printf("Dwse t.m: ");
        scanf("%d", &apartments[i].squareMeters);
        printf("Dwse fetes: ");
        scanf("%d", &apartments[i].heaters);
    }
}

// Συνάρτηση για τους υπολογισμούς
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

// Συνάρτηση για την εμφάνιση της αναλυτικής κατάστασης πληρωμής
void DisplayPaymentStatus() {
    printf("\n%-3s %-25s %-4s %-6s %-10s %-10s %-10s\n",
           "Α/Α", "ONOMATEPWNYMO", "Τ.Μ.", "FΕΤΕS", "PΟSΟ THERΜ.", "PΟPΟ ΚΟΙΝ.", "SΥΝΟLΟ");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

    // Εδώ θα χρειαστεί να καλέσετε την συνάρτηση Calculations και να εμφανίσετε τα αποτελέσματα

    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("SΥΝΟLΑ: %-10.2f %-10.2f %-10.2f\n", 0.0, 0.0, 0.0);
}

int main() {
    int numApartments;
    struct MonthlyData monthlyData;
    struct Apartment apartments[MAX_APARTMENTS];

    // Διάβασμα πλήθους διαμερισμάτων
  numApartments = ReadNumApparts();

    // Διάβασμα μηνιαίων δαπανών
    monthlyData = ReadMonthData();

    // Διάβασμα στοιχείων κάθε διαμερίσματος
    ReadEnoikoiData(apartments, numApartments);

    // Υπολογισμοί και εμφάνιση αναλυτικής κατάστασης πληρωμής
    DisplayPaymentStatus();

    return 0;
}
