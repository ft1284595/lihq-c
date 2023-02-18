#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"


int list_insert(struct node_st **list, struct score_st *data){
//printf("%s------>lineNum:%d\n",__FUNCTION__, __LINE__);
	struct node_st *newnode = NULL;
	newnode = malloc(sizeof(struct node_st));
	if(newnode == NULL)
		return -1;
	newnode->data = *data;
	newnode->next = NULL;
	
	newnode->next = *list;

	*list = newnode;	
	return 0;
}

void list_show(struct node_st *list){
	struct node_st *cur = NULL;
	for(cur = list; cur != NULL; cur = cur->next){
		printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
	}
}

int list_delete(struct node_st **list){
	struct node_st *cur = NULL;
	if(*list == NULL){
		return -1;
	}
	
	cur = *list;

	*list = (*list)->next;


	free(cur);

	return 0;
}

struct score_st * list_find(struct node_st* list, int id){
	struct node_st *cur;
	for(cur = list; cur != NULL; cur = cur->next){
		if(cur->data.id == id){
			return &(cur->data);
		}
	}
	
	return NULL;
}

void list_destory(struct node_st *list){

	struct node_st *cur;
	struct node_st *tmp;
	for(cur = list; cur != NULL; cur = tmp){
		tmp = cur->next;
		free(cur);
	}

}
