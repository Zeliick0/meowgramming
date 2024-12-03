#include "lib.h"
#include <stdio.h>

int get_length(const char *filename){
    int lines = 0;
    const int buffer = 32;
    char line_cont[buffer]; 
    
    FILE *f = fopen(filename, "r");
    
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
    fclose(f);
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
    int final_dist = 0;
    int temp;

    for(int i = 0; i < length;i++){
    temp = abs(array1[i] - array2[i]);
    final_dist = final_dist + temp;
    }
    
    return final_dist;
}

int matches(int *array1, int *array2, int length){
    int score = 0;

    for(int i = 0; i < length;i++){
        int count = 0;
        for(int j = 0; j < length; j++){
            if (array2[j] == array1[i]){
                count++;
        }
        }
    score = score + (count * array1[i]);
    }

    return score;
}

