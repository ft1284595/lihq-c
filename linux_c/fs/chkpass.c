#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>
#include <unistd.h>
#include <string.h>

/**
 *
 * 校验用户名和密码
 * @Note: 这个程序会读取/etc/shadow文件,所以必须得用管理员权限来运行
 *
 */
int main(int argc, char *argv[])
{
	struct spwd *pwdline = NULL;
	char *input = NULL;
	char *encode = NULL;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s <username>\n", argv[0]);
		exit(1);
	}

	pwdline = getspnam(argv[1]);	
	if(pwdline == NULL)
	{
		perror("getspname()");
		exit(2);
	}

	input = getpass("Enter your password:");
	if(input == NULL)
	{
		perror("getpass()");
		exit(3);
	}

	//crypt函数的第2个参数要求一个字符串的形式$id$salt$
	//其中id是选用的加密算法,salt是加密用来和原始串混杂在一起来确保加密的可靠性
	//但是这里的pwdline->sp_pwdp是$id$salt$encode$, crypt只用了前3个$的内容,但是我们这里没有手动截取
	encode = crypt(input, pwdline->sp_pwdp);
	if(encode != NULL)
	{
		if(strcmp(encode, pwdline->sp_pwdp) == 0)
		{
			printf("correct\n");
		}
		else
		{
			printf("wrong password.\n");
		}
	}



	exit(0);
}
