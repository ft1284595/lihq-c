#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define NAMESIZE 	64

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void print_s(void *record)
{
	struct score_st *data;
	data = (struct score_st *) record;
	printf("%d %s %d %d\n", data->id, data->name, data->math, data->chinese);
}

int main()
{
	STACK *stack;
	struct score_st tmp;
	int i;
	int ret;

	stack = stack_create(sizeof(tmp));

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "stu%d", i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
		ret = stack_push(stack, &tmp);
		if(ret != 0)
		{
			fprintf(stderr, "stack push failed. i=%d\n", i);
			exit(-1);
		}
	}


	while(1)
	{
		ret = stack_pop(stack, &tmp);	
		if(ret == -1)
		{
			break;
		}
		print_s(&tmp);
	}	

	stack_destory(stack);
	return 0;
}
