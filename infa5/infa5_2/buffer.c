#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

int get_line(char s[]) {
    int c, i;
    for (i = 0; i < MAX_BUFFER_SIZE - 2 && (c = getchar()) != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\n';
    s[++i] = '\0';
    return i;
}
