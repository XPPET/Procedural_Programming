#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *file;
    char filename[] = "i5f9.dat";
    char ch;
    int lines = 0, words = 0, characters = 0;
    bool inWord = false;

    // ’νοιγμα του αρχείου για ανάγνωση
    file = fopen(filename, "r");

    // Έλεγχος αν το αρχείο υπάρχει
    if (file == NULL) {
        printf("Fail to open %s.\n", filename);
        return 1;
    }

    // Υπολογισμός γραμμών, λέξεων και χαρακτήρων
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        // Έλεγχος αν βρισκόμαστε εντός λέξης
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            inWord = false;
        } else {
            // Αν δεν είμαστε ήδη σε λέξη, αυξάνουμε τον μετρητή λέξεων
            if (!inWord) {
                inWord = true;
                words++;
            }
        }
    }

    // Κλείσιμο του αρχείου
    fclose(file);

    // Εκτύπωση των αποτελεσμάτων
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}
