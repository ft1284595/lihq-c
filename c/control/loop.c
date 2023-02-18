#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=0,sum=0;

	loop:
		sum += i;
		i++;
		if(i<=100)
			goto loop;
	
	printf("sum = %d\n", sum);

	exit(0);
}
