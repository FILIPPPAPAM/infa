#include "infa3_2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[100];
    char s2[100];

    printf("Введите строку s1: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Удаление символа новой строки

    printf("Введите строку s2: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Удаление символа новой строки

    remove_chars(s1, s2);

    printf("Результат: %s\n", s1);

    return 0;
}
