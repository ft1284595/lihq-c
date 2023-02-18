#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sqstack.h"

sqstack *st_create(void)
{
	sqstack *stack;
	stack = malloc(sizeof(*stack));
	if(stack == NULL)
		exit(-1);

	stack->top = -1;
	
	return stack;
}

int st_isempty(sqstack *stack)
{
	if(stack == NULL)
		exit(-1);


	return (stack->top == -1);
}

int st_push(sqstack *stack, datatype *data)
{
	if(stack == NULL)
		exit(-1);

	if(stack->top == (MAXSIZE - 1))
	{
		fprintf(stderr, "stack is full, can not push.\n");
		return -1;
	}
	stack->data[++stack->top] = *data;
	return 0;
}

int st_pop(sqstack *stack, datatype *data)
{
	sleep(1);
	if(stack == NULL)
		exit(-1);

	if(st_isempty(stack))
		return -2;
	
	*data = stack->data[stack->top--];
	printf("pop up: %d\n", *data);

	return 0;
}

int st_top(sqstack *stack, datatype *data)
{
	if(stack == NULL)
		exit(-1);
	
	*data = stack->data[stack->top];
	
	return 0;
}

void st_travel(sqstack *stack)
{
	int i;

	if(stack == NULL)
		exit(-1);
	if(st_isempty(stack))
	{
		printf("this is a empty stack.\n");
		return ;
	}

	/*
	for(i = 0; i<= stack->top; i++)
	{
		printf("%d ", stack->data[i]);
	}
	*/
	for(i = stack->top; i >= 0; i--)
	{
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}

void st_destory(sqstack *stack){
	free(stack);
}

