#include <stdio.h>

// Функция для поиска первого вхождения символа из s1 в s2
// Возвращает положение (индекс) найденного символа или -1, если символ не найден
int find_first_occurrence(const char *s1, const char *s2) {
    for (int i = 0; s1[i] != '\0'; i++) {  // Проходим по символам строки s1
        for (int j = 0; s2[j] != '\0'; j++) {  // Проходим по символам строки s2
            if (s1[i] == s2[j]) {  // Если символы совпадают
                return i;  // Возвращаем положение символа в s1
            }
        }
    }
    return -1;  // Символ не найден, возвращаем -1
}

int main() {
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    int position = find_first_occurrence(s1, s2);  // Вызов функции для поиска символа
    printf("Position: %d\n", position);  // Вывод результата поиска

    return 0;
}
