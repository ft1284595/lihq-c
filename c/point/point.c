#include <stdio.h>
#include <stdlib.h>

int main()
{

	int i = 0;
	int *p = &i;

	printf("p=%p\n", p);
	printf("sizeof(p)=%d\n", sizeof(p));

	exit(0);
}

