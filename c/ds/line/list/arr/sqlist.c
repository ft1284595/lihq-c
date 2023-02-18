#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"



sqlist *sqlist_create(){
	sqlist *me = NULL;
	//printf("%ld\n", sizeof(sqlist));
	me = malloc(sizeof(sqlist));
	//me = malloc(-100);
	if(me == NULL){
		fprintf(stderr, "malloc for sqlist failed.\n");
		exit(-1);
	}
	me->last = -1;

	return me;
}

void sqlist_create1(sqlist **me){
	*me = malloc(sizeof(sqlist));
	if(*me == NULL){
		fprintf(stderr, "create1 malloc for sqlist failed.\n");
		exit(-1);
	}
	(**me).last = -1;
	return;
}

int sqlist_insert(sqlist *me, int index, datatype *data){
	int i;
	if(me == NULL){
		fprintf(stderr,"sqlist is NULL.\n");
		return -1;
	}
	if(index < 0 || index > DATASIZE){
		fprintf(stderr, "index is out of range.\n");
		return -2;
	}else if(index > me->last+1){
		fprintf(stderr, "you can not skip insert.\n");
		return -3;
	}else{
		for(i=me->last; i>=index; i--){
			me->data[i+1] = me->data[i];
		}
		me->data[index] = *data;
		me->last ++;
	}

	return 0;
}

int sqlist_delete(sqlist *me, int i){
	int j;
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
		return -1;
	}
	if(i < 0 || i > DATASIZE){
		fprintf(stderr, "the index you wanna delete is out of range.");
		return -2; //
	}
	if(sqlist_isempty(me) == 0){
		fprintf(stderr, "input sqlist is a empty container.");
		return -3;
	}
	if(i > me->last){
		fprintf(stderr, "you can not delete a non-exist index in sqlist.");
		return -4;
	}

	for(j = i; j < me->last; j++){
		me->data[j] = me->data[j+1];
	}
	me->last --;
	
	return 0;
}

int sqlist_find(sqlist *me, datatype *data){
	int i=0; 
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
		return -1;
	}
	while(i <= me->last){
		if(*data == me->data[i]){
			return i;
		}
		i++;
	}
	return -2;		// can not find the given data in sqlist
}

int sqlist_isempty(sqlist *me){
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
		return -1;
	}
	if(me->last != -1){
		return -2;		//sqlist has some elements.
	}
	return 0;
}

int sqlist_setempty(sqlist *me){
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
		return -1;
	}
	me->last = -1;
	return 0;
}

int sqlist_getnum(sqlist *me){
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
		return -1;
	}
	return me->last+1;
}


void sqlist_display(sqlist *me){
	int i;
	if(me == NULL){
		fprintf(stderr, "The input sqlist is NULL.\n");
	}

	for(i = 0; i <= me->last; i++){
		printf("%d ", me->data[i]);
	}
	printf("\n");
}

int sqlist_destory(sqlist *me){
	if(me == NULL){
		fprintf(stderr, "input sqlist is NULL, can not destory.\n");
		
		return -1;
	}

	free(me);
	
	return 0;

}

int sqlist_union(sqlist *list1, sqlist *list2){
	int i;
	if(list1 == NULL || list2 == NULL ){
		fprintf(stderr, "list1 is null or list2 is null.");
		return -1;
	}

	for(i = 0; i <= list2->last; i++){
		if(sqlist_find(list1, &list2->data[i]) == -2){
			sqlist_insert(list1, 0, &list2->data[i]);
		}
	}

	return 0;
}
