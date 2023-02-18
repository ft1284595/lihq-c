#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"
#include "squeue.h"

#define 	NR_BALL		27

/*
 * 检查队列中的所有球是不是按照顺序排列的
 * 请注意:我们现在使用的队列中head节点是不存放数据的,参见squeue.h
 *
 * 返回值: 	1 表示顺序排列
 * 			0 表示次序不对
 */
int check_order(squeue *que)
{
	int i = (que->head + 1) % MAXSIZE;

	while(i != que->tail)
	{
		if(que->data[i] > que->data[(i+1)%MAXSIZE])
		{
			return 0;
		}
		i = (i + 1) % MAXSIZE;
	}
	return 1;
}

/**
 *  球钟问题:球钟是一个利用球的移动来记录时间的简单装置.它有三个可以容纳若干个球的指示器:分钟指示器,五分钟指示器,小时指示器.
 *
 * 	若分钟指示器中有2个球，五分钟指示器中有6个球，小时指示器中有5个球，则时间为5:32。
 *
 * 	现设初始时球队列的球数为27，球钟的三个指示器初态均为空。问，要经过多久，球队列才能回复到原来的顺序。
 */
int main()
{
	sqstack *stack_min, *stack_5min, *stack_hour;
	squeue *queue_ball;
	int i;
	int ball;
	int time = 0;

	stack_min = st_create(); 
	if(stack_min == NULL)
		exit(-1);
	stack_5min = st_create();
	if(stack_5min == NULL)
		exit(-1);
	stack_hour = st_create();
	if(stack_hour == NULL)
		exit(-1);

	queue_ball = qu_create();
	if(queue_ball == NULL)
		exit(-2);

	for(i = 1; i <= NR_BALL; i++)
	{
		qu_enqueue(queue_ball, &i);
	}

	qu_travel(queue_ball);

	//printf("%d\n", (-1 == -1));
#if 1
	while(1)
	{
		qu_dequeue(queue_ball, &ball);
		time++;
		if(stack_min->top == 3)	//stack_min栈满了,该进位了
		{
			while(!st_isempty(stack_min))	//先出栈stack_min中的所有球,出栈的球入queue_ball队列
			{
				st_pop(stack_min, &i);
				qu_enqueue(queue_ball, &i);
			}
			//进位的时候,要判断stack_5min是不是满了
			if(stack_5min->top == 10)	//stack_5min满了,需要进位
			{
				while(!st_isempty(stack_5min)) 	//出栈stack_5min中的所有球,出栈的球入queue_ball队列
				{
					st_pop(stack_5min, &i);
					qu_enqueue(queue_ball, &i);
				}
				//进位的时候,要判断stack_hour是不是满了
				if(stack_hour->top == 10)	//stack_hour栈满了,但是它不能再网上进位了
				{
					while(!st_isempty(stack_hour))	//出栈stack_hour中的所有球,出栈的球入queue_ball队列
					{
						st_pop(stack_hour, &i);
						qu_enqueue(queue_ball, &i);
					}

					//将当前的ball入queue_ball队列
					qu_enqueue(queue_ball, &ball);
					//只有这个时候stack_min, stack_5min, stack_hour这3个栈都是空的,所有的球都在队列中,才有可能符合顺序排列的要求
					if(check_order(queue_ball))
					{
						break;
					}

				}
				else	//stack_hour还有空间
				{
					st_push(stack_hour, &ball);
				}
			}
			else	//stack_5min还有空间
			{
				st_push(stack_5min, &ball);
			}

		}
		else		//stack_min栈还有空间,直接入栈
		{
			st_push(stack_min, &ball);
		}
	}

	printf("%d\n", time);

	qu_travel(queue_ball);
#endif

	st_destory(stack_min);	
	st_destory(stack_5min);
	st_destory(stack_hour);

	qu_destory(queue_ball);
	return 0;
}
