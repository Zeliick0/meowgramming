#include "headers/lib.h"

int main() {
    int *array;
    int *evenNums;
    int even;

    array = (int*) malloc(N * sizeof(int));
    fillArray(array);
    printArray(array, N);
    
    even = evenNumbers(array, evenNums);
    printArray(evenNums, even);

    free(array);
    free(evenNums);
    return 0;
}
