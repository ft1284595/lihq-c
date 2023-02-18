#ifndef SQUEUE_H__
#define SQUEUE_H__

//虽然MAXSIZE定义为5,但是我们约定head不存放数据,所以队列的实际容量是4
#define MAXSIZE		5	


typedef int datatype;
/**
 * 定义一个队列, 
 * data[MAXSIZE]: 使用一个数组来存放数据
 * head: 队列的头部的下标
 * tail: 队列的尾部的下标
 * 
 * 在这里我们设计data数组是可以循环重复使用的.
 * 入队列: tail下标+1,然后存入数据到data[tail]
 * 
 * 如何判断队列为空?
 * tail == head, 使用这个条件判断队列为空需要有一个前提:
 * 即,队列的head所指向的单元不可以存放数据.
 * 
 */
typedef struct node_st
{
	datatype data[MAXSIZE];
	int head;
	int tail;
} squeue;


squeue * qu_create();

//判断队列是否为空队列
int qu_isempty(squeue *);

int qu_enqueue(squeue *, datatype *);

int qu_dequeue(squeue *, datatype *);

//清空队列
int qu_clear(squeue *);

void qu_travel(squeue *);

void qu_destory(squeue *);

#endif
