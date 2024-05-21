#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define M 100

/* Δημιουργία δομών */
typedef struct {
    char name[30];
    int apousies;
    char comments[68];
} studentT;

/* Πρωτότυπα συναρτήσεων */
void readInput(FILE* infile, studentT students[], int *pApontes, int *pStudents);
void writeOutput(FILE* outfile, int size, studentT students[], int total);

int main()
{
/* Δήλωση-αρχικοποίηση μεταβλητών */
    FILE* infile;
    FILE* outfile;

    char inputFileName[30];
    char outputFileName[30];

    studentT students[M];
    int numberOfApousies, numberOfStudents;

/* Είσοδος δεδομένων */
    printf("Dwste onoma gia to arxeio eisodou: ");
    gets(inputFileName);
    printf("Dwste onoma gia to arxeio exodou: ");
    gets(outputFileName);

    infile = fopen(inputFileName, "r");
    if(infile == NULL){
        printf("Cannot open input file %s",inputFileName);
        exit(1);
    }

    outfile = fopen(outputFileName, "w");

    readInput(infile, students, &numberOfApousies, &numberOfStudents);

/* Υπολογισμοί - Έξοδος σε αρχείο */
    writeOutput(outfile, numberOfApousies, students, numberOfStudents);

/* Κλείσιμο αρχείων */
    fclose(infile);
    fclose(outfile);



    return 0;
}


/* Συναρτήσεις */

/* Συνάρτηση ανάγνωσης δεδομένω πηγαίου αρχείου */
void readInput(FILE *infile, studentT students[], int *pApousies, int *pStudents)
{
    char name[30], comments[68], termch;
    int apousies, nscan, line;

    line = 0;
    *pApousies = 0;
    *pStudents = 0;
    while (true){
           nscan = fscanf (infile, "%30[^,], %d, %68[^\n]%c", name, &apousies, comments, &termch); /* Πρέπει να επιστρέψει 4 */
           if (nscan == EOF) break;
           line++;
           if (nscan != 4 || termch !='\n')
           {
               printf ("Error in line %d. Program termination\n", line);
               exit(1);
           }
           if (apousies>100)
           {
               students[*pApousies].apousies = apousies;
               strcpy(students[*pApousies].name, name);
               (*pApousies)++;
           }
           (*pStudents)++;
    }
}

/* Συνάρτηση εξαγωγής επεξεργασμένων δεδομένων σε αρχείο */
void writeOutput(FILE* outfile, int size, studentT students[], int total)
{
    int i;

    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOUSIES");
    for (i=0; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);
    for (i=0; i<size; i++)
    {
        fprintf (outfile, "%-30s%9d\n", students[i].name, students[i].apousies);
    }

    for (i=0; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    fprintf (outfile, "%-30s%9d\n", "SYNOLO MATHITWN", total);
    fprintf (outfile, "%-30s%9d\n", "SYNOLO APONTWN", size);
}
