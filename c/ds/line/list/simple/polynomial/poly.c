#include <stdio.h>
#include <stdlib.h>


struct node_st {
	int coefficent;
	int exponent;
	struct node_st *next;
};

/**
 * create a list with a head node.
 */
struct node_st * poly_create(int a[][2], int num){
	struct node_st *head, *tmp, *cur;
	int i;
	head = malloc(sizeof(*head));
	head->next = NULL;

	cur = head;
	for(i = 0; i < num; i++){
		tmp = malloc(sizeof(struct node_st));
		tmp->coefficent = (*(a+i))[0];
		tmp->exponent = (*(a+i))[1];
		tmp->next = NULL;


		cur->next = tmp;
		cur = tmp;
	}


	return head;
}

void poly_show(struct node_st *head){
	struct node_st *cur;
	for(cur = head->next; cur != NULL; cur = cur->next){
		printf("(%d,%d)", cur->coefficent, cur->exponent);
	}
	printf("\n");
}

/*
 * union list2 to list1.
 */
int poly_union(struct node_st *list1, struct node_st *list2){
	struct node_st *p1, *p2, *cur, *newnode;
	p1 = list1->next;
	p2 = list2->next;
	cur = list1;

	while(p1 && p2){
		if(p1->exponent < p2->exponent){
			cur->next = p1;
			cur = p1;
			p1 = p1->next;
		}else if(p1->exponent == p2->exponent){
			if((p1->coefficent + p2->coefficent) == 0){
				p1 = p1->next;
				p2 = p2->next;
			}else{
				newnode = malloc(sizeof(*newnode));
				newnode->coefficent = (p1->coefficent + p2->coefficent);
				newnode->exponent = p1->exponent;
				newnode->next = NULL;

				cur->next = newnode;
				cur = newnode;
				p1 = p1->next;
				p2 = p2->next;
			}
		}else{			//p1->exponent > p2->exponent
			cur->next = p2;
			cur = p2;
			p2 = p2->next;
		}
	}

	
	if(p1){ //there isn't any node in list2, and list1 still has some more node.
		cur->next = p1;
	}else{ 
		cur->next = p2;
	}

	return 0;	
}

int main()
{
	struct node_st *p1, *p2;
	int a[][2] = {{5,0},{2,1},{8,8},{3,16}};
	int b[][2] = {{6,1},{16,6},{-8,8}};

	p1 = poly_create(a, 4);
	p2 = poly_create(b, 3);
	poly_show(p1);
	poly_show(p2);

	printf("nihao.\n");

	poly_union(p1, p2);
	poly_show(p1);

	return 0;
}
