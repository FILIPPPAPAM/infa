#ifndef HEX_TO_DEC_H
#define HEX_TO_DEC_H

#include <ctype.h>

// Функция для преобразования строки из шестнадцатеричного формата в целое число
int hex_to_dec(const char* hex_string) {
    int decimal = 0;
    int len = 0;

    // Подсчитываем длину строки
    while (hex_string[len] != '\0') {
        len++;
    }

    // Проходим по каждому символу строки
    for (int i = 0; i < len; i++) {
        char c = hex_string[i];

        // Если символ является шестнадцатеричной цифрой
        if (isxdigit(c)) {
            // Преобразуем символ в соответствующее значение
            int digit;
            if (isdigit(c)) {
                digit = c - '0';
            } else {
                digit = tolower(c) - 'a' + 10;
            }

            // Умножаем текущее число на 16 и добавляем следующую цифру
            decimal = decimal * 16 + digit;
        }
    }

    return decimal;
}

#endif // HEX_TO_DEC_H
