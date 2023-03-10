#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *ptr = "abc";
	ptr[0] = 'x';

	printf("%s", ptr);
	exit(0);
}
