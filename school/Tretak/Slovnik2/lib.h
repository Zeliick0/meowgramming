#ifndef LIB_H
#define LIB_H
#define N 255
#define MAX_WORDS 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void flushInput();
void to_lowercase(char *string);
int loadDictionary(const char* filename, char czech[][N], char english[][N], int lessons[], int maxWords);
void Translate(char czech[][N], char english[][N], int count);
void lesson_test(char czech[][N], char english[][N], int lessons[], int count);
int wordsInLesson(char czech[][N], int lessons[], int count);
void addWord(const char *filename, int *count, char czech[][N], char english[][N], int lessons[], int maxWords);
void randomTest(char czech[][N], char english[][N], int count);
void EditWords(const char *filename, char czech[][N], char english[][N], int lessons[], int *count);

#endif
