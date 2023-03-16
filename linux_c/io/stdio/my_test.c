#include <stdio.h>
#include <stdlib.h>

void func(char **s)
{
	int i;
	if(*s == NULL)
	{
		*s = malloc(5);
	}
	for(i = 0; i < 3; i++)
	{
		printf("%p\n", *s);
		*(*s+i)= 'a' + i;
	}
}

int main()
{
	char *s = NULL;

	func(&s);


	printf("in main s=%p\n", s);
	printf("%s\n", s);
	fflush(NULL);
	return 0;
}
