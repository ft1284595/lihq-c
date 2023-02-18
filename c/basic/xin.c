#include <stdio.h>
#include <stdlib.h>

//#define ADD 	2+3
//#define MAX(a, b)  a > b ? a : b
#define MAX(a, b)  (a) > (b) ? (a) : (b)

int main(){

	int i=5, j=3;
	//printf("%d\n", ADD);

	printf("i = %d\tj=%d\n", i, j);
	//printf("%d\n", MAX(i, j));
	printf("%d\n", MAX(i++, j++));
	printf("i = %d\tj=%d\n", i, j);
	exit(0);
}
