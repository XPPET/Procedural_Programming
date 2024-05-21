#include <stdio.h>

#define SIZE 5

// Συνάρτηση που βρίσκει το μέγιστο βάρος, ύψος και ηλικία
void FindMax(int data[SIZE][4], int column, double *max_boys, double *max_girls) {
    *max_boys = 0.0;
    *max_girls = 0.0;

    for (int i = 0; i < SIZE; i++) {
        if (data[i][0] == 0) { // Αγόρι
            if (data[i][column] > *max_boys) {
                *max_boys = data[i][column];
            }
        } else { // Κορίτσι
            if (data[i][column] > *max_girls) {
                *max_girls = data[i][column];
            }
        }
    }
}

int main() {
    int data[SIZE][4] = {
        {1, 40, 120, 12},
        {0, 45, 110, 13},
        {0, 50, 140, 14},
        {1, 40, 120, 14},
        {1, 45, 135, 15}
    };

    double max_weight_boys, max_weight_girls;
    double max_height_boys, max_height_girls;
    double max_age_boys, max_age_girls;

    FindMax(data, 1, &max_weight_boys, &max_weight_girls); // Βάρος
    FindMax(data, 2, &max_height_boys, &max_height_girls); // Ύψος
    FindMax(data, 3, &max_age_boys, &max_age_girls); // Ηλικία
//-------------------------------------------------------------
    printf("Max weight boy: %.1f\n", max_weight_boys);
    printf("Max weight girl: %.1f\n", max_weight_girls);
    printf("Max height boy: %.1f\n", max_height_boys);
    printf("Max height girl: %.1f\n", max_height_girls);
    printf("Max age boy: %.1f\n", max_age_boys);
    printf("Max age girl: %.1f\n", max_age_girls);

    return 0;
}
//------------------------------------------------------
