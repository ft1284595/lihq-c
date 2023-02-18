#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define NAMESIZE 	32

struct score_st 
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void print_s(void *record)
{
	struct score_st * r;
	r = record;

	printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

int main()
{
	QUEUE *que;
	struct score_st tmp;
	int i;
	int ret;

	que = queue_create(sizeof(struct score_st));

	for(i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name, NAMESIZE, "student%d", i);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;

		ret = queue_en(que, &tmp);
		if(ret != 0)
		{
			fprintf(stderr, "enqueue failed.\n");
			exit(-1);
		}
		
	}

	while(1)
	{
		ret = queue_de(que, &tmp);
		if(ret == 0)
		{
			print_s(&tmp);
		}else
		{
			break;
		}
	}


	queue_destory(que);
	return 0;
}
