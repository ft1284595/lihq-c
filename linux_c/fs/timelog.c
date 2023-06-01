#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define 	FNAME	"/tmp/timelog"
#define 	BUF_SIZE	256
/**
 * 在临时文件(如果没有就创建临时文件,如果已经存在,在文件的末尾接着写下去)中每隔1秒钟打印行号和时间戳
 * 例如:
 * 	1 	xxxx-xx-xx xx:xx:xx
 * 	2 	xxxx-xx-xx xx:xx:xx
 * 	3 	xxxx-xx-xx xx:xx:xx
 * 	4 	xxxx-xx-xx xx:xx:xx
 *
 *
 */

int main(){

	int fd;
	//char buffer[BUF_SIZE] = {'\0'};
	char buffer[BUF_SIZE];
	//char count_str[32];
	int count = 0;
	time_t stamp;
	struct tm *stamp_p;

	fd = open(FNAME, O_CREAT | O_APPEND | O_RDWR, 0600);
	if(fd < 0)
	{
		perror("open file failed.");
		exit(-1);
	}

	while(read(fd, buffer, BUF_SIZE))
	{
		++count;
	}

	while(1)
	{

		time(&stamp);	
		stamp_p = localtime(&stamp);
		/*
		strftime(buffer, BUF_SIZE, "%Y-%m-%d %H:%M:%S", stamp_p);
		//printf("%s\n", buffer);
		sprintf(count_str, "%-16d", ++count);
		strcat(count_str, buffer);
		printf("%s\n", count_str);
		*/
		sprintf(buffer, "%d\t%d-%d-%d %d:%d:%d\n", ++count, (stamp_p->tm_year+1900), (stamp_p->tm_mon+1), stamp_p->tm_mday, stamp_p->tm_hour, stamp_p->tm_min, stamp_p->tm_sec);
		write(fd, buffer, strlen(buffer));
		sleep(1);
	}

	close(fd);

	exit(0);

}
