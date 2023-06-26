#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % MAX_SIZE;
}

void addCity(HashTable* hashTable, City* city) {
    int index = hash(city->name);

    if (hashTable->cities[index] != NULL) {
        printf("Коллизия! Город %s не может быть добавлен.\n", city->name);
        return;
    }

    hashTable->cities[index] = city;
    printf("Город %s добавлен в базу данных.\n", city->name);
}

void removeCity(HashTable* hashTable, char* cityName) {
    int index = hash(cityName);

    if (hashTable->cities[index] == NULL) {
        printf("Город %s не найден в базе данных.\n", cityName);
        return;
    }

    free(hashTable->cities[index]);
    hashTable->cities[index] = NULL;
    printf("Город %s удален из базы данных.\n", cityName);
}

void listCities(HashTable* hashTable) {
    printf("Список городов:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (hashTable->cities[i] != NULL) {
            printf("%s (население: %d)\n", hashTable->cities[i]->name, hashTable->cities[i]->population);
        }
    }
}

int main() {
    HashTable hashTable;
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable.cities[i] = NULL;
    }

    int choice;
    do {
        printf("1. Добавить город\n");
        printf("2. Удалить город\n");
        printf("3. Вывести список городов\n");
        printf("4. Выйти\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите имя города: ");
                char cityName[50];
                scanf("%s", cityName);

                if (hashTable.cities[hash(cityName)] != NULL) {
                    printf("Город %s уже существует в базе данных.\n", cityName);
                    break;
                }

                int population;
                printf("Введите население города: ");
                scanf("%d", &population);

                City* city = (City*)malloc(sizeof(City));
                strcpy(city->name, cityName);
                city->population = population;

                addCity(&hashTable, city);
                break;

            case 2:
                printf("Введите имя города для удаления: ");
                char cityToRemove[50];
                scanf("%s", cityToRemove);

                removeCity(&hashTable, cityToRemove);
                break;

            case 3:
                listCities(&hashTable);
                break;

            case 4:
                printf("Программа завершена.\n");
                break;

            default:
                printf("Неверный выбор. Попробуйте еще раз.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
