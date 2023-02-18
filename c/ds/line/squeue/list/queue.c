#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


QUEUE * queue_create(int initsize)
{
	
	return llist_create(initsize);
}

int queue_en(QUEUE *ptr, void *data)
{
	return llist_insert(ptr, data, TAIL);
}

static int always_match(void *p1, void *p2)
{
	return 0;
}
int queue_de(QUEUE *ptr, void *data)
{
	return llist_fetch(ptr, (void *)0, always_match, data);
}

void queue_destory(QUEUE *ptr)
{
	llist_destory(ptr);
}
