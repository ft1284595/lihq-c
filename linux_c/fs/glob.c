
#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>


#if 1
static int handleError(const char *epath, int errno)
{

	puts(epath);
	fprintf(stderr, "ERROR MSG:%s\n", strerror(errno));

	return 0;
}
#endif


/**
 * 使用glob匹配一个路径,查看该路径下符合要求的文件有哪些?
 */
 // 例如: 
 // ./glob /etc/l*.conf 显示/etc下所有l开头的conf文件
 // ./glob "/home/xin/*"	显示/home/xin下的所有文件(不包含隐藏文件)
 // ./glob "/home/xin/.*" 显示/home/xin下的所有隐藏文件,双引号"是为了防止shell扩展通配符
 
int main(int argc, char* argv[])
{
	glob_t globres;
	int ret;
	int i;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <glob pattern>\n", argv[0]);
		exit(1);
	}

	ret = glob(argv[1], 0, handleError, &globres);
	//ret = glob(argv[1], 0, NULL, &globres);
	if(ret != 0)
	{
		fprintf(stderr, "glob() failed.\n");
		exit(2);
	}

	for(i = 0; i < globres.gl_pathc; i++)
	{
		puts(globres.gl_pathv[i]);
	}

	globfree(&globres);

	exit(0);
}
