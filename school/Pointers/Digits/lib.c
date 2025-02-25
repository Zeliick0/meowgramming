#include "headers/lib.h"

void flush() {
 q   int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_digits(int num, int *digits) {
    while (num != 0) {
        num /= 10;
        (*digits)++;
    }
}

void add_digits(int num, int digits, int *sum) {
    for(int i = 0; i < digits; i++) {
        *sum += num % 10; 
    }
}
