#include "infa4_1.h"
#include <stdio.h>

int main() {
    char hex_string[100];

    printf("Введите шестнадцатеричное число: ");
    scanf("%s", hex_string);

    int decimal = hex_to_dec(hex_string);

    printf("Десятичное число: %d\n", decimal);

    return 0;
}
