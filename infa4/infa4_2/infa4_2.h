#ifndef R_H
#define R_H

// Функция для подсчета количества установленных нечетных бит, равных 1, в числе
int count_odd_bit_ones(unsigned int number) {
    int count = 0;

    // Перебираем каждый нечетный бит числа
    for (int bit = 0; bit < sizeof(number) * 8; bit += 2) {
        if ((number >> bit) & 1) {
            count++;
        }
    }

    return count;
}

#endif // R_H
