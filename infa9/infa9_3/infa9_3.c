#include <stdio.h>
#include "paginate.h"

void printPage(FILE* file, int pageNumber, int linesPerPage, int maxLineLength) {
    char line[maxLineLength];
    int lineCount = 0;

    printf("\n— Page %d —\n", pageNumber);

    while (lineCount < linesPerPage && fgets(line, sizeof(line), file) != NULL) {
        lineCount++;
        printf("%d: %s", lineCount, line);
    }
}

void paginateFile(const char* filename, int linesPerPage, int maxLineLength) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    int pageNumber = 1;

    while (!feof(file)) {
        printPage(file, pageNumber, linesPerPage, maxLineLength);
        pageNumber++;
    }

    fclose(file);
}
