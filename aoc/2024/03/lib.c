#include "lib.h"
#include <string.h>

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
        char *occurence;

        while ((occurence = strstr(temp,keyword)) != NULL) {
            occurence += strlen(keyword);

            char *num1_start = occurence;
            while (is_digit(*occurence)) {
                occurence++;
            }
            char *num1_end = occurence;

            if (*occurence == ',') {
                occurence++;
            }

            char *num2_start = occurence;
            while (is_digit(*occurence)) {
                occurence++;
            }
            char *num2_end = occurence;
            

            if (*occurence == ')') {
                char num1[4] = {0};
                char num2[4] = {0};
                strncpy(num1, num1_start, num1_end - num1_start);
                strncpy(num2, num2_start, num2_end - num2_start);
                
                int number1 = atoi(num1);
                int number2 = atoi(num2);
                
                sum = sum + (number1 * number2);
            }
            temp = occurence + 1;
        }
    }
     
    fclose(f);
    return sum;
}
