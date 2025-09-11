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
void to_lowercase(char *string);
int loadDictionary(const char* filename, Word dictionary[]);
void Translate(Word dictionary[], int count);
void lesson_test(Word dictionary[], int count);
int wordsInLesson(Word dictionary[], int count);
void addWord(const char* filename, int count, Word dictionary[]);
void randomTest(Word dictionary[], int count);
void EditWords(const char *filename, Word dictionary[], int count);

#endif
