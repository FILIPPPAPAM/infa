#include <stdio.h>
#include <stdlib.h>
#include "tail.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Использование: %s <имя_файла> [N]\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int n = 5;  // Значение N по умолчанию

    if (argc >= 3) {
        n = atoi(argv[2]);
        if (n <= 0) {
            printf("Неверное значение N. Используется значение по умолчанию: 5.\n");
            n = 5;
        }
    }

    return tail(filename, n);
}
