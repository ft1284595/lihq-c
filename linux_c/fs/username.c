#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

/**
 *
 * 根据uid获取uid对应的username
 */
int main(int argc, char *argv[])
{
	struct passwd *pwd = NULL;

	if(argc < 2)
	{
		fprintf(stderr, "Useage %s #\n", argv[0]);
		exit(1);
	}

	pwd = getpwuid(atoi(argv[1]));	

	if(pwd == NULL)
	{
		perror("getpwname()");
		exit(1);
	}

	printf("the uid %s is releative to %s\n", argv[1], pwd->pw_name);
	printf("pw_pwd=%s\n", pwd->pw_passwd);
	printf("pw_gid=%d\n", pwd->pw_gid);
	printf("pw_gecos=%s\n", pwd->pw_gecos);
	printf("pw_dir=%s\n", pwd->pw_dir);
	printf("pw_shell=%s\n", pwd->pw_shell);

	exit(0);
}
