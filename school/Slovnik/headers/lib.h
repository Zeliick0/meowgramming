#ifndef LIB_H
#define LIB_H
#define N 255


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char czech[N];
    char english[N];
    int lecture;
}Word;

void flushInput();
int loadDictionary(const char* filename, Word dictionary[]);
void Translate(Word dictionary[], int count);




#endif
