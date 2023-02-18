#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
	sqstack *stack;
	int i, ret, tmp;
	datatype arr[] = {19,23,0,45,67};

	stack = st_create();

	for(i = 0; i < (sizeof(arr) / sizeof(*arr)); i++)
	{
		ret = st_push(stack, &arr[i]);
		if(ret != 0)
		{
			printf("push failed, data=%d\n", arr[i]);
			exit(-1);
		}

	}

	st_travel(stack);

#if 0
	tmp = 10;
	st_push(stack, &tmp);
	st_travel(stack);
#endif

	
	while(!st_isempty(stack))
	{
		st_pop(stack, &tmp);
	}


	return 0;
}






