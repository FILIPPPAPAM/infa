#include <stdio.h>
#include "interleave.h"

void interleaveFiles(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Ошибка открытия файлов.\n");
        return;
    }

    char line1[256];
    char line2[256];
    int endOfFile1 = 0;
    int endOfFile2 = 0;

    while (!endOfFile1 || !endOfFile2) {
        if (!endOfFile1 && fgets(line1, sizeof(line1), fp1) != NULL) {
            printf("%s", line1);
        } else {
            endOfFile1 = 1;
        }

        if (!endOfFile2 && fgets(line2, sizeof(line2), fp2) != NULL) {
            printf("%s", line2);
        } else {
            endOfFile2 = 1;
        }
    }

    fclose(fp1);
    fclose(fp2);
}
