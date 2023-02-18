#ifndef SQSTACK_H__
#define SQSTACK_H__

#define MAXSIZE	5

typedef int datatype;

typedef struct stack_st
{
	datatype data[MAXSIZE];
	int top;
}sqstack ;

sqstack *st_create(void);

int st_isempty(sqstack *stack);

int st_push(sqstack *stack, datatype *data);

int st_pop(sqstack *stack, datatype *data);

int st_top(sqstack *stack, datatype *data);

void st_travel(sqstack *stack);

void st_destory(sqstack *stack);


#endif
