#include "lib.h"

void fillarrays(int *array1, int *array2, int length) {

}

void sortarray(int *array, int length) {

}

int distance(int *array1, int *array2, int length) {
    int final_dist;
    int temp;

    for(int i = 0; i < length;i++){
    temp = abs(array1[i] - array2[i]);
    final_dist = final_dist + temp;
    }
    
    return final_dist;
}
