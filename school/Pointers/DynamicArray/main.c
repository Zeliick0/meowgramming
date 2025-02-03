#include "headers/lib.h"

int main() {
    int *array;
    int *evenNums;
    int even;

    array = (int*) malloc(N * sizeof(int));
    fillArray(array);
    printArray(array, N);
    
    even = evenNumbers(array, evenNums);
    evenNums = (int*) malloc(even * sizeof(int));
    printArray(evenNums, even);

    free(array);
    return 0;
}
