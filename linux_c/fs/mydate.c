#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE	512
#define FORMAT_SIZE 256

/**
 *
 * 练习使用getopt相关的函数, 解析命令行选项,以及选项相关的参数
 *
 *  -y: year
 *  -m: month
 *  -d: day
 *  -H: hour
 *  -M: minute
 *  -S: second
 *
 * 	./mydate -y	//打印年份
 * 	./mydate -y -m -d //打印 年 月 日
 * 	./mydate -y 2	//打印2位年份
 * 	./mydate -y 4 	//打印4为年份
 * 	./mydate -H 12	//12小时制
 * 	./mydate -H 24	//24小时制
 */
int main(int argc, char *argv[])
{
	time_t result;
	time_t time_seconds;
	struct tm *time_s;
	char buf[BUF_SIZE] = {'\0'};
	int opt;
	char timeFormat[FORMAT_SIZE] = {'\0'};

	result = time(&time_seconds);
	if(result == -1)
	{
		perror("time() failed.");
		exit(-1);
	}

	time_s = localtime(&time_seconds);
	if(time_s == NULL)
	{
		perror("localtime() failed.");
	}

	while((opt = getopt(argc, argv, "ymdHMS")) != -1)
	{
		switch(opt)
		{
            case 'y':
                break;
			case 'm':
				strncat(timeFormat, " %m", 4);
				break;
            case 'd':
				strncat(timeFormat, " %d", 4);
                break;
			case 'H':
                break;
			case 'M':
				strncat(timeFormat, " %M", 4);
				break;
			case 'S':
				strncat(timeFormat, " %S", 4);
				break;
			default:
				fprintf(stderr, "you input wront option, please check the options.\n");
				exit(-2);

		}
	}

	printf("timeFormat=%s\n", timeFormat);
	strftime(buf, BUF_SIZE, timeFormat, time_s);

	printf("%s\n", buf);

	exit(0);
}
