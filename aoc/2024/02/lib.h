#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define buffer 32

int is_monotone(int prev, int cur);
int safe_reps(const char *filename);
int safeish_reps(const char *filename);

#endif
