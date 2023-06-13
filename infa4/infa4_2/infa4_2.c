#include "infa4_2.h"
#include <stdio.h>

int main() {
    unsigned int number;

    printf("Введите число: ");
    scanf("%x", &number);

    int count = count_odd_bit_ones(number);

    printf("Количество установленных нечетных бит, равных 1: %d\n", count);

    return 0;
}
