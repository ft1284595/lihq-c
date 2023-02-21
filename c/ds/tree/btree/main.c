#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32

/**
 *
 * 实现一颗二叉树
 *
 */

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

struct node_st
{
	struct score_st data;
	struct node_st *leftChild;
	struct node_st *rightChild;
};


/**
 * 插入树的节点,
 * 插入规则是,比较新节点的id和当前节点的id,如果新节点的id > 当前节点的id,
 * 则插入为当前节点的右孩子,其他情况为左孩子
 */
int insert(struct node_st **root, struct score_st *score)
{
	struct node_st *newNode;
	if(*root== NULL)
	{
		newNode = malloc(sizeof(*newNode));
		newNode->data = *score;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;

		*root= newNode;
		return 0;
	}

	if(score->id > (*root)->data.id)
	{
		insert (&((*root)->rightChild), score);
	}
	else{
		insert(&(*root)->leftChild, score);
	}

	return 0;
}

void print_s(struct score_st * score)
{
	printf("%d\n", score->id);
}

void draw_(struct node_st *root, int level)
{
	int i;
	if(root == NULL)	
		return;

	draw_(root->rightChild, level+1);
	for(i = 0; i < level; i++)
	{
		printf("    ");
	}
	print_s(&root->data);
	draw_(root->leftChild, level+1);
}

void draw(struct node_st *root)
{
	draw_(root, 0);
}

int main()
{
	struct node_st *root = NULL;
	struct score_st tmp;
	int i;

	int arr[] = {1,2,3,7,6,5,9,8,4};

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "stu%d", arr[i]);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
		insert(&root, &tmp);
	}

	draw(root);
	//printf("%p", root);
	return 0;
}
