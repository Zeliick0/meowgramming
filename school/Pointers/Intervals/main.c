#include "headers/lib.h"

int main() {
    int upper;
    int lower;
    int divider;

    get_variables(&upper, &lower, &divider);
    
    if (upper < lower) {   
    reverse(&upper,&lower);
    }
    printf("Sum of the numbers is %d\n", sum(&upper, &lower));
    printf("Average of the numbers is: %.2f\n", avg(&upper, &lower, &divider));

}
