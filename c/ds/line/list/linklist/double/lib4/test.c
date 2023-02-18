#include <stdio.h>
#include <stdlib.h>

#define 	NAMESIZE 	1024

struct node_st 
{
	struct node_st *prev;
	struct node_st *next;
};

struct score_st
{
	int id;
	struct node_st node;
	//char gender;
	char name[NAMESIZE];
	int math;
	int chinese;
};

/**
 * 测试指针的offset
 */
int main()
{
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(char));
	printf("%d\n", (size_t) &((struct score_st *) 0)->node);

	return 0;
}
