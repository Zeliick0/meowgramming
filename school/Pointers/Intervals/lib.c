#include "headers/lib.h"

void get_variables(int *upper, int *lower, int *divider) {
    printf("Enter the upper and lower limit and divider in this order (u l d):\n");
    scanf("%d %d %d", upper, lower, divider);
}

void reverse(int *upper, int *lower) {
    int temp = *lower;
    *lower = *upper;
    *upper = temp;
}

int sum(int *upper, int *lower) {
    int summ = *upper + *lower;
    return summ;
}

float avg(int *upper, int *lower, int *divider) {
    int avg = (sum(upper, lower)) / *divider;
    return avg;
}
