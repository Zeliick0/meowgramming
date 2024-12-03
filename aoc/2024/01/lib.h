#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#define buffer 32

int get_length(const char *filename);
void fillarrays(int *array1, int *array2, int length);
void sortarray(int *array, int length);
int distance(int *array1, int *array2, int length);
int matches(int *array1,int *array2, int length);

#endif
