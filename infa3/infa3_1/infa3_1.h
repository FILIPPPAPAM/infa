#ifndef REVERSE_RANGE_H
#define REVERSE_RANGE_H

#include <string.h>

// Функция для разворота сокращенной записи
void reverse_range(char* s1, char* s2) {
    int len = strlen(s1);
    int index = 0;

    while (index < len) {
        char start = s1[index];
        char end = s1[index + 2];
        char current = start;

        if (start != '-' || end != '-') {
            if (start < end) {
                // Если первый символ меньше последнего, увеличиваем текущий символ
                // от начального до конечного значения и сохраняем каждый символ в результирующей строке
                while (current <= end) {
                    *s2 = current;
                    s2++;
                    current++;
                }
            } else {
                // Если первый символ больше последнего, уменьшаем текущий символ
                // от начального до конечного значения и сохраняем каждый символ в результирующей строке
                while (current >= end) {
                    *s2 = current;
                    s2++;
                    current--;
                }
            }
        }

        index += 3;
    }

    *s2 = '\0'; // Добавляем завершающий нулевой символ
}

#endif // REVERSE_RANGE_H
