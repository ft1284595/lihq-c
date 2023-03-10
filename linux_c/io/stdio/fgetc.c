#include <stdio.h>
#include <stdlib.h>


/**
 * 从命令行读取文件名称,打印这个文件的大小
 * Usage: fgetc filename
 *
 */
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int count = 0;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename", argv[1]);
		exit(1);
	}


	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(-1);
	}
	
	while(fgetc(fp) != EOF)
	{
		count++;
	}


	fclose(fp);
	printf("count = %d\n", count);

	exit(0);
}
