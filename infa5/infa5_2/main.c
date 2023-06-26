#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "calc.h"

#define MAX_OPERAND_SIZE 100

int main() {
    int digit = 0, line_length;
    double op2;
    char s[MAX_OPERAND_SIZE];
    line_length = get_line(s);
    for (int i = 0; i < line_length; i++) {
        switch (s[i]) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                digit += s[i] - '0';
                while (isdigit(s[++i]))
                    digit = digit * 10 + s[i] - '0';
                push(digit);
                digit = 0;
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push((int)(pop() / op2));
                } else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case ' ':
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                return -1;
        }
    }
    return 0;
}
