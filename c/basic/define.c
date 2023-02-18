#include <stdio.h>
#include <stdlib.h>

#define PI 				3.141593
//#define ADD 			2+3
#define ADD 			(2+3)
//#define MAX(a,b)		((a) > (b) ? (a) : (b))
/*
#define MAX(a,b)		\
		({int A=a,B=b; ((A) > (B) ? (A) : (B));})
*/
#define MAX(a,b)		\
		({typeof(a) A=a,B=b; ((A) > (B) ? (A) : (B));})


#if 0
int max(int a, int b){
	return a > b ? a : b;
}
#endif



int main(){

	/*
	int a,b,c;

	a * PI;
	b + PI;
	c / PI;
	*/

	//printf("%d\n", ADD * ADD);
	
	int i = 5, j = 3;
	printf("i = %d\tj = %d\n", i, j);
	//printf("%d\n", MAX(i, j*2));
	printf("%d\n", MAX(i++, j++));
	printf("i = %d\tj = %d\n", i, j);

	exit(0);
}

