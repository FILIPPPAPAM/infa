#include <stdio.h>
#include <stdlib.h>

// Функция для сортировки массива методом сортировки Шелла
void shellSort(int arr[], int n) {
    // Выбираем размер шага
    int gap = n / 2;

    while (gap > 0) {
        // Выполняем сортировку вставками с шагом gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        // Уменьшаем размер шага
        gap /= 2;
    }
}

int main() {
    int length;

    // Запрашиваем у пользователя длину массива
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Выделяем память для массива
    int* array = (int*)malloc(length * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Запрашиваем у пользователя элементы массива
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }

    // Вызываем функцию сортировки Шелла для массива
    shellSort(array, length);

    // Выводим отсортированный массив на экран
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Освобождаем память, выделенную для массива
    free(array);

    return 0;
}
