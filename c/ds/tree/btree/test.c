#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	int data;
	struct node_st *l;
	struct node_st *r;
};



/**
 * 插入树的节点,
 * 插入规则是,比较新节点的id和当前节点的id,如果新节点的id > 当前节点的id,
 * 则插入为当前节点的右孩子,其他情况为左孩子
 */

int insert(struct node_st **root, int data)
{
	if(*root == NULL)
	{
		struct node_st *newNode;
		newNode = malloc(sizeof(*newNode));		
		newNode->data = data;
		newNode->l = NULL;
		newNode->r = NULL;
		*root = newNode;
		return 0;
	}

	if(data > (*root)->data)
	{
		insert(&((*root)->r), data);
	}
	else
	{
		insert(&((*root)->l), data);
	}
	return 0;
}

void draw_(struct node_st *root, int level)
{
	int i;
	if(root == NULL)
		return;

	draw_(root->r, level+1);
	for(i = 0; i < level; i++)
	{
		printf("    ");
	}
	printf("%d\n", root->data);
	draw_(root->l, level+1);
}

void draw(struct node_st *root)
{
	draw_(root, 0);
}

int main()
{
	int i;
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct node_st *root = NULL;

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		insert(&root, arr[i]);
	}
	draw(root);
}
