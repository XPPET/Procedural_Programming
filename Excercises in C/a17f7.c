#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ConvertToUpper(char *name, char *surname, char *fullname, char *upperFullname) {
    sprintf(fullname, "%s %s", name, surname);

    for (int i = 0; fullname[i] != '\0'; i++) {
        upperFullname[i] = toupper(fullname[i]);
    }
}

int main() {
    char name[50], surname[50], fullname[100], upperFullname[100];

    printf("Enter onoma: ");
    scanf("%s", name);

    printf("Enter eponymo: ");
    scanf("%s", surname);

    ConvertToUpper(name, surname, fullname, upperFullname);

    printf("Onoma = %s, %lu\n", name, strlen(name));
    printf("Eponymo = %s, %lu\n", surname, strlen(surname));
    printf("Onomateponymo = %s, %lu\n", fullname, strlen(fullname));
    printf("Upper Onomateponymo = %s, %lu\n", upperFullname, strlen(upperFullname));

    return 0;
}
