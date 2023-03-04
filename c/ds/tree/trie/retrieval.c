#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILENAME 	"dictionary"
#define KEY_SIZE	256
#define VALUE_SIZE	256
#define BUF_SIZE 	513 	//key:value 它们的总长度是513


/**
 *
 * 简洁起见没有把这个结构体中使用的常量定义为宏
 * 正常写法应该使用宏来定义常量
 */
struct node_st 		//搜索树的节点
{
	/*
	 * 这个指针数组的大小是26,对应26个英文字母
	 * 这个指针数组中的所有指针都初始化为NULL,如果某个指针不为空,那么这个指针所在的位置就代表在字母表中的字母
	 * 同一时刻只会去取这个数组中的某一个指针的值
	 * 例如:
	 * 	第二个指针有值,其他指针都为NULL,表示字母'b'
	 */
	struct node_st *alphabet[26];	
	char description[1024];
};

struct node_st *newNode()
{
	int i;
	struct node_st *node = NULL;
	node = malloc(sizeof(*node));
	for(i = 0; i < 26; i++)
	{
		node->alphabet[i] = NULL;
	}
	node->description[0] = '\0';
	return node;
}

/**
 *
 * 插入元素
 *
 */
int insert(struct node_st **root, char *key, char *value)
{
	int i;

	if(*root == NULL)
	{
		*root = newNode();
	}

	if(*key == '\0')
	{
		strcpy((*root)->description, value);
		return 0;
	}

	insert(&((*root)->alphabet[*key - 'a']), key + 1, value); 
	//insert((*root)->alphabet + (*key - 'a'), key + 1, value); 

	return 0;
}


/**
 * 将文件中的一行文本以:为分隔符,解析为key和value
 *
 */
int getWord(char *buffer, char *key, char *value)
{
	int i, j;
	if(buffer == NULL)
	{
		fprintf(stderr, "buffer is NULL, can not getWord.\n");
		return -1;
	}

	for(i = 0; i < KEY_SIZE - 1 && buffer[i] != '\0'; i++)
	{
		if(buffer[i] != ':')
		{
			key[i] = buffer[i];
		}
		else
		{
			break;
		}
	}
	key[i] = '\0';
	i++;

	for(j = 0; j < VALUE_SIZE - 1 && buffer[i] != '\0'; j++, i++)
	{
		if(buffer[i] == '\n')
		{
			break;
		}
		value[j] = buffer[i];

	}
	value[j] = '\0';

	//printf("key=%s,value=%s\n", key, value);
	return 0;
}

/**
 *
 * 搜索树的查询时间复杂度是O(1)
 */
char *searchWord(struct node_st *root, char *key)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(*key == '\0')
	{
		return root->description;
	}

	return	searchWord(root->alphabet[*key - 'a'], key + 1);
}

/**
 *
 * 搜索树的概念及简单应用
 *
 * 在当前目录下有一个dictionary文件
 * 文件中的内容是一个小的字典
 * 每一行是一个单词(只考虑小写的情况)和它的解释,用:分割开来,类似于xxx:yyyyy
 *
 * 利用搜索树的概念来存储这个文件的内容
 *
 * 然后尝试查询一个单词的解释
 *
 *
 */
int main()
{
	struct node_st *root = NULL;
	FILE *fp = NULL;
	char buffer[BUF_SIZE];
	char key[KEY_SIZE] = {'\0'};
	char value[VALUE_SIZE] = {'\0'};
	char *datap = NULL;

	fp = fopen(FILENAME, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "read file failed.\n");
		exit(-1);
	}

	while(fgets(buffer, BUF_SIZE, fp) != NULL)
	{
		//printf("%s", buffer);
		getWord(buffer, key, value);
		insert(&root, key, value);
	}

	datap = searchWord(root, "butterfly");

	if(datap == NULL)
	{
		printf("did not find the word.\n");
	}
	else
	{
		printf("%s\n", datap);
	}

	fclose(fp);


	return 0;
}
