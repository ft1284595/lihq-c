#include <stdio.h>
#include <stdlib.h>

#include "list.h"

node *list_create(){
	node *head = NULL;
	head = malloc(sizeof(node));
	if(head == NULL)
	{
		fprintf(stderr, "list_create malloc failed.");
		exit(-1);
	}
	return head;
}

int list_insert_at(node *head, int index, datatype *data){
	int j = 0;
	node *element = head;
	node *newnode = NULL;
	if(index < 0){
		fprintf(stderr,"list_insert_at, index is out of range.");
		return -1;
	}

	//printf("before while loop:%d, j=%d element=%p\n ", __LINE__, j, element);

	//while(j < index ,element != NULL){
	while(j < index && element != NULL){
		element = element->next;
		j++;
		//printf("linenum:%d, j=%d element=%p\n ", __LINE__, j, element);
	}

	if(element)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL){
			fprintf(stderr, "list_insert_at, malloc failed.\n");
			return -2;
		}
		newnode->data = *data;
		newnode->next = NULL;

		newnode->next = element->next;
		element->next = newnode;
		return 0;

	}else{
		fprintf(stderr, "list_insert_at, can not insert data in to the given index=%d.\n", index);
		return -3;
	}

}

#if 0
int list_insert_at(node *head, int index, datatype *data){
	int j;
	node *element = head->next;
	if(index < 0){
		fprintf(stderr,"list_insert_at, index is out of range.");
		return -1;
	}

	if(index == 0){
		list_order_insert(head, data);
		node *element = malloc(sizeof(node));
		if(element == NULL){
			fprintf(stderr, "list_order_insert malloc failed.");
			return -1;
		}

		element->data = *data;
		element->next = NULL;

		element->next = head->next;
		head->next = element;
		return 0;
	}
	if(head->next == NULL && index > 0){
		fprintf(stderr,"list_insert_at, index is bigger than the list size.");
		return -2;
	}
	for(j = 0; element != NULL; j++, element = element->next){
		if((j+1) == index){
			node *tmp = malloc(sizeof(node));
			tmp->data = *data;
			tmp->next = NULL;

			tmp->next = element->next;
			element->next = tmp;
			return 0;
		}

	}
	if(j+1 != index){
		fprintf(stderr, "list_insert_at, can not insert at the index.");
		return -3;
	}
	return 0;
}
#endif

/**
 * insert the list node value with an order, assume the order is small to big
 */
int list_order_insert(node *head, datatype *data){
	node *p = head;
	node *newnode = NULL;

	while(p->next != NULL && *data > p->next->data){
		p = p->next;
	}

	newnode = malloc(sizeof(node));
	newnode->data = *data;
	newnode->next = NULL;

	if(p->next){
		newnode->next = p->next;
		p->next = newnode;
	}else{
		p->next = newnode;
	}

	return 0;



}

/*
 * delete the given index node in list, return the data value of the deleted node.
 */
int list_delete_at(node *head, int index, datatype *data){
	int i = 0;
	node *p = head;
	while(i < index && p != NULL){
		p = p->next;
		i++;
	}	

	if(p){
		*data = p->next->data;
		p->next = p->next->next;
		return 0;
	}else{
		fprintf(stderr, "list_delete_at: can not delete the given index node in list.\n");
		return -1;
	}
}

/**
 * find the given data in list, then delete the node.
 */
int list_delete(node *head, datatype *data){
	node *p = head;

	while( p != NULL && p->next->data != *data){
		p = p->next;
	}

	if(p){
		p->next = p->next->next;
		return 0;
	}else{
		fprintf(stderr, "list_delete: can not find the given data in list.\n");
		return 1;
	}


	
}

int list_isempty(node *head){
	if(head->next == NULL)
		return 0;
	else 
		return -1;
} 

void list_display(node *head){
	node *next = head->next;
	//printf("head=%p\n", head);
	while(next){
		//printf("%p->%d ", next, next->data);
		printf("%d ", next->data);
		next = next->next;
	}
	printf("\n");
}

void list_destory(node *head){
	node *next = head->next;
	node *tmp;
	while(next){
		tmp = next->next;
		free(next);
		next = tmp;
	}
	free(head);
	return ;
}
