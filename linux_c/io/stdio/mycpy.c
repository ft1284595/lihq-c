#include <stdio.h>
#include <stdlib.h>

/**
 * 从命令行接收参数,拷贝文件
 * Usage: ./mycpy sourcefile destfile
 *
 */
int main(int argc, char *argv[])
{
	FILE *source, *dest;
	int ch, ret;

	if(argc < 3)
	{
		fprintf(stderr, "Usage: %s sourcefile destfile\n", argv[0]);
		exit(-1);
	}

	source = fopen(argv[1], "r");
	if(source == NULL)
	{
		perror("open sourcefile");
		exit(-2);
	}
	dest = fopen(argv[2], "w");
	if(dest == NULL)
	{
		fclose(source);
		perror("open destfile");
		exit(-2);
	}

	while(1)
	{
		ch = fgetc(source);
		if(ch == EOF)
		{
			break;
		}
		ret = fputc(ch, dest);
		if(ret == EOF)
		{
			perror("fputc()");
			break;
		}
	}

	fclose(source);
	fclose(dest);

	exit(0);
}
