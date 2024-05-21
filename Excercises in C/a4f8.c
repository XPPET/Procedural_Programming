#include <stdio.h>

#define MAX_SHIPMENTS 20


struct Shipment {
    char fullName[26];
    char recipientAddress[26];
    int postalCode;
    char city[16];
    char country[16];
    int packageType;
    int weight;
};


//---------------------------------------

void readShipments(struct Shipment shipments[], int M);
void calculateAndDisplayStats(struct Shipment shipments[], int M);

//---------------------------------------



int main() {
    int M;
    struct Shipment shipments[MAX_SHIPMENTS];
    printf("Dwse to plhthos twn dematwn: ");
    scanf("%d", &M);


    readShipments(shipments, M);


    calculateAndDisplayStats(shipments, M);

    return 0;
}


void readShipments(struct Shipment shipments[], int M) {
    for (int i = 0; i < M; ++i) {

        printf("Name: ");
        scanf("%s", shipments[i].fullName);
        printf("Address: ");
        scanf("%s", shipments[i].recipientAddress);
        printf("Zip: ");
        scanf("%d", &shipments[i].postalCode);

        printf("City: ");
        scanf("%s", shipments[i].city);
        printf("Country: ");
        scanf("%s", shipments[i].country);
        printf("Type: ");
        scanf("%d", &shipments[i].packageType);
        printf("Weight: ");
        scanf("%d", &shipments[i].weight);
    }
}


void calculateAndDisplayStats(struct Shipment shipments[], int M) {
    int internalCount = 0;
    int externalCount = 0;
    float totalCost = 0.0;

    for (int i = 0; i < M; ++i) {
        if (shipments[i].packageType == 1) {

            internalCount++;
            totalCost += shipments[i].weight * 0.40;
        } else if (shipments[i].packageType == 2) {

            externalCount++;
            totalCost += shipments[i].weight * 0.84;
        }
    }



    printf("\nStatistika:\n");
    printf("Esoterikou: %d %.2f\n", internalCount, internalCount * 0.40);
    printf("Exoterikou: %d %.2f\n", externalCount, externalCount * 0.84);
}

