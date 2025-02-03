#include "headers/lib.h"

void fillArray(int *array) {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (rand() % 10) + 1;
    }
}

void printArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("The number %d is %d\n", i + 1, array[i]);
    }
}

int evenNumbers(int *array, int *evenNums) {
    int even = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] % 2 == 0) {
            evenNums[even] = array[i];
            even++;
        }
    }
    return even;
}
