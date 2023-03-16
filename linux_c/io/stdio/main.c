#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_getline.h"

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t n = 0;
	FILE *fp = NULL;
	int ret = 0;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <file>", argv[0]);
		exit(-1);
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(-2);
	}


	while(1) 
	{
		ret = my_getline(&line, &n, fp);
		//printf("ret = %d\n",ret);
		if( ret < 0)
		{
			break;
		}
		printf("line=%s\n", line);
		printf("*n=%d\n", n);
		//sleep(1);
	}


	exit(0);
}
