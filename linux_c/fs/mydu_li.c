#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <glob.h>


#define PATHSIZE 1024

static int path_noloop(const char *path)
{
	char *pos;

	pos = strrchr(path, '/');
	if(pos == NULL)
		exit(1);

	if(strcmp(pos+1, ".") == 0 || strcmp(pos+1, "..") == 0)
		return 0;

	return 1;
}

static int64_t mydu(const char *path)
{
	struct stat statres;
	char nextpath[PATHSIZE];
	//struct glob_t globres;
	glob_t globres;
	int i; 
	int64_t sum;

	if(lstat(path, &statres) < 0)
	{
		perror("lstat()");
		exit(1);
	}

	if(!S_ISDIR(statres.st_mode))
		return statres.st_blocks;
	
	// /aaa/bbb/ccc/ddd/eee/fff
	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/*", PATHSIZE - 2);
	glob(nextpath, 0, NULL, &globres);
	

	strncpy(nextpath, path, PATHSIZE);
	strncat(nextpath, "/.*", PATHSIZE - 3);
	glob(nextpath, GLOB_APPEND, NULL, &globres);

	sum = 0;

	for( i = 0; i < globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);
	}

	sum += statres.st_blocks;

	globfree(&globres);
	return sum;
}

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>", argv[0]);
		exit(1);
	}

	printf("%ld\n", mydu(argv[1])/2);
	exit(0);
}
