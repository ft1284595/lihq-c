#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE	 5	


int main(int argc, char *argv[])
{

	FILE *source = NULL;
	FILE *dest = NULL;
	char buffer[BUF_SIZE] = {'\0'};
	int n = 0;

	if(argc < 3)
	{
		fprintf(stderr,"Usage: %s sourcefile destfile\n", argv[0]);
	}

	source = fopen(argv[1], "r");
	if(source == NULL)
	{
		perror("fopen sourcefile");
		exit(-1);
	}

	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		perror("fopen dest file");
		fclose(source);
		exit(-2);
	}

	while((n = fread(buffer, 1, BUF_SIZE, source)) > 0)
	{
		fwrite(buffer, 1, n, dest);
	}
	/*
	//会出问题的代码, 文件的大小不可能正好是BUF_SIZE的整数倍
	while((n = fread(buffer, BUF_SIZE, 1, source)) > 0)
	{
		fwrite(buffer, 1, n, dest);
	}
	*/

	fclose(source);
	fclose(dest);

	exit(0);
}
