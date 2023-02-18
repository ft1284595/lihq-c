#ifndef SQSTACK_H__
#define SQSTACK_H__

#define SIZE	32

typedef int type;

typedef struct 
{
	type data[SIZE];
	int top;
}sqstack ;

sqstack *st_create(void);

int st_isempty(sqstack *stack);

int st_push(sqstack *stack, type *data);

int st_pop(sqstack *stack, type *data);

int st_top(sqstack *stack, type *data);

void st_travel(sqstack *stack);

void st_destory(sqstack *stack);


#endif
