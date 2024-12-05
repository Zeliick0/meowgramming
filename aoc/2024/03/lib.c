#include "lib.h"

int is_digit(char number) {
    return number >= '0' && number <= '9';
}

int total_sum(const char *filename) {
    char input_buffer[buffer];
    int sum = 0;

    char *keyword = "mul(";
    FILE *f = fopen(filename, "r");

    while (fgets(input_buffer, sizeof(input_buffer), f)) {
        char *temp = input_buffer;
        int len = strlen(temp);
        char *occurence;
        char *num1, *num2;
        int number1 = 0, number2 = 0;


        while ((occurence = strstr(temp,keyword)) != 0) {
            if (!is_digit(*occurence)) {
                occurence += 4;
            }

            while (is_digit(*occurence)) {
                num1 = occurence;
                num1++;
                occurence++;
            }

            if (*occurence == ',') {
                occurence++;
            }

            while (is_digit(*occurence)) {
                num2 = occurence;
                num2++;
                occurence++;
            }

            if ((*occurence + 1) == ')') {
                number1 = atoi(num1);
                number2 = atoi(num2);
            } else {
                num1 = 0;
                num2 = 0;
            }
        sum = sum + (number1 * number2);
                
        }

    }
     
    fclose(f);
    return sum;
}
