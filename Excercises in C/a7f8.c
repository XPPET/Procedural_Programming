#include <stdio.h>
#include <string.h>

#define N 20

typedef struct {
    int no;
    char brand[20];
    int cc;
    char name[20];
    int rent_days;
    float price_per_day;
    float total_price;
} car;

typedef struct {
    char brand[20];
    int cc;
    float total_price;
} bestcar;

void insert_rent_data(car cars[], int rentn);
void print_rent_data(car cars[], int rents);
void separator(int n);
bestcar findbest_car(car cars[], int rent);

int main() {
    int rentn;
    bestcar bc;
    car cars[N];

    printf("Dose ton arithmo ton enoikiaseon: ");
    scanf("%d", &rentn);

    while (getchar() != '\n');

    insert_rent_data(cars, rentn);
    print_rent_data(cars, rentn);
    bc = findbest_car(cars, rentn);
    printf("Best car %s rented for %.2f Euros\n", bc.brand, bc.total_price);

    return 0;
}

void insert_rent_data(car cars[], int rentn) {
    int i;

    for (i = 0; i < rentn; i++) {
        printf("\nDose ta stoixeia tis enoikiasis %d:\n", i + 1);
        cars[i].no = i + 1;

        printf("Dose marka: ");
        gets(cars[i].brand);

        printf("Dose kyvika: ");
        scanf("%d", &cars[i].cc);
        while (getchar() != '\n');

        printf("Dose onoma pelati: ");
        gets(cars[i].name);

        printf("Dose imeres enoikiasis: ");
        scanf("%d", &cars[i].rent_days);
        while (getchar() != '\n');

        printf("Dose imeres enoikiasis: ");
        scanf("%f", &cars[i].price_per_day);
        while (getchar() != '\n');

        cars[i].total_price = cars[i].rent_days * cars[i].price_per_day;
    }
}

void print_rent_data(car cars[], int rents) {
    int i;
    float total = 0.0;
    printf("%-10s %-20s %-20s %-10s %-5s %-10s %-10s\n", "Number", "Name", "Type", "CC", "Days", "Price", "Total");
    separator(90);

    for (i = 0; i < rents; i++) {
        printf("%-10d %-20s %-20s %-10d %-5d %-10.2f %-10.2f\n", cars[i].no, cars[i].name, cars[i].brand, cars[i].cc,
               cars[i].rent_days, cars[i].price_per_day, cars[i].total_price);

        total += cars[i].total_price;
    }

    separator(90);
    printf("%75s %11.2f\n", "Total", total);
}

void separator(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

bestcar findbest_car(car cars[], int rent) {
    float maxprice;
    bestcar bc;
    int i;

    maxprice = cars[0].total_price;
    strcpy(bc.brand, cars[0].brand);
    bc.cc = cars[0].cc;
    bc.total_price = cars[0].total_price;

    for (i = 1; i < rent; i++) {
        if (cars[i].total_price > maxprice) {
            maxprice = cars[i].total_price;
            strcpy(bc.brand, cars[i].brand);
            bc.cc = cars[i].cc;
            bc.total_price = cars[i].total_price;
        }
    }

    return bc;
}
