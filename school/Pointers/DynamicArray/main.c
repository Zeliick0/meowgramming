#include "headers/lib.h"

int main() {
    int *array;
    int *evenNums;
    int even;

    array = (int*) malloc(N * sizeof(int));
    fillArray(array);
    printf("Initial array: \n");
    printArray(array, N);
    
    even = evenNumbers(array, &evenNums);
    
    if (evenNums) {
        printf("\nArray with even numbers: \n");
        printArray(evenNums, even);
        free(evenNums);
    }
    
    free(array);
    return 0;
}
