#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE *fp = NULL;
	int count = 0;

	while(1)
	{
		fp = fopen("tmp","w");
		if(fp == NULL)
		{
			perror("fopen()");
			break;
		}
		count ++;
	}

	printf("count = %d\n", count);	


	exit(0);
}
