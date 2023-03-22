/**
 *
 * 这个程序有bug, 它要求被删除的行的长度要比覆盖它的内容长, 最好是每行的长度都相同,否则会出错.
 * 
 * 例如: 
 * 1
 * 23
 * abc
 *
 * 如果删除第二行的23就会出错,因为要覆盖它的第3行,内容的长度超过了第2行.
 * 文件位置指针会乱掉
 *
 *
 * 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE	1
#define LINE_NUM	2

int getFileLength(int fd)
{
	int current = 0;
	int end = 0;

	current = lseek(fd, 0, SEEK_CUR);

	lseek(fd, 0, SEEK_SET);
	end = lseek(fd, 0, SEEK_END);

	lseek(fd, current, SEEK_SET);

	return end;
}



/**
 * 根据给定的行数,返回这行文本的末尾,距离文件开始位置的偏移量, 返回-1表示找不到指定行
 * 			
 */
int getPosition(int fd, int lineNum)
{
	int current = 0;
	int result = -1;
	int ret = 0;
	char buf[BUF_SIZE] = {'\0'};
	//回车计数器
	int crCount = 0;
	//先保存一下当前文件位置指针的位置
	current = lseek(fd, 0, SEEK_CUR);
	if(current < 0)
	{
		perror("lseek current postion");
		exit(-2);
	}

	//复位文件位置指针到文件的开头,准备下一步的计算
	ret = lseek(fd, 0, SEEK_SET);
	if(ret < 0)
	{
		perror("lseek to begining of the file");
		exit(-2);
	}

	if(lineNum == 1)
	{
		//将文件位置指针恢复成原状
		lseek(fd, current, SEEK_SET);
		result = 0;
		return result;
	}

	while(1)
	{
		ret = read(fd, buf, BUF_SIZE);
		if(ret == -1)
		{
			perror("read file");
			exit(-3);
		}
		if(ret == 0)
		{
			break;
		}

		if(buf[0] == '\n')
		{
			crCount ++;
			if(crCount == (lineNum - 1))
			{
				ret = read(fd, buf, BUF_SIZE);
				if(ret == 0)
				{
					lseek(fd, current, SEEK_SET);
					return -1;
				}
				result = lseek(fd, 0, SEEK_CUR);
				//将文件位置指针恢复成原状
				lseek(fd, current, SEEK_SET);
				return result - 1;
			}
		}
	}

	//将文件位置指针恢复成原状
	lseek(fd, current, SEEK_SET);
	return result;

}

/**
 *
 * 思路1:
 * while()
 * {
 * 		lseek 11 + read + lseek 10 + write
 * }
 *
 */
static int func1(char *filename)
{
	int fd = -1;
	int pos = 0;
	int line_length = 0;
	int file_length = 0;
	char buf[BUF_SIZE] = {'\0'};
	char buf2[BUF_SIZE] = {'\0'};
	int offset = 0;
	int n = 0;
	int lines = 0;
	int ret = 0;



	fd = open(filename, O_RDWR);
	if(fd < 0)
	{
		perror("open faile");
		exit(-1);
	}

	file_length = getFileLength(fd);

	line_length = getPosition(fd, LINE_NUM + 1) - getPosition(fd, LINE_NUM);
	if(line_length <= 0)
	{
		fprintf(stdout, "there aren't enough lines in file, nothing changed.\n");
		close(fd);
		return 0;
	}
	//printf("line_length=%d\n", line_length);
	
#if 1
	while(getPosition(fd, LINE_NUM + 1 + lines) > 0)
	{
		//printf("lines=%d\n", lines);
		//printf("pos=%d\n", getPosition(fd, LINE_NUM + 1 + lines));
		while(1)
		{
			ret = lseek(fd, getPosition(fd, LINE_NUM + 1 + lines) + offset, SEEK_SET);
			n = read(fd, buf, BUF_SIZE);
			//printf("N+1 line:offset = %d, n = %d, index = %d, %c\n", offset, n, ret, buf[0]);
			if(n < 0)
			{
				perror("read lines");
				exit(-4);
			}
			if(n == 0)
			{
				printf("EOF\n");
				fflush(NULL);
				close(fd);
				return 0;
			}
			ret = lseek(fd, getPosition(fd, LINE_NUM + lines) + offset, SEEK_SET);
			//printf("N line:offset = %d, n = %d, index = %d, %c\n", offset, n, ret, buf[0]);
			ret = write(fd, buf, n);
			/*
			read(fd, buf2, BUF_SIZE);
			if(buf2[0] == '\n')
			{
				write(fd, buf, n);
				write(fd, "\n", 1);
			}
			else
			{
				ret = write(fd, buf, n);
			}
			*/
			//printf("after write: n = %d, ret = %d, %c\n", n, ret, buf[0]);
			//printf("=================================================\n\n");
			offset ++;
			if(buf[0] == '\n')
			{
				//printf("break\n");
				offset = 0;
				break;
			}
		}
		offset = 0;
		lines ++;

	}

	//printf("line11 pos=%d\n", pos);

	//ftruncate(fd, pos);
#endif
	//printf("truncate offset = %d\n", file_length - line_length);
	ftruncate(fd, file_length - line_length);

	close(fd);
	return 0;


}

/**
 * 使用系统IO删除一个文件的第10行
 */
int main(int argc, char *argv[])
{

	int fd = 0;
	int pos = 0;
	int line = 2;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(-1);
	}

	func1(argv[1]);
	
#if 0
	fd = open(argv[1], O_RDWR);	

	pos = getPosition(fd, line);
	printf("line=%d, pos=%d\n", line, pos);
	lseek(fd, pos, SEEK_SET);
	write(fd, "\n", 2);
#endif

	close(fd);

	return 0;
}
