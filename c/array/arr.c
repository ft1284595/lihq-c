#include <stdio.h>
#include <stdlib.h>

int main()
{

#if 0
	int a[5] = {1,2,3,4,5};

	printf("a=%p\n", a);
	printf("&a[0]=%p\n", &a[0]);
	printf("&a[0]+1=%p\n", &a[0]+1);
	printf("&a=%p\n", &a);
	printf("&a+1=%p\n", &a+1);
#endif

	int a[3][2] = {1,2,3,4,5,6};
	printf("a=%p\n", a);
	printf("&a=%p\n", &a);
	printf("a[0]=%p\n", a[0]);
	printf("a[1]=%p\n", a[1]);
	printf("*a[1]=%d\n", *a[1]);
	printf("&a[0]=%p\n", &a[0]);
	printf("&a[1]=%p\n", &a[1]);
	printf("(&a)[1]=%p\n", (&a)[1]);
	printf("*a=%p\n", *a);
	printf("&a[0][0]=%p\n", &a[0][0]);
	printf("================================================\n");
	printf("a+1=%p\n", a+1);
	printf("&a+1=%p\n", &a+1);
	printf("&a[0]+1=%p\n", &a[0]+1);
	exit(0);
}
