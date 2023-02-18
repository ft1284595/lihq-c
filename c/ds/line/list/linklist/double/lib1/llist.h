#ifndef LLIST_H__
#define LLIST_H__

struct node_st {
	void *data;
	struct node_st *prev;
	struct node_st *next;
};

typedef struct list_st {
	int size;
	struct node_st head;
} LLIST;

enum INSERT_ORDER{
	HEAD,
	TAIL
};

/**
 * 打印数据的回调函数, 由main.c来实现
 */
typedef void llist_op (void *data);

/**
 * 链表中各个节点数据的比较方法,用于查询指定条件的数据
 * 根据返回值来判断是否符合条件
 * 0表示符合条件,非0表示不符合条件
 */
typedef int llist_cmp(void *key, void *data);


LLIST * llist_create(int);

int llist_insert(LLIST *, void *, enum INSERT_ORDER);

void *llist_find(LLIST *, void *, llist_cmp *);

int llist_delete(LLIST *, void *, llist_cmp *);

int llist_fetch(LLIST *, void *, llist_cmp *, void *);

void llist_travel(LLIST *, llist_op*);

void llist_destory(LLIST *);


#endif
