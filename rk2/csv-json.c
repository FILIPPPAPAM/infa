#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void csvToJson(FILE *csvFile, FILE *jsonFile) {
    char line[4096];
    char *headers[1024];
    int headerCount = 0;

    if (fgets(line, sizeof(line), csvFile)) {
        char *token = strtok(line, ";");
        while (token != NULL) {
            token[strcspn(token, "\r\n")] = 0;  // Remove newline characters
            headers[headerCount++] = strdup(token);
            token = strtok(NULL, ";");
        }
    }

    cJSON *root = cJSON_CreateObject();

    while (fgets(line, sizeof(line), csvFile)) {
        cJSON *entry = cJSON_CreateObject();
        char *value = strtok(line, ";");
        int i = 0;
        while (value != NULL) {
            value[strcspn(value, "\r\n")] = 0;  // Remove newline characters
            cJSON_AddStringToObject(entry, headers[i], value);
            value = strtok(NULL, ";");
            i++;
        }
        cJSON_AddItemToArray(root, entry);
    }

    char *jsonString = cJSON_Print(root);
    fprintf(jsonFile, "%s", jsonString);

    cJSON_Delete(root);
    free(jsonString);

    for (int i = 0; i < headerCount; i++) {
        free(headers[i]);
    }
}

int main() {
    FILE *csvFile = fopen("input.csv", "r");
    if (csvFile == NULL) {
        printf("Failed to open CSV file.\n");
        return 1;
    }

    FILE *jsonFile = fopen("output.json", "w");
    if (jsonFile == NULL) {
        printf("Failed to create JSON file.\n");
        return 1;
    }

    csvToJson(csvFile, jsonFile);

    fclose(csvFile);
    fclose(jsonFile);

    printf("CSV to JSON conversion successful.\n");
    return 0;
}
