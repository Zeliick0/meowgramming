#include "lib.h"

int is_digit(char number) {
    return number >= '0' && number <= '9';
}

int is_valid(char *number) {
    for (int i = 0; number[i] != '\0'; i++) {
        if (!is_digit(number[i])) return 0;
    }
    return 1;
}

int total_sum(const char *filename) {
    int sum = 0;
    char num1[4];
    char num2[4];
    char *keyword = "mul(";

    FILE *f = fopen(filename, "r");
    
    
    
    return sum;
}
