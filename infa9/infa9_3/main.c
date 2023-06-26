#include <stdio.h>
#include "paginate.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Использование: %s -p <строк_на_странице> -n <макс_длина_строки> <имя_файла>\n", argv[0]);
        return 1;
    }

    int linesPerPage = atoi(argv[2]);
    int maxLineLength = atoi(argv[4]);
    char* filename = argv[5];

    paginateFile(filename, linesPerPage, maxLineLength);

    return 0;
}
