#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для обмена двух строк
void swapStrings(char** str1, char** str2) {
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Функция для разбиения массива строк на основе опорного элемента
int partition(char** arr, int low, int high) {
    char* pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному элементу
        if (strlen(arr[j]) <= strlen(pivot)) {
            i++; // Увеличиваем индекс меньшего элемента
            swapStrings(&arr[i], &arr[j]);
        }
    }

    swapStrings(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Функция быстрой сортировки строк
void quickSortStrings(char** arr, int low, int high) {
    if (low < high) {
        // Получаем индекс опорного элемента
        int pivotIndex = partition(arr, low, high);

        // Рекурсивно сортируем две части массива
        quickSortStrings(arr, low, pivotIndex - 1);
        quickSortStrings(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    printf("Введите количество строк: ");
    scanf("%d", &n);

    // Выделяем память для массива строк
    char** strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        printf("Введите строку %d: ", i + 1);
        char buffer[100];
        scanf("%s", buffer);
        strings[i] = strdup(buffer); // Копируем строку в память
    }

    // Сортируем массив строк по их длине
    quickSortStrings(strings, 0, n - 1);

    // Выводим отсортированный массив строк
    printf("Отсортированный массив строк:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); // Освобождаем память для каждой строки
    }

    free(strings); // Освобождаем память для массива строк

    return 0;
}
