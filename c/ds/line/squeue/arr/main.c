#include <stdio.h>
#include <stdlib.h>

#include "squeue.h"


int main()
{
	squeue *queue;
	datatype arr[] = {1,3,5,7};
	int i;
	int ret;

	queue = qu_create();
	if(queue == NULL)
		exit(-1);

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		qu_enqueue(queue, &arr[i]);
	}

	qu_travel(queue);

	/*
	i = 9;
	qu_enqueue(queue, &i);
	*/

	//qu_clear(queue);

	//qu_travel(queue);
	printf("====================================\n");
	while(!qu_isempty(queue)){
		ret = qu_dequeue(queue, &i);
		if(ret == 0)
			printf("%d ", i);
		else
			printf("dequeue error.\n");
	}
	printf("\n");

	printf("************************************\n");
	qu_travel(queue);
	printf("====================================\n");
	qu_destory(queue);

	return 0;
}
