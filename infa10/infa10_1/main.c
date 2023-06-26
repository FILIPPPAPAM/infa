#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Использование: %s <имя_файла> [-o ASC|DESC]\n", argv[0]);
        return 1;
    }

    char* fileName = argv[1];
    char* sortOrder = "ASC";  // По умолчанию сортировка по возрастанию

    if (argc == 4 && strcmp(argv[2], "-o") == 0) {
        sortOrder = argv[3];
    }

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    char word[50];
    TreeNode* root = NULL;

    while (fscanf(file, "%s", word) != EOF) {
        root = insertNode(root, word);
    }

    fclose(file);

    printf("Уникальные слова и их частота повторения:\n");

    if (strcmp(sortOrder, "ASC") == 0) {
        inorderTraversal(root);
    } else if (strcmp(sortOrder, "DESC") == 0) {
        reverseInorderTraversal(root);
    } else {
        printf("Неверный параметр сортировки. Используйте ASC или DESC.\n");
    }

    freeTree(root);

    return 0;
}
