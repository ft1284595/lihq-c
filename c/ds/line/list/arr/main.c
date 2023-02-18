#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main()
{
	int i;
	datatype arr[5] = {12,23,34,45,56};
	datatype arr1[5] = {34,45,56,67,78};
	sqlist *list = NULL, *list1 = NULL;

	//printf("hello world.\n");
	list = sqlist_create();
	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
		//sqlist_insert(list, 0, &arr[i]);
		sqlist_insert(list, i, &arr[i]);
	}

	sqlist_display(list);

	sqlist_create1(&list1);
	for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++){
		sqlist_insert(list1, i, &arr1[i]);
	}
	sqlist_display(list1);

	sqlist_delete(list, 2);
	sqlist_display(list);

	sqlist_union(list, list1);
	sqlist_display(list);

	return 0;
}

