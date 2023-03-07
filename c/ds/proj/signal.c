#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



void alrm_handler(int s)
{
	alarm(1);
	printf("Get SIGALRM\n");
	//俄罗斯方块下落函数
}

int main()
{
	int ch;

	signal(SIGALRM, alrm_handler);
	alarm(1);

	while(1)
	{
		//printf("while(1)\n");
		//sleep(1);

		ch = getchar();
		printf("ch = %x\n", ch);
	}

	return 0;
}
