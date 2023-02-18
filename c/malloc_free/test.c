#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void func(int **p, int num){

	*p = malloc(num);
	return ;
}



int main()
{
	int *p = NULL;
	func(&p, 10);

	free(p);

	return 0;
}
