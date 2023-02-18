#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

/**
 * 带头节点的双向循环链表测试类
 *
 * 假设我们要使用链表来存放学生的信息(一个结构体)
 *
 * struct score_st {
 * 		int id;					//学号
 * 		char name[NAMESIZE];	//姓名
 * 		int math;				//数学成绩
 * 		int chinese;			//语文成绩
 * };
 *
 */

#define	NAMESIZE		1024

struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void print_data(void *data){
	//printf("%s\n", __FUNCTION__);
	struct score_st *score;	
	//score = (struct score_st *) data;
	score = data;
	printf("id:%d, name:%s, math=%d, chinese=%d\n", score->id, score->name, score->math, score->chinese);
	printf("\n");
}

int id_cmp(void *key, void *data){
	int *k;
	struct score_st *record;

	k = key;
	record = data;

	return (*k - record->id);
}

int name_cmp(void *key, void *data){
	char *k;
	struct score_st *record;

	k = key;
	record = data;

	return strcmp(k, record->name);
}

int main(){
	LLIST *list;
	struct score_st *student;
	int i, ret;
	char *s;

	printf("hello. ft\n");

	//llist_travel(NULL, print_data);

	list = llist_create(sizeof(struct score_st));

	for(i = 0; i < 7; i++){
		student = malloc(sizeof(*student));
		student->id = i;
		snprintf(student->name, NAMESIZE, "student%d", i);
		student->math = rand() % 100;
		student->chinese = rand() % 100;

		//llist_insert(list, student, HEAD);
		llist_insert(list, student, TAIL);
	}

	llist_travel(list, print_data);

#if 0
	printf("==============================================\n");
	i = 6;

	student = llist_find(list, &i, id_cmp);
	if(student){
		print_data(student);
	}else{
		printf("can not find the node.\n");
	}
#endif

#if 0
	printf("==============================================\n");
	i = 3;

	ret = llist_delete(list, &i, id_cmp);
	if(ret == 0){
		llist_travel(list, print_data);
	}else{
		fprintf(stderr, "delete node error.\n");
	}
#endif
	printf("==============================================\n");
	s = "student2";	

	ret = llist_fetch(list, s, name_cmp, student);
	if(ret == 0){
		print_data(student);
		printf("***************************************\n");
		llist_travel(list, print_data);
	}else{
		printf("fetch record failed.\n");
	}

	

	

	return 0;
}
