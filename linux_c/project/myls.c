#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <unistd.h>
#include <string.h>

#define PATH_SIZE 1024

/**
 *
 * 使用文件系统的相关函数粗略实现ls命令的功能
 */
int main(int argc, char *argv[])
{
	char path[PATH_SIZE] = {'\0'};
	glob_t globres;
	int ret = 0;
	int i = 0;

	if(argc == 1)
	{
		getcwd(path, PATH_SIZE);			
		if(path == NULL)
		{
			perror("getcwd()");
			exit(1);
		}
		
		strncat(path, "/*", PATH_SIZE - 2);
		ret = glob(path, 0, NULL, &globres);
		if(ret != 0)
		{
			fprintf(stderr, "glob() failed. ret = %d\n", ret);
			exit(2);
		}

		for(i = 0; i < globres.gl_pathc; i++)
		{
			printf("%s  ", strrchr(globres.gl_pathv[i], '/') + 1);
		}

	}

	printf("\n");

	exit(0);
}
