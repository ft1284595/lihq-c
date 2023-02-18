#include <stdio.h>
#include <stdlib.h>

int main()
{

	int *p = NULL;
	p = (int *)malloc(sizeof(int));
	if(p == NULL)
	{
		printf("malloc() failed.\n");

		exit(1);
	}
	*p = 10;
	printf("%p->%d\n", p, *p);
	free(p);
	//p = NULL;
	*p = 123;
	printf("%p->%d\n", p, *p);

	return 0;
}
