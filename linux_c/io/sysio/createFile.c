#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define BUF_SIZE 		256
#define lineCount		10	


int main()
{
	int fd = -1;
	char buf[BUF_SIZE] = {'\0'};
	int i = 0;
	int ret = 0;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if(fd < 0)
	{
		fprintf(stderr, "open file faile.\n");
		exit(-1);
	}

	for(i = 1; i <= lineCount; i++)
	{
		sprintf(buf, "this is line %d.\n", i);
		//sprintf(buf, "%d.\n", i);
		ret = write(fd, buf, strlen(buf));
		if(ret < 0)
		{
			perror("write file");
			exit(-2);
		}
	}



	return 0;
}
