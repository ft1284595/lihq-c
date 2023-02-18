#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"
/**
 * 这是一个带头结点的双向循环链表
 *
 */

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

struct list_st {
	int size;
	struct node_st head;
};

/**
 * 创建一个双向链表,
 * initsize: 是链表的每个node中data的大小
 */
LLIST *llist_create(int initsize){

	//LLIST *list;
	struct list_st *list;

	list = malloc(sizeof(*list));
	if(list == NULL)
		exit(-1);
	list->size = initsize;

	//list->head.data = NULL;
	list->head.prev = &(list->head);
	list->head.next = &(list->head);

	return list;
}

int llist_insert(LLIST *p, void *user_data, enum INSERT_ORDER order){
	struct list_st *ptr;
	struct node_st *newnode;

	ptr = p;

	newnode = malloc(sizeof(*newnode) + ptr->size);
	//newnode->data = malloc(ptr->size); 
//printf("%s---->%d\n", __FUNCTION__,__LINE__);
	memcpy(newnode->data, user_data, ptr->size);
	if(order == HEAD){
		newnode->next = ptr->head.next;
		newnode->prev = &ptr->head;

		newnode->prev->next = newnode;
		newnode->next->prev = newnode;
		
	}else if(order == TAIL){
		newnode->next = &ptr->head;
		newnode->prev = ptr->head.prev;

		newnode->prev->next = newnode;
		newnode->next->prev = newnode;

	}else{
		return -100;
	}
	return 0;
}

static struct node_st *find_(struct list_st *ptr, void *key, llist_cmp *cmp){
	struct node_st *current;
	for(current = ptr->head.next; current != &ptr->head; current = current->next){
		if(cmp(key, current->data) == 0){
			break;
		}	
	}
	return current;

}

void *llist_find(LLIST *p, void *key, llist_cmp *cmp){
	struct list_st *ptr;
	struct node_st *node;
	ptr = p;

	node = find_(ptr, key, cmp);

	if(node == &ptr->head){
		return NULL;
	}else{
		return node->data;
	}

}

int llist_delete(LLIST *p, void *key, llist_cmp *cmp){
	struct list_st *list;
	struct node_st *node;
	list = p;
	node = find_(list, key, cmp);
	if(node && (node != &list->head)){
		node->prev->next = node->next;
		node->next->prev = node->prev;
		//free(node->data);
		free(node);
		return 0;
	}else{
		return -1;
	}

}

int llist_fetch(LLIST *p, void *key, llist_cmp *cmp, void *data){
	if(data == NULL)
		printf("nihao, lao six.\n");
	struct list_st *list;
	struct node_st *node;
	list = p;

	node = find_(list, key, cmp);
	if(node && (node != &list->head)){
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if(data != NULL){
			memcpy(data, node->data, list->size);
		}
		//free(node->data);
		free(node);
		return 0;

	}else{
		return -1;
	}
}

void llist_travel(LLIST *p, llist_op *op) {
	struct list_st *ptr;
	struct node_st *current;
	ptr = p;
	for(current = ptr->head.next; current != &ptr->head; current = current->next){
		op(current->data);
	}
}

void llist_destory(LLIST *p){
	struct list_st *list;
	struct node_st *current, *next;

	list = p;

	for(current = list->head.next; current != &(list->head); current = next){
		next = current->next;
		//free(current->data);
		free(current);
	}

	free(list);
}
