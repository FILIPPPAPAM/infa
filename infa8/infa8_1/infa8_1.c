#include <stdio.h>
#include <string.h>

int strend(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (t_len > s_len) {
        return 0; // Строка t не может быть окончанием строки s
    }

    int start_index = s_len - t_len;
    for (int i = 0; i < t_len; i++) {
        if (s[start_index + i] != t[i]) {
            return 0; // Строка t не совпадает с окончанием строки s
        }
    }

    return 1; // Строка t является окончанием строки s
}

int main() {
    char s[100], t[100];
    printf("Введите строку s: ");
    scanf("%s", s);
    printf("Введите строку t: ");
    scanf("%s", t);

    int result = strend(s, t);

    if (result == 1) {
        printf("Строка t является окончанием строки s\n");
    } else {
        printf("Строка t не является окончанием строки s\n");
    }

    return 0;
}
