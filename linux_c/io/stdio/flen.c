#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(-1);
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(-2);
	}

	fseek(fp, 0, SEEK_END);

	printf("file size = %ld\n", ftell(fp));


	exit(0);
}

