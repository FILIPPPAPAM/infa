#include <stdio.h>
#include <stdlib.h>

// Функция для сортировки слиянием
void mergeSort(int arr[], int l, int r);

// Функция для сортировки подсчетом
void countingSort(int arr[], int n, int max);

// Функция для печати элементов массива
void printArray(int arr[], int size);

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Исходный массив для сортировки слиянием: ");
    printArray(arr1, arrSize1);

    mergeSort(arr1, 0, arrSize1 - 1);

    printf("Отсортированный массив сортировкой слиянием: ");
    printArray(arr1, arrSize1);

    int arr2[] = {4, 2, 8, 3, 1, 5};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Исходный массив для сортировки подсчетом: ");
    printArray(arr2, arrSize2);

    countingSort(arr2, arrSize2, 8);

    printf("Отсортированный массив сортировкой подсчетом: ");
    printArray(arr2, arrSize2);

    return 0;
}

// Функция для слияния двух подмассивов arr[l..m] и arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создаем временные подмассивы
    int L[n1], R[n2];

    // Копируем данные во временные подмассивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Слияние временных подмассивов L[] и R[] обратно в arr[l..r]
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = l; // Индекс объединенного подмассива
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов из L[], если таковые есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов из R[], если таковые есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция для сортировки массива с использованием сортировки слиянием
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Находим средний индекс

        // Рекурсивно сортируем два подмассива
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Слияние двух отсортированных подмассивов
        merge(arr, l, m, r);
    }
}

// Функция для сортировки массива с использованием сортировки подсчетом
void countingSort(int arr[], int n, int max) {
    int count[max + 1]; // Массив для подсчета частот элементов
    int output[n]; // Отсортированный массив
    int i;

    // Инициализация массива подсчета нулями
    for (i = 0; i <= max; i++)
        count[i] = 0;

    // Подсчет частоты элементов
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // Вычисление позиций элементов в отсортированном массиве
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Размещение элементов в отсортированном массиве
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Копирование отсортированного массива обратно в arr
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Функция для печати элементов массива
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
