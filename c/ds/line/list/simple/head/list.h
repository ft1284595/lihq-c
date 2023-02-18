#ifndef LIST_H__
#define LIST_H__

/**
 * this is a list which has a head node.
 */

typedef int datatype;

typedef struct node_st
{
	datatype data;
	struct node_st *next;
} node;


node *list_create();

int list_insert_at(node *, int i, datatype *);
int list_order_insert(node *, datatype *);

int list_delete_at(node *, int i, datatype *);
int list_delete(node *, datatype *);

int list_isempty(node *); 

void list_display(node *);
void list_destory(node *);


#endif
