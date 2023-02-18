#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct node_st {
	int data;
	struct node_st *next;
};


struct node_st * jose_create(int num){
	int i = 1;
	struct node_st *newnode, *cur;
	struct node_st *me;
	me = malloc(sizeof(struct node_st));
	me->data = i;
	me->next = me;
	i++;

	cur = me;

	for(; i <= num; i++){
		newnode = malloc(sizeof(*newnode));	
		newnode->data = i;
		newnode->next = me;

		cur->next = newnode;
		cur = newnode;
	}

	return me;
}

void jose_show(struct node_st *me){
	struct node_st *list = me;
	printf("jose_show: ");
	while(list){
		printf("(%p->%d->%p)", list, list->data, list->next);
		if(me == list->next){
			break;
		}
		list = list->next;
		sleep(1);
		fflush(NULL);
		
	}
	printf("\n");
}

void jose_kill(struct node_st *me, int n){
	printf("jose_kill:");
	struct node_st *cur, *node;
	cur = me;
	int i = 1;
	while(cur != cur->next){
		while(i < n){
			node = cur;
			cur = cur->next;
			i++;
		}

		printf("(%d ) ", cur->data);
		sleep(1);
		fflush(NULL);
		node->next = cur->next;
		printf("free %p	", cur);
		//free(cur);
		printf("after free %p->%d\n", cur, cur->data);

		cur = node->next;
		i = 1;
	}
	printf("\n");
}

/*
int jose_kill(struct node_st *list, int num){

	struct node_st *p1, *p2;
	int i = 1;

	p1 = list;
	p2 = list;
	//while(p1 != p1->next){
	while(p2 != p2->next){
		while(i < num){
			p1 = p2;
			p2 = p2->next;
			i++;
		}
		printf("%d is out of cirle.\n", p2->data);
		//
		p1->next = p2->next;
		free(p2);
		p2 = p1->next;
		i = 1;
	}

	return 0;


}
*/


int main()
{
	struct node_st *list;
	int num = 8;
	
	list = jose_create(8);
	jose_show(list);
	jose_kill(list, 3);
	jose_show(list);

	return 0;
}
