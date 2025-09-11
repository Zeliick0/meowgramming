#ifndef TEALIB_H
#define TEALIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void flushInput();

typedef struct{
    int Number;
    float Price;
    char Name[N];
    char Type[N];
}TEA;

TEA addTea(int count);
void printInfo(TEA tearr[], int count);
int greenteas(TEA tearr[], int count);
int compareNum(const void *a, const void *b);
int compareABC(const void *a, const void *b);
int comparePrice(const void *a, const void *b);
void sortNum(TEA tearr[], int count); 
void sortABC(TEA tearr[], int count);
void sortPrice(TEA tearr[], int count);
void saveToTXT(TEA tearr[], int count);
void findTea(TEA tearr[], int count);
int removeByNum(TEA tearr[], int *count);
void savetoBin(TEA tearr[], int count);
void printBin(const char *filename);

#endif
