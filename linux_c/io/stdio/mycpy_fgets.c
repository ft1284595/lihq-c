#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE	256

int main(int argc, char *argv[])
{

	FILE *source = NULL;
	FILE *dest = NULL;
	char buf[BUF_SIZE] = {'\0'};




	if(argc < 3)
	{
		fprintf(stderr, "Usage: %s sourcefile destfile.\n", argv[0]);
		exit(-1);
	}

	source = fopen(argv[1], "r");
	if(source == NULL)
	{
		perror("fopen sourcefile");
		exit(-2);
	}
	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		perror("fopen dest file");
		fclose(source);
		exit(-3);
	}

	while(fgets(buf, BUF_SIZE, source) != NULL)
	{
		fputs(buf, dest);
	}


	fclose(source);
	fclose(dest);


	exit(0);
}
