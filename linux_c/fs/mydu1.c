#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define PATH_SIZE 1024

/**
 *
 * mydu.c使用的是glob函数,这里要换一种方式,使用readdir等函数来替代glob函数
 *
 */



/**
 *
 * 校验当前路径是不是.或者..
 * .和..这两个路径不需要递归
 */
int check_path(const char *path)
{
	//printf("path=%s\n", path);
	if(strcmp(".", path) == 0 || strcmp("..", path) == 0)
	{
		//printf("cmp . = %d\n", strcmp(".", path));
		//printf("cmp .. = %d\n", strcmp("..", path));
		return 0;
	}
	else
	{
		return 1;
	}
}

int64_t mydu(const char* path)
{
	int64_t sum = 0;
	struct stat statres;
	int ret = 0;
	DIR *dp = NULL;
	struct dirent *dir = NULL;
	char full_path[PATH_SIZE] = {'0'};

	//printf("path1=%s\n", path);
	ret = lstat(path, &statres);	
	if(ret == -1)
	{
		perror("lstat()");
		exit(-2);
	}

	if(S_IFDIR != (statres.st_mode & S_IFMT))
	{
		//printf("regular file.\n");
		return statres.st_blocks;
	}

	sum += statres.st_blocks;
	//printf("direcotry.\n");
	dp = opendir(path);	
	if(dp == NULL)
	{
		perror("opendir()");
		exit(-3);
	}
	while((dir = readdir(dp)) && dir != NULL)
	{
		//printf("%s\n", dir->d_name);
		//sleep(1);
		if(check_path(dir->d_name))
		{
			strncpy(full_path, path, PATH_SIZE);
			strncat(full_path, "/", PATH_SIZE - 1);
			strncat(full_path, dir->d_name, PATH_SIZE);
			printf("full_path=%s\n", full_path);
			sum += mydu(full_path);
		}
	}


	//closedir(dp);

	


	return sum;

}

int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(-1);
	}


	printf("%ld\n", mydu(argv[1]) / 2);

	exit(0);
}
