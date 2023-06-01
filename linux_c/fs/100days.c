#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * 练习使用time相关的函数,求当前时间的100天后是哪天.
 *
 *
 */
int main(int argc, char *argv[])
{

	time_t time_seconds, time_seconds1, time_seconds2;
	time_t time_100day;
	struct tm* time_struct_pointer;

	char result[128];

	time_seconds = time(NULL);
	time_seconds2 = time(&time_seconds1);


	//printf("time = %ld\n", time_seconds);
	//printf("time1 = %ld\n", time_seconds1);
	//printf("time2 = %ld\n", time_seconds2);

	time_struct_pointer = localtime(&time_seconds);

	//printf("tm_mday=%d\n", time_struct_pointer->tm_mday);
	time_struct_pointer->tm_mday = time_struct_pointer->tm_mday + 10;
	//time_struct_pointer->tm_sec += 60*60*24*10;
	//printf("tm_yday=%d\n", time_struct_pointer->tm_yday);
	//time_100day = mktime(time_struct_pointer);
	mktime(time_struct_pointer);
	//time_struct_pointer = localtime(&time_100day);

	//printf("tm_mday=%d\n", time_struct_pointer->tm_mday);
	strftime(result, 128, "%Y-%m-%d", time_struct_pointer);

	printf("100 days after is:%s\n", result);

	exit(0);
}
