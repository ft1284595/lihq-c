#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME	"/tmp/out"


struct treenode_st
{
	int data;
	struct treenode_st *leftChild;
	struct treenode_st *rightChild;
};


/**
 * 插入树的节点,
 * 插入规则是,比较新节点的id和当前节点的id,如果新节点的id > 当前节点的id,
 * 则插入为当前节点的右孩子,其他情况为左孩子
 */
int insert(struct treenode_st **root, int data)
{
	struct treenode_st *newNode;
	if(*root== NULL)
	{
		newNode = malloc(sizeof(*newNode));
		newNode->data = data;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;

		*root= newNode;
		return 0;
	}

	if(data > (*root)->data)
	{
		insert (&((*root)->rightChild), data);
	}
	else{
		insert(&(*root)->leftChild, data);
	}

	return 0;
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
	//print_s(&root->data);
	printf("%c\n", root->data);
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

int save_(struct treenode_st *root, FILE *fp)
{
	fputs("(", fp);
	if(root == NULL)
	{
		fputs(")", fp);
		return 0;
	}
	fputc(root->data, fp);
	save_(root->leftChild, fp);
	save_(root->rightChild, fp);
	fputs(")", fp);
	return 0;
}


void save(struct treenode_st *root)
{
	FILE *fp = NULL;
	fp = fopen(FILENAME, "w");
	save_(root, fp);
	fclose(fp);
	
}


int main()
{
	struct treenode_st *root = NULL;
	int i;

	char arr[] = "cefadjbh";

	for(i = 0; i < strlen(arr); i++)
	{
		insert(&root, arr[i]);
	}

	draw(root);

	save(root);


	return 0;
}
