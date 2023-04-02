#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * 接收命令行参数
 * 查看指定目录下有多少文件(不包含隐藏文件)
 *
 */

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
	struct dirent *ditem = NULL;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
		exit(-1);
	}

	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		perror("opendir()");
		exit(-2);
	}

	while((ditem = readdir(dp)) && ditem != NULL)
		puts(ditem->d_name);


	closedir(dp);
	

	exit(0);
}
