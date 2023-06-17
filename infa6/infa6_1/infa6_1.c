#include <stdio.h>

#define SWAP(x, y, T) { T temp = x; x = y; y = temp; }

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    SWAP(a, b, int);

    printf("After swap: a = %d, b = %d\n", a, b);

    float c = 3.14, d = 2.71;
    printf("Before swap: c = %f, d = %f\n", c, d);

    SWAP(c, d, float);

    printf("After swap: c = %f, d = %f\n", c, d);

    return 0;
}
