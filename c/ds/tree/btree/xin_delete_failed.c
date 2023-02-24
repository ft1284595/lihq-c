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
	printf("\n");
	printf("--------------------------------------\n");
	draw_(root, 0);
	printf("--------------------------------------\n");
	printf("\n");
}

struct score_st * find(struct node_st *root, int id)
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
}

int get_height(struct node_st *root)
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
void turn_left(struct node_st **root)
{
	//printf("turn_left\n");
	struct node_st *tmp;
	struct node_st *oldRoot = *root;
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
void turn_right(struct node_st **root)
{
	struct node_st *tmp;
	struct node_st *oldRoot = *root;

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
void balance(struct node_st **root)
{
	int leftHeight = 0;
	int rightHeight = 0;
	int diffHeight = 0;
	struct node_st **cur = root;	//保留root指针不被改变,方便调试问题

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
int delete(struct node_st **root, int id)
{
	struct node_st *cur = *root;
	struct node_st *tmp = NULL;
	struct node_st *tmp1 = NULL;
	
	if(*root == NULL)
	{
		printf("there isn't any tree. *root is NULL.\n");
		return -1;
	}
		
	//在树中查找指定的节点
	while(cur != NULL && id > cur->data.id)
	{
		cur = cur->rightChild;
	}

	while(cur != NULL && id < cur->data.id)
	{
		cur = cur->leftChild;
	}

	if(cur == NULL)
	{
		printf("can not find the node for the given id:%d\n", id);
		return -2;
	}
	
	printf("--------->%d\n", cur->data.id);
	tmp = cur;
	cur = cur->leftChild;
	tmp1 = cur;
	while(tmp1->rightChild != NULL)
	{
		tmp1 = tmp1->rightChild;
	}

	tmp1->rightChild = tmp->rightChild;

	free(tmp);


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

	balance(&root);

	draw(root);

	printf("*******************************\n");

	delete(&root, 5);

	draw(root);
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
