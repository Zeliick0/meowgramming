#include "lib.h"

int is_digit(char number) {
    return number >= '0' && number <= '9';
}

int total_sum(const char *filename) {
    char input_buffer[buffer];
    int sum = 0;

    char *keyword = "mul(";
    FILE *f = fopen(filename, "r");

    while(fgets(input_buffer, sizeof(input_buffer), f)) {
    char *temp = input_buffer;

    }
     
    fclose(f);
    return sum;
}
