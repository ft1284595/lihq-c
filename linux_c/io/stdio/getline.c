#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *line = NULL;
	size_t n = 0;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
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
		if(getline(&line, &n, fp) < 0)
			break;
		printf("%s", line);
		printf("%d\n", n);
	}


	exit(0);
}
