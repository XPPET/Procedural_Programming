#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *file;
    char filename[] = "i5f9.dat";
    char ch;
    int lines = 0, words = 0, characters = 0;
    bool inWord = false;

    // ������� ��� ������� ��� ��������
    file = fopen(filename, "r");

    // ������� �� �� ������ �������
    if (file == NULL) {
        printf("Fail to open %s.\n", filename);
        return 1;
    }

    // ����������� �������, ������ ��� ����������
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        // ������� �� ����������� ����� �����
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            inWord = false;
        } else {
            // �� ��� ������� ��� �� ����, ��������� ��� ������� ������
            if (!inWord) {
                inWord = true;
                words++;
            }
        }
    }

    // �������� ��� �������
    fclose(file);

    // �������� ��� �������������
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}
