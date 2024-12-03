#include "lib.h"
#include <stdio.h>

int get_length(){
    int lines = 0;
    const int buffer = 32;
    char line_cont[buffer]; 
    
    FILE *f = fopen("input.txt", "r");
    
    while(fgets(line_cont, buffer, f)) {
        lines++;
    }
    fclose(f);
    return lines;
}

void fillarrays(int *array1, int *array2, int length) {
    FILE *f = fopen("input.txt", "r");
    
    for(int i = 0; i < length; i++){
        fscanf(f, "%d %d", &array1[i], &array2[i]);
    }
}

void sortarray(int *array, int length) {
    int temp;
    for(int i = 0; i < length; i++) {
        for(int j = 1; j < length - i - 1; j++) {
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
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
