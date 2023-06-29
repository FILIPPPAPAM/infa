#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации о книге
struct Book {
    char isbn[20];
    char authors[100];
    char title[100];
    int total;
    int available;
};

// Функция для добавления новой книги
void addBook(struct Book books[], int *count) {
    char isbn[20];
    char authors[100];
    char title[100];
    int total;
    int available;

    printf("Enter the ISBN: ");
    scanf("%s", isbn);

    // Проверка, есть ли книга с таким ISBN уже в базе данных
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            printf("A book with the given ISBN already exists.\n");
            return;
        }
    }

    printf("Enter the author(s): ");
    scanf(" %[^\n]s", authors);

    printf("Enter the title: ");
    scanf(" %[^\n]s", title);

    printf("Enter the total number of books: ");
    scanf("%d", &total);

    printf("Enter the number of available books: ");
    scanf("%d", &available);

    // Добавление новой книги в базу данных
    strcpy(books[*count].isbn, isbn);
    strcpy(books[*count].authors, authors);
    strcpy(books[*count].title, title);
    books[*count].total = total;
    books[*count].available = available;

    (*count)++;

    printf("The book has been successfully added to the database.\n");
}

// Функция для удаления книги по ISBN
void removeBook(struct Book books[], int *count) {
    char isbn[20];

    printf("Enter the ISBN of the book to remove: ");
    scanf("%s", isbn);

    int found = 0;
    int index;

    // Поиск индекса книги в базе данных
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        // Удаление книги из базы данных путем сдвига элементов
        for (int i = index; i < *count - 1; i++) {
            books[i] = books[i + 1];
        }

        (*count)--;

        printf("The book has been successfully removed from the database.\n");
    } else {
        printf("The book with the given ISBN was not found.\n");
    }
}

// Функция для создания резервной копии базы данных
void createBackup(struct Book books[], int count) {
    char filename[100];

    printf("Enter the filename for the backup: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the backup file.\n");
        return;
    }

    // Запись информации о книгах в файл резервной копии
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s;%d;%d\n", books[i].isbn, books[i].authors, books[i].title, books[i].total, books[i].available);
    }

    fclose(file);

    printf("The backup has been successfully created.\n");
}

// Функция для восстановления базы данных из файла резервной копии
void restoreFromBackup(struct Book books[], int *count) {
    char filename[100];

    printf("Enter the filename of the backup: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the backup file.\n");
        return;
    }

    *count = 0;

    // Чтение информации о книгах из файла резервной копии
    while (!feof(file)) {
        fscanf(file, "%[^;];%[^;];%[^;];%d;%d\n", books[*count].isbn, books[*count].authors, books[*count].title, &books[*count].total, &books[*count].available);
        (*count)++;
    }

    fclose(file);

    printf("The database has been successfully restored from the backup.\n");
}

// Функция для поиска книг по фамилии автора
void searchByAuthor(struct Book books[], int count) {
    char lastName[100];
    int found = 0;

    printf("Enter the author's last name: ");
    scanf(" %[^\n]s", lastName);

    // Поиск книг по фамилии автора и вывод информации
    for (int i = 0; i < count; i++) {
        char *token = strtok(books[i].authors, ",");
        while (token != NULL) {
            if (strstr(token, lastName) != NULL) {
                printf("ISBN: %s\n", books[i].isbn);
                printf("Author(s): %s\n", books[i].authors);
                printf("Title: %s\n", books[i].title);
                printf("Total: %d\n", books[i].total);
                printf("Available: %d\n\n", books[i].available);
                found = 1;
                break;
            }
            token = strtok(NULL, ",");
        }
    }

    if (!found) {
        printf("No books found for the given author.\n");
    }
}

// Функция для сохранения текущего состояния базы данных в файл
void saveDatabase(struct Book books[], int count) {
    FILE *file = fopen("books.csv", "w");
    if (file == NULL) {
        printf("Failed to save the database.\n");
        return;
    }

    // Запись информации о книгах в файл
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s;%d;%d\n", books[i].isbn, books[i].authors, books[i].title, books[i].total, books[i].available);
    }

    fclose(file);

    printf("The database has been successfully saved.\n");
}

int main() {
    struct Book books[100];  // Массив для хранения книг
    int count = 0;  // Количество книг в массиве

    FILE *file = fopen("books.csv", "r");
    if (file == NULL) {
        printf("Failed to open the database file.\n");
        return 1;
    }

    // Чтение информации о книгах из файла базы данных
    while (!feof(file)) {
        fscanf(file, "%[^;];%[^;];%[^;];%d;%d\n", books[count].isbn, books[count].authors, books[count].title, &books[count].total, &books[count].available);
        count++;
    }

    fclose(file);

    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add a new book\n");
        printf("2. Remove a book by ISBN\n");
        printf("3. Create a backup\n");
        printf("4. Restore from backup\n");
        printf("5. Search for books by author's last name\n");
        printf("6. Exit the program\n");
        printf("Enter the operation number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                removeBook(books, &count);
                break;
            case 3:
                createBackup(books, count);
                break;
            case 4:
                restoreFromBackup(books, &count);
                break;
            case 5:
                searchByAuthor(books, count);
                break;
            case 6:
                saveDatabase(books, count);
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid operation number.\n");
        }
    } while (choice != 6);

    return 0;
}
