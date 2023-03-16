#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_getline.h"


#define ORIGIN_SIZE 60

size_t my_getline(char **line, size_t *n, FILE *fp)
{
	size_t count = 0;
	int ch = 0;

	if(fp == NULL)	
	{
		fprintf(stderr, "in my_getline function the input fp is NULL.\n");
		exit(-10086);
	}
	

	if(n == NULL)
	{
		fprintf(stderr, "in my_getline function input pointer n is NULL.\n");
		exit(-10088);
	}

	if(*line == NULL)
	{
		*n = (*n == 0 ? ORIGIN_SIZE : *n);
		*line = malloc(*n);
		if(*line == NULL)
		{
			fprintf(stderr, "in my_getline function malloc failed.\n");
			exit(-10087);
		}
	}

	while(1)
	{

//size_t my_getline(char **line, size_t *n, FILE *fp)
		ch = fgetc(fp);
		if(ch == EOF)
		{
			printf("EOF\n");
			//if(feof(fp) > 0)
			return -1;
		}
		if(count == (*n - 5))
		{
			*n = (*n) * 2;
			*line = realloc(*line, *n);
		}
		if(ch != '\n')
		{
			if(count == 0)
			{
				memset(*line, '\0', *n);
			}

			*(*line + count) = ch;
			count ++;
		}
		else{
			if(feof(fp) > 0)
				return -1;
			return count;
		}
	}

	return count;

}

void my_getline_free(char **line)
{
	if(*line != NULL)
	{
		free(*line);
	}

}
