#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int ret = 0;
	struct stat fileStat;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	ret = stat(argv[1], &fileStat);
	if(ret != 0)
	{
		perror("stat() failed");
		exit(-1);
	}

	printf("%s's length = %lld\n", argv[1], fileStat.st_size);


	exit(0);
}


