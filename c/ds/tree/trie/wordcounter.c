#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	FILENAME	"Zen_of_Python"
#define 	BUF_SIZE	256

struct node_st 
{
	struct node_st *alphabet[26];
	int count;
};

/**
 * 判断一个字符是不是字母
 */
int isLetter(char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return 0;
	}
	else if(c >= 'a' && c <= 'z')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int parseLine(char *buffer, char * wordArr[32])
{
	int i = 0;
	int j = 0;
	int index = 0;
	int flag = 0;

	if(buffer == NULL)
	{
		fprintf(stderr, "buffer is NULL.\n");
		return -1;
	}

	for(i = 0, j = 0; i < BUF_SIZE; i++)	
	{
		if(isLetter(buffer[i]) == 0)
		{
			flag = 1;
			*(wordArr[index] + j) = buffer[i];
			j++;
		}
		else
		{
			if(flag == 1)		
			{
				*(wordArr[index] + j) = '\0';
				j = 0;
				index ++;
				flag = 0;
			}
			if(buffer[i] == '\n')
			{
				break;
			}
		}


	}

	return 0;
}

struct node_st *newNode()
{
	int i;
	struct node_st *node;
	node = malloc(sizeof(*node));
	if(node == NULL)
	{
		fprintf(stderr, "malloc for new node failed.\n");
		exit(-1);
	}
	node->count = 0;
	for(i = 0; i < 26; i++)
	{
		node->alphabet[i] = NULL;
	}

	return node;
}

/**
 * 将一个word存入搜索树
 */
int insert(struct node_st **root, char *key)
{
	//printf("insert()-->%s\n", key);
	if(*root == NULL)
	{
		*root = newNode();
	}

	if(*key == '\0')
	{
		(*root)->count = (*root)->count + 1;
		//printf("count=%d\n", (*root)->count);
		return 0;
	}

	insert((*root)->alphabet + (*key - 'a'), key + 1);
	return 0;

}

int search(struct node_st *root, char *key)
{
	if(root == NULL)
	{
		return -1;
	}

	if(*key == '\0')
	{
		return root->count;
	}

	return search(root->alphabet[*key - 'a'], key+1);
}

/**
 * 读取文件Zen_of_Python(文件中的标点符号和缩写我手动做了处理)
 * 利用搜索树,统计文件中的各个单词出现的次数
 *
 */
int main()
{
	
	int i;
	FILE *fp = NULL;
	char buffer[BUF_SIZE];
	char *splitWords[32];
	struct node_st *root = NULL;

	for(i = 0; i < 32; i++)
	{
		splitWords[i] = malloc(sizeof(64));
	}

	fp = fopen(FILENAME, "r");
	
	while(fgets(buffer, BUF_SIZE, fp) != NULL)
	{
		//printf("%s", buffer);
		parseLine(buffer, splitWords);
		for(i = 0; i < 32; i++)
		{
			if(*splitWords[i] == '\0')
				continue;
			printf("%s\n", splitWords[i]);
			insert(&root, splitWords[i]);
		}

		//每次用完后,重置指针数组
		for(i = 0; i < 32; i++)
		{
			*splitWords[i] = '\0';
		}
	}

	printf("%d\n",search(root, "is"));

	fclose(fp);

	return 0;
}
