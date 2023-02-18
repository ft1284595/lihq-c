#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"

int main()
{
	int i, ret;
	struct node_st *list = NULL;
	struct score_st *data = NULL;
	struct score_st *tmp = NULL;
//printf("%s------>lineNum:%d\n",__FUNCTION__, __LINE__);
	for(i = 0; i < 7; i++){
		data = malloc(sizeof(*data));	
		if(data == NULL)
			exit(-1);
		data->id = i;
		snprintf(data->name, (NAMESIZE-1), "student%d", i);
		data->math = rand() % 100; 
		data->chinese = rand() % 100;

		ret = list_insert(&list, data);
		if(ret != 0){
			fprintf(stderr, "list_insert error, return code is %d\n", ret);
			exit(-2);
		}

	}

	list_show(list);
	printf("===============================================\n");
	list_delete(&list);
	list_show(list);

	printf("===============================================\n");
	tmp = list_find(list, 1);
	if(tmp != NULL)
		printf("%d %s %d %d\n", tmp->id, tmp->name, tmp->math, tmp->chinese);
	
	list_destory(list);
	

	exit(0);
}
