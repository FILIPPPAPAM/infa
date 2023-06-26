#ifndef DATABASE_H
#define DATABASE_H

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int population;
} City;

typedef struct {
    City* cities[MAX_SIZE];
} HashTable;

int hash(char* key);
void addCity(HashTable* hashTable, City* city);
void removeCity(HashTable* hashTable, char* cityName);
void listCities(HashTable* hashTable);

#endif
