#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <strings.h>
#define buffer 64

int get_width(const char *filename);
int get_height(const char *filename);
int total_matches(const char *filename);

#endif
