#include <stdio.h>
#include <stdlib.h>

/**
 *
 * 指针常量和常量指针
 *
 * int * const p;
 * 
 * const int *p;
 * int const *p;
 *
 * const int * const p;
 *
 */
int main()
{
	//const int i = 1;
	int i = 1;
	int j = 10;

	const int* p = &i;
	//int * const p = &i;
	//*p = 102;
	p = &j;

	printf("i=%d\n", i);
	printf("*p=%d\n", *p);



	exit(0);
}
