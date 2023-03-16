#ifndef MY_GETLINE__H
#define MY_GETLINE__H
#include <stdio.h>

size_t my_getline(char **line, size_t *n, FILE *fp);

void my_getline_free(char **line);

#endif
