#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a[3] = {1,2,3};
	int *p = a;
	int i;


	for(i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("a[%d] = %d\n", i, a[i]);

	printf("--------------------------------------------");
	printf("\n");
	
	printf("a[1] = %d\n", a[1]);
	printf("*(a+1)= %d\n", *(a+1));
	printf("*(p+1)= %d\n", *(p+1));
	printf("p[1]= %d\n", p[1]);

	printf("--------------------------------------------");
	printf("\n");
	
	printf("&a[1] = %p\n", &a[1]);
	printf("a+1 = %p\n", a+1);
	printf("p+1 = %p\n", p+1);
	printf("&p[1] = %p\n", &p[1]);



	exit(0);
}
