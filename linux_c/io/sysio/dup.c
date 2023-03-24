#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 *
 * 不改变注释行之后的那两行代码,将输出的字符串写到一个文件中而不是打印在屏幕上
 *
 */

#define FILENAME "/tmp/out"

int main()
{
	int fd;

	fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);

#if 0
	close(1);
	dup(fd);
#endif

	dup2(fd, 1);

	if(fd != 1)
		close(fd);


/**********************************/
	puts("hello world");
	exit(0);
}
