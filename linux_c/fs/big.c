#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * 创建一个5G大小的文件,
 *
 */
int main(int argc, char *argv[])
{
	int fd;
	int ret;

	if(argc < 2)
	{
		fprintf(stderr, "Usage:%s <filename>\n", argv[0]);
		exit(0);
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC , 0600);
	if(fd < 0)
	{
		perror("open()");
		exit(-1);
	}

	ret = lseek(fd, 1L*1024LL*1024LL*1024LL*5LL-1, SEEK_END);
	if(ret < 0)
	{
		perror("lseek()");
		exit(-2);
	}

	write(fd,"",1);
	close(fd);

	return 0;
}

