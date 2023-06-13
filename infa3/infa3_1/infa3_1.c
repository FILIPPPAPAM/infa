#include "infa3_1.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[100];
    printf("String: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Удаление символа новой строки

    char s2[100]; // Результирующая строка
    reverse_range(s1, s2);
    printf("result: %s\n", s2);

    return 0;
}
