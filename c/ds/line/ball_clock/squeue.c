#include <stdio.h>
#include <stdlib.h>

#include "squeue.h"

squeue * qu_create()
{
	squeue *queue;
	queue = malloc(sizeof(*queue));
	if(queue == NULL)
		return NULL;
	queue->head = 0;
	queue->tail = 0;

	return queue;
}

//判断队列是否为空队列
int qu_isempty(squeue *queue)
{
	
	return (queue->head == queue->tail);
}

int qu_enqueue(squeue *queue, datatype *data)
{
	if(queue->head == (queue->tail + 1) % MAXSIZE)
	{
		fprintf(stderr, "queue is full, can not enqueue.\n");
		return -1;
	}

	queue->tail = (queue->tail + 1) % MAXSIZE;
	queue->data[queue->tail] = *data;
	
	return 0;
}

int qu_dequeue(squeue *queue, datatype *data)
{
	if(qu_isempty(queue))
	{
		fprintf(stderr,"queue is empty, can not dequeue.\n");
		return -1;
	}
	queue->head = (queue->head + 1) % MAXSIZE;
	*data = queue->data[queue->head];
	return 0;
}

//清空队列
int qu_clear(squeue *queue)
{
	queue->head = queue->tail;
	return 0;
}

void qu_travel(squeue *queue)
{
	int i;
	if(qu_isempty(queue))
	{
		return;
	}

	i = (queue->head + 1) % MAXSIZE;
	while(i != queue->tail)
	{
		printf("%d ", queue->data[i]);
		i = (i + 1) % MAXSIZE;
	}

	printf("%d\n", queue->data[i]);
	
}


void qu_destory(squeue *queue)
{
	free(queue);
}
