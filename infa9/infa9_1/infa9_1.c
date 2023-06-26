#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"

#define MAX_LINE_LENGTH 256

int tail(const char* filename, int n) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    char lines[n][MAX_LINE_LENGTH];
    int lineCount = 0;

    // Чтение и сохранение последних N строк
    while (fgets(lines[lineCount % n], MAX_LINE_LENGTH, file) != NULL) {
        lineCount++;
    }

    fclose(file);

    // Вывод последних N строк
    int start = lineCount >= n ? lineCount % n : 0;
    int i;
    for (i = start; i < start + n; i++) {
        printf("%s", lines[i % n]);
    }

    return 0;
}
