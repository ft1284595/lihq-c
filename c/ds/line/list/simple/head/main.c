#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
	node *head = NULL;
	datatype arr[] = {7, 12, 8, 10, 56, 23};
	//datatype arr[] = {12,23,34,45,56};
	int num = 78;
	int num1 = 100;
	int i;
	int value;

	printf("sizeof(node)=%d\n", sizeof(node));
#if 0
	printf("hello makefile.\n");
	printf("sizeof(*head)=%d\n", sizeof(*head));
	printf("sizeof(head)=%d\n", sizeof(head));
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(datatype)=%d\n", sizeof(datatype));
#endif
	head = list_create();
	for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
		//list_order_insert(head, &arr[i]);
		//list_insert_at(head, i, &arr[i]);
		list_order_insert(head, &arr[i]);
	}

	list_display(head);

	//list_insert_at(head, 0, &num);
	list_insert_at(head, 5, &num);
	list_display(head);


	value = 0;
	list_delete_at(head, 2, &value);
	printf("the deleted node value = %d\n", value);
	list_display(head);

	list_delete(head, &num);
	list_display(head);

	list_order_insert(head, &num1);

	list_display(head);

	num1 = 50;
	list_order_insert(head, &num1);
	list_display(head);

	list_destory(head);


	exit(0);
}
