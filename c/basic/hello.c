#include <stdio.h>

int main(void){

	int *p = NULL;

	p = (int *)malloc(sizeof(int));

	if(p == NULL){
		return -1;
	}

	printf("Hello world!\n");

	exit (0);
}
