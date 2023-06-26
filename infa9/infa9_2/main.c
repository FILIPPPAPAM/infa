#include <stdio.h>
#include "interleave.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Использование: %s <файл1> <файл2>\n", argv[0]);
        return 1;
    }

    char* file1 = argv[1];
    char* file2 = argv[2];

    interleaveFiles(file1, file2);

    return 0;
}
