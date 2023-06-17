#include <stdio.h>
#include <stdlib.h>

char* readLine() {
    // Инициализируем начальный размер буфера
    int bufferSize = 1024;

    // Выделяем память для буфера
    char* buffer = (char*)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int position = 0;
    int c;

    // Считываем символы из консоли до символа новой строки или конца файла
    while ((c = getchar()) != '\n' && c != EOF) {
        // Если достигли предела буфера, увеличиваем его размер
        if (position >= bufferSize - 1) {
            bufferSize *= 2;
            buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
            if (buffer == NULL) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }

        // Записываем считанный символ в буфер
        buffer[position++] = c;
    }

    // Добавляем символ конца строки
    buffer[position] = '\0';

    return buffer;
}

int main() {
    printf("Enter a line: ");

    // Считываем строку из консоли с помощью функции readLine()
    char* line = readLine();

    // Выводим считанную строку на экран
    printf("You entered: %s\n", line);

    // Освобождаем память, выделенную для строки
    free(line);

    return 0;
}
