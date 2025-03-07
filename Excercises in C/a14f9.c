#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 70
#define MAX_ACTOR_LENGTH 50

// ���� ��� ��� ������������ ��� �������
struct Movie {
    char title[MAX_TITLE_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    long views;
};

void readInput(const char *filename, struct Movie *movies, int *numMovies) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("�������� ���������� ��� ������� %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    *numMovies = 0;

    while (fscanf(file, "%69[^,],%49[^,],%ld\n", movies[*numMovies].title, movies[*numMovies].actor, &movies[*numMovies].views) == 3) {
        (*numMovies)++;
    }

    fclose(file);
}

void findNewMovies(struct Movie *januaryMovies, int numJanuaryMovies, struct Movie *decemberMovies, int numDecemberMovies, struct Movie *newMovies, int *numNewMovies) {
    *numNewMovies = 0;

    for (int i = 0; i < numJanuaryMovies; i++) {
        int j;
        for (j = 0; j < numDecemberMovies; j++) {
            if (strcmp(januaryMovies[i].title, decemberMovies[j].title) == 0) {
                break;
            }
        }

        // �� �� ������� � ������ ���� ������ ��� ����������, ��������� ��� ��� ������
        if (j == numDecemberMovies) {
            newMovies[*numNewMovies] = januaryMovies[i];
            (*numNewMovies)++;
        }
    }
}


void writeOutput(const char *filename, struct Movie *newMovies, int numNewMovies) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("�������� ����������� ��� ������� %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numNewMovies; i++) {
        fprintf(file, "%s, %s, %ld\n", newMovies[i].title, newMovies[i].actor, newMovies[i].views);
    }

    fclose(file);
}

int main() {
    struct Movie januaryMovies[100];  // ���������� ��� �������� �� ���� 100 �������
    int numJanuaryMovies;

    struct Movie decemberMovies[100];
    int numDecemberMovies;

    struct Movie newMovies[100];
    int numNewMovies;

    // �������� ��� ������� ��� ���������� 2019
    readInput("moviesJan2019.txt", januaryMovies, &numJanuaryMovies);

    // �������� ��� ������� ��� ���������� 2018
    readInput("moviesDec2018.txt", decemberMovies, &numDecemberMovies);

    // ������ ��� ���������� ��� ���� ������� ��� ���������� 2019
    findNewMovies(januaryMovies, numJanuaryMovies, decemberMovies, numDecemberMovies, newMovies, &numNewMovies);

    // ������� ��� ���� ������� �� ��� ������
    writeOutput("newMovies.txt", newMovies, numNewMovies);

    return 0;
}


