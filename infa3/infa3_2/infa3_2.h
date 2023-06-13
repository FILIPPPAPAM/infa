#ifndef REMOVE_CHARS_H
#define REMOVE_CHARS_H

#include <string.h>

// Функция для удаления символов строки s2 из строки s1
void remove_chars(char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j, k;

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        int found = 0;

        for (k = 0; k < len2; k++) {
            if (s1[i] == s2[k]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0'; // Добавляем завершающий нулевой символ
}

#endif // REMOVE_CHARS_H
