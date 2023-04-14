#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>

#define BUF_SIZE 1024
#define STR_SIZE 512
#define PATH_SIZE 1024



int check_path(char *path)
{
	char *filename;
	filename = strrchr(path, '/');
	if(strcmp(filename+1, ".") == 0 || strcmp(filename+1, "..") == 0)
	{
		//printf("return 1 path=%s\n", filename+1);
		return 1;
	}
	//printf("return 0 path=%s\n", filename+1);
	return 0;
}


int64_t disk_usage(char *path)
{
	int ret;
	char newpath[PATH_SIZE];
	glob_t globres;
	int i = 0;
	struct stat statres;
	int64_t sum = 0;

	//先判断传入的path是目录还是文件
	//这里使用的lstat函数,注意它和stat的区别,如果传入的参数是一个符号链接,
	//我们这里需要的是符号链接文件的属性而不是符号链接指向的源文件的属性
	ret = lstat(path, &statres);	
	if(ret != 0)
	{
		perror("lstat()");
		exit(-2);
	}

#if 1
	if(!S_ISDIR(statres.st_mode))
	{
		return statres.st_blocks;
	}

	strncpy(newpath, path, PATH_SIZE);

	//使用glob函数解析这个目录下有多少文件
	//假设目录是/home/xin
	strncat(newpath, "/*", PATH_SIZE - 2);
	ret = glob(newpath, 0, NULL, &globres);

	strncpy(newpath, path, PATH_SIZE);

	//使用glob函数解析这个目录下有多少隐藏文件
	strncat(newpath, "/.*", PATH_SIZE - 2);
	//sleep(1);
	ret = glob(newpath, GLOB_APPEND, NULL, &globres);
	
	sum = statres.st_blocks;
	for( i = 0; i < globres.gl_pathc; i++)
	{
		if(check_path(globres.gl_pathv[i]) == 0)
			sum += disk_usage(globres.gl_pathv[i]);
	}

	globfree(&globres);

	return sum;


#endif

}

/**
 *
 * 使用glob函数解析路径,结合stat函数来实现du命令,查看一个目录的大小
 *
 */

int main(int argc, char *argv[])
{
	char *path = NULL;
	//char buf[BUF_SIZE] = {0};
	int64_t du_size = 0;

	if(argc < 2)	
	{
		//path = getcwd(buf, BUF_SIZE);
		//printf("buf=%s\n", buf);
		path = getcwd(NULL, 0);
		if(path == NULL)
		{
			perror("getcwd()");
			exit(-1);
		}
	}
	else{
		path = argv[1];
	}


	du_size = disk_usage(path);

	printf("%ld\n", du_size/2);

	//printf("path=%s\n", path);

	exit(0);
}
