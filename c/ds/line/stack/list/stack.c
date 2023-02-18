#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int always_match(void *data, void *record)
{
	return 0;
}

STACK *stack_create(int initsize)
{
	return llist_create(initsize);
}

int stack_push(STACK *stack, void *data)
{
	return llist_insert(stack, data, HEAD);
}

int stack_pop(STACK *stack, void *data)
{
	return llist_fetch(stack, (void *)0, always_match,data);
}

void stack_destory(STACK *stack)
{
	llist_destory(stack);
}
