#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 10

// Функция для печати горизонтальной гистограммы
void print_horizontal_histogram(int counts[]) {
    printf("Horizontal histogram:\n");
    for (int i = 0; i < MAX_DIGITS; i++) {
        printf("%d: ", i);
        for (int j = 0; j < counts[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Функция для печати вертикальной гистограммы
void print_vertical_histogram(int counts[]) {
    printf("Vertical histogram:\n");

    int max_count = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
    }

    for (int i = max_count; i > 0; i--) {
        for (int j = 0; j < MAX_DIGITS; j++) {
            if (counts[j] >= i) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_DIGITS; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

#endif // HISTOGRAM_H
