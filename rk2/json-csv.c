#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void jsonToCsv(cJSON *json, FILE *csvFile) {
    if (json->type == cJSON_Object) {
        cJSON *child = NULL;
        cJSON_ArrayForEach(child, json) {
            if (child->type == cJSON_String) {
                fprintf(csvFile, "%s;", child->string);
            } else {
                fprintf(csvFile, ";");
            }
        }
        fprintf(csvFile, "\n");

        cJSON *entry = NULL;
        cJSON_ArrayForEach(entry, json) {
            if (entry->type == cJSON_String) {
                fprintf(csvFile, "%s;", entry->valuestring);
            } else {
                fprintf(csvFile, ";");
            }
        }
        fprintf(csvFile, "\n");
    }
}

int main() {
    FILE *jsonFile = fopen("input.json", "r");
    if (jsonFile == NULL) {
        printf("Failed to open JSON file.\n");
        return 1;
    }

    FILE *csvFile = fopen("output.csv", "w");
    if (csvFile == NULL) {
        printf("Failed to create CSV file.\n");
        return 1;
    }

    char buffer[4096];
    fread(buffer, sizeof(char), sizeof(buffer), jsonFile);
    cJSON *json = cJSON_Parse(buffer);
    jsonToCsv(json, csvFile);

    cJSON_Delete(json);
    fclose(jsonFile);
    fclose(csvFile);

    printf("JSON to CSV conversion successful.\n");
    return 0;
}
