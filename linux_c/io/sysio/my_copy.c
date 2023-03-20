#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//#define BUFSIZE	1024
#define BUFSIZE	1024

int main(int argc, char* argv[])
{
	int sourceFD, destFD;
	char buffer[BUFSIZE];
	int length;
	int ret;
	int count = 0; 
	int readCount = 0;
	int writeCount = 0;

	if(argc < 3)
	{
		fprintf(stderr, "Usage: %s <sourcefile> <destfile>\n");
		exit(1);
	}


	sourceFD = open(argv[1], O_RDONLY);
	if(sourceFD < 0)
	{
		perror("source file open()");
		exit(1);
	}
	destFD = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(destFD < 0)
	{
		close(sourceFD);
		perror("dest file open()");
		exit(1);
	}


	while(1)
	{
		length = read(sourceFD, buffer, BUFSIZE);
		if(length == 0)
		{
			break;
		}
		if(length == -1)
		{
			perror("read sourcefile");
			exit(2);
		}

		readCount ++;

		count = 0;
		while(length > 0)
		{
			/**
			 * 有的时候读写速度并不一致,有可能写的速度跟不上读的速度
			 * 比如读取了10个字节,但是一次写操作值写入了3个字节,
			 * 这时就需要在下一次read操作之前,判断上一次读取出来的10个字符是不是已经全部写完了
			 * 如果没有写完,就需要继续做write
			 */
			//printf("length=%d\n", length);
			ret = write(destFD, buffer+count, length);
			if(ret == -1)
			{
				perror("write destfile");
				exit(2);
			}
			length -= ret;
			count += ret;

			writeCount ++;
		}
	}


	close(sourceFD);
	close(destFD);

	printf("readCount=%d\n", readCount);
	printf("writeCount=%d\n",writeCount);

	return 0;
}
