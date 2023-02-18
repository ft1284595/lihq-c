#ifndef LLIST_H__
#define LLIST_H__

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
/*
struct node_st {
	void *data;
	struct node_st *prev;
	struct node_st *next;
};
*/

struct node_st {
	struct node_st *prev;
	struct node_st *next;
	//char *data;   //不能用指针代替一维数组
	char data[0];	//C99以前不支持0个元素数组的写法	

	//double data[0];
	//char data[1];
};

typedef struct list_st {
	int size;
	struct node_st head;

	int (*insert) (struct list_st *, void *, enum INSERT_ORDER);
	void *(*find) (struct list_st *, void *, llist_cmp *);
	int (*delete) (struct list_st *, void *, llist_cmp *);
	int (*fetch) (struct list_st *, void *, llist_cmp *, void *);
	void (*travel) (struct list_st *, llist_op *);
} LLIST;




LLIST * llist_create(int);



void llist_destory(LLIST *);


#endif
