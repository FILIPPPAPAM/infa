#include <stdio.h>

// Функция для обмена значений двух элементов
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для разделения массива на подмассивы и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Функция для сортировки массива с использованием цикла
void quick_sort(int arr[], int low, int high) {
    int stack[high - low + 1];  // Стек для хранения индексов
    int top = -1;  // Инициализация вершины стека

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pi = partition(arr, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

// Функция для вывода массива на экран
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
