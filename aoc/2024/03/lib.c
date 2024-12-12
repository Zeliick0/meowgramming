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

    int i = 0;
    int c;

    while ((c = fgetc(f)) != EOF) {
        
        if (i < buffer - 1) {
            input_buffer[i++] = c;
        }

        if (c == '\n' || i >= buffer - 1) {
        input_buffer[i] = '\0';
        char *temp = input_buffer;
        char *occurence;

        while ((occurence = strstr(temp,keyword)) != NULL) {
            printf("Found keyword %s\n", occurence);

            occurence += strlen(keyword);

            char *num1_start = occurence;
            while (is_digit(*occurence)) {
                occurence++;
            }
            if (occurence == num1_start || *occurence != ',') {
                temp = occurence + 1;
                continue;
            }
            
            char num1[16] = {0};
            strncpy(num1, num1_start, occurence - num1_start);

            if (*occurence == ',') {
                occurence++;
            }

            char *num2_start = occurence;
            while (is_digit(*occurence)) {
                occurence++;
            }
            if (occurence == num2_start || *occurence != ')') {
                temp = occurence + 1;
                continue;
            }
            
            char num2[16] = {0};
            strncpy(num2, num2_start, occurence - num2_start);


            if (*occurence == ')') {
                if (strlen(num1) > 0 && strlen(num2) > 0) {
                int number1 = atoi(num1);
                int number2 = atoi(num2);
                sum = sum + (number1 * number2);
                } 
                }
            temp = occurence + 1;
        }
    }
    }
     
    fclose(f);
    return sum;
}
