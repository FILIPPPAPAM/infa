#include "infa3.h"
#include <stdio.h>

void reverse_range(char* s1, char* s2) {
    char start = s1[0];
    char end = s1[2];
    char current = start;

    if (start < end) {
        while (current <= end) {
            *s2 = current;
            s2++;
            current++;
        }
    } else {
        while (current >= end) {
            *s2 = current;
            s2++;
            current--;
        }
    }

    *s2 = '\0'; // Добавляем завершающий нулевой символ
}

int main() {
    char s1[] = "a-z";
    char s2[27]; // Результирующая строка, достаточно большая, чтобы вместить все буквы алфавита
    reverse_range(s1, s2);
    printf("%s\n", s2);

    char s3[] = "d-D";
    char s4[27];
    reverse_range(s3, s4);
    printf("%s\n", s4);

    return 0;
}