#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

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

struct treenode_st
{
	struct score_st data;
	struct treenode_st *leftChild;
	struct treenode_st *rightChild;
};


/**
 * 插入树的节点,
 * 插入规则是,比较新节点的id和当前节点的id,如果新节点的id > 当前节点的id,
 * 则插入为当前节点的右孩子,其他情况为左孩子
 */
int insert(struct treenode_st **root, struct score_st *score)
{
	struct treenode_st *newNode;
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

void draw_(struct treenode_st *root, int level)
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

void draw(struct treenode_st *root)
{
	printf("\n");
	printf("--------------------------------------\n");
	draw_(root, 0);
	printf("--------------------------------------\n");
	printf("\n");
}

struct score_st * find(struct treenode_st *root, int id)
{
	if(root == NULL)
		return NULL;

	if(id == root->data.id)
	{
		return &root->data;
	}

	if(id > root->data.id)
	{
		find(root->rightChild, id);
	}
	else
	{
		find(root->leftChild, id);
	}
	return NULL;
}

int get_height(struct treenode_st *root)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if(root == NULL)
		return 0;


	leftHeight = get_height(root->leftChild);
	rightHeight = get_height(root->rightChild);

	return (leftHeight >= rightHeight ? leftHeight : rightHeight) + 1;


}
/**
 * 向左旋转二叉树
 */
void turn_left(struct treenode_st **root)
{
	//printf("turn_left\n");
	struct treenode_st *tmp;
	struct treenode_st *oldRoot = *root;
	*root = (*root)->rightChild;
	tmp = *root;
	while(tmp->leftChild != NULL)
	{
		tmp = tmp->leftChild;
	}
	oldRoot->rightChild = NULL;
	tmp->leftChild = oldRoot;

	//draw(*root);
}

/**
 * 向右旋转二叉树
 */
void turn_right(struct treenode_st **root)
{
	struct treenode_st *tmp;
	struct treenode_st *oldRoot = *root;

	*root = (*root)->leftChild;
	tmp = *root;
	while(tmp->rightChild != NULL)
	{
		tmp = tmp->rightChild;
	}
	oldRoot->leftChild = NULL;
	tmp->rightChild = oldRoot;

	//draw(*root);
}

/**
 *
 * 	平衡二叉树: 平衡二叉树的意义是避免二叉树退化成链表,
 * 	链表的查询效率比二叉树低一些
 */
void balance(struct treenode_st **root)
{
	int leftHeight = 0;
	int rightHeight = 0;
	int diffHeight = 0;
	struct treenode_st **cur = root;	//保留root指针不被改变,方便调试问题

	if(*cur == NULL)
	{
		return;
	}

	leftHeight = get_height((*cur)->leftChild);
	rightHeight = get_height((*cur)->rightChild);

	diffHeight = leftHeight - rightHeight;
	//printf("diffHeight = %d\n", diffHeight);

	//左右两边子树的高度差小于等于1,那么就是平衡的
	if(diffHeight <= 1 && diffHeight >= -1)
	{
		//printf("0\n");
		balance(&(*root)->leftChild);
		balance(&(*root)->rightChild);
		//return;
	}
	if(diffHeight < -1)
	{
		//printf("1\n");
		turn_left(cur);
		balance(cur);
	}
	if(diffHeight > 1)
	{
		//printf("2\n");
		turn_right(cur);
		balance(cur);
	}

}

/**
 * 删除指定id的节点,
 * 我们约定,删除节点的时候,如果该节点同时有左子树和右子树,优先将左子树顶上去
 * 删除节点别忘了free节点相应的内存
 */
int delete(struct treenode_st **root, int id)
{
	struct treenode_st **node;
	struct treenode_st *cur = NULL;
	struct treenode_st *tmp = NULL;

	if(*root == NULL)
	{
		printf("the given tree is a empty tree.");
		return -1;
	}

	node = root;

	//在树种查找指定的节点
	while(*node != NULL && (*node)->data.id != id)
	{
		if(id > (*node)->data.id)
		{
			*node = (*node)->rightChild;
		}
		else{
			*node = (*node)->leftChild;
		}
	}

	//没有找到要删除的节点
	if(*node == NULL)
	{
		printf("can not find the given id in the tree.\n");
		return -2;
	}

	//找到了指定的节点, 但是指定节点没有左子树
	if((*node)->leftChild == NULL)
	{
		*node = (*node)->rightChild;
	}
	else
	{
		tmp = *node;
		*node = (*node)->leftChild;
		cur = *node;
		while(cur->rightChild != NULL)
		{
			cur = cur->rightChild;
		}

		cur->rightChild = tmp->rightChild;

		free(tmp);
		
	}


	return 0;

}

/**
 *
 * 遍历树节点, 前序,中序,后序,
 * 根,左孩子,右孩子就是前序
 * 左孩子,根,右孩子就是中序
 * 左孩子,右孩子,根 就是后序
 */
#if 0
void traversal(struct treenode_st *root)
{
	if(root == NULL)	
	{
		return;
	}


	traversal(root->leftChild);
	traversal(root->rightChild);
	print_s(&root->data);


}
#else
/**
 * 按行遍历树节点
 */
void traversal(struct treenode_st *root)
{
	QUEUE *que = NULL;
	struct treenode_st *tmp = malloc(sizeof(*tmp));
	
	if(root == NULL)
		return;
	que = queue_create(sizeof(*root));
	printf("que=%p\n", que);
	if(que == NULL)
	{
		fprintf(stderr, "init queue failed.\n");
		return;
	}

	queue_en(que, root);

	while(1)
	{
		if(queue_de(que, tmp) != -1)
		{
			print_s(&tmp->data);
			if(tmp->leftChild != NULL)
			{
				queue_en(que, tmp->leftChild);
			}
			if(tmp->rightChild != NULL)
			{
				queue_en(que, tmp->rightChild);
			}
		}
		else{
			break;
		}
	} 
	printf("123\n");
	printf("que=%p\n", que);
	//queue_destory(que);
	printf("456\n");
}
#endif

int main()
{
	struct treenode_st *root = NULL;
	struct score_st tmp;
	int i;

	int arr[] = {1,2,3,7,6,5,9,8,4};
	//int arr[] = {1};

	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name, NAMESIZE, "stu%d", arr[i]);
		tmp.math = rand() % 100;
		tmp.chinese = rand() % 100;
		insert(&root, &tmp);
	}

	draw(root);

	balance(&root);

	draw(root);


	printf("\n\n");
	traversal(root);


	printf("where is core dump\n");
	/*
	printf("*******************************\n");

	delete(&root, 5);

	draw(root);
	*/
#if 0
	printf("===============================\n");
	printf("%d", get_height(root));
	//printf("%p", root);
	printf("===============================\n");
	struct score_st *res = NULL;
	i = 90;
	res = find(root, i);
	if(res == NULL)
		printf("can not find %d in tree.\n", i);
	else
		print_s(res);
#endif
	
	return 0;
}
