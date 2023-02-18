#define MAXSIZE		5

typedef struct node_st
{
	datatype data[MAXSIZE];
	int top;
} sqstack;


sqstack *st_create(void);

int st_isempty(sqstack *);

int st_push(sqstack *, datatype *);

int st_pop(sqstack *, datatype *);

int st_top(sqstack *, datatype *);

void st_travel(sqlstack *);

void st_destory(sqstack *);
