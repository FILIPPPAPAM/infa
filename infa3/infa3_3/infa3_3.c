#include "infa3_3.h"

int main() {
    int counts[MAX_DIGITS] = {0};
    char c;

    printf("Enter text: ");

    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            counts[c - '0']++;
        }
    }

    print_horizontal_histogram(counts);
    print_vertical_histogram(counts);

    return 0;
}
