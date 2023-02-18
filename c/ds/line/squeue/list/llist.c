#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"
/**
 * 这是一个带头结点的双向循环链表
 *
 */


/**
 * 创建一个双向链表,
 * initsize: 是链表的每个node中data的大小
 */
LLIST *llist_create(int initsize){

	LLIST *list;

	list = malloc(sizeof(*list));
	if(list == NULL)
		exit(-1);
	list->size = initsize;

	//list->head.data = NULL;
	list->head.prev = &(list->head);
	list->head.next = &(list->head);

	return list;
}

int llist_insert(LLIST *ptr, void *user_data, enum INSERT_ORDER order){
	struct node_st *newnode;

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

static struct node_st *find_(LLIST *ptr, void *key, llist_cmp *cmp){
	struct node_st *current;
	for(current = ptr->head.next; current != &ptr->head; current = current->next){
		if(cmp(key, current->data) == 0){
			break;
		}	
	}
	return current;

}

void *llist_find(LLIST *ptr, void *key, llist_cmp *cmp){
	struct node_st *node;
	node = find_(ptr, key, cmp);

	if(node == &ptr->head){
		return NULL;
	}else{
		return node->data;
	}

}

int llist_delete(LLIST *list, void *key, llist_cmp *cmp){
	struct node_st *node;
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

int llist_fetch(LLIST *list, void *key, llist_cmp *cmp, void *data){
	if(data == NULL)
		printf("nihao, lao six.\n");
	struct node_st *node;
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

void llist_travel(LLIST *ptr, llist_op *op) {
	struct node_st *current;
	for(current = ptr->head.next; current != &ptr->head; current = current->next){
		op(current->data);
	}
}

void llist_destory(LLIST *list){
	struct node_st *current, *next;

	for(current = list->head.next; current != &(list->head); current = next){
		next = current->next;
		//free(current->data);
		free(current);
	}

	free(list);
}
