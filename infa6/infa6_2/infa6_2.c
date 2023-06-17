#include <stdio.h>

// Рекурсивная функция для бинарного поиска
int binary_search_recursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;  // Базовый случай: элемент не найден
    }

    int mid = (low + high) / 2;  // Находим середину массива

    if (arr[mid] == target) {
        return mid;  // Базовый случай: элемент найден
    } else if (arr[mid] > target) {
        return binary_search_recursive(arr, low, mid - 1, target);  // Ищем в левой половине
    } else {
        return binary_search_recursive(arr, mid + 1, high, target);  // Ищем в правой половине
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};  // Отсортированный массив
    int n = sizeof(arr) / sizeof(arr[0]);  // Размер массива
    int target;  // Целевой элемент для поиска

    printf("Enter the target element: ");
    scanf("%d", &target);  // Ввод целевого элемента

    int result = binary_search_recursive(arr, 0, n - 1, target);  // Вызов рекурсивной функции бинарного поиска

    if (result == -1) {
        printf("Element not found\n");  // Элемент не найден
    } else {
        printf("Element found at index %d\n", result);  // Элемент найден, вывод индекса
    }

    return 0;
}
