#ifndef STACK_H__
#define STACK_H__

#include "llist.h"

typedef	LLIST 	STACK;


STACK *stack_create(int);

int stack_push(STACK *, void *);

int stack_pop(STACK *, void *);

void stack_destory(STACK *);

#endif
