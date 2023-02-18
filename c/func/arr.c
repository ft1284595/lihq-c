#include <stdio.h>
#include <stdlib.h>

void func(int *p, int n)
{
	int i = 0;
	int tmp;
	for(i=0; i<n/2; i++)
	{
		tmp = p[i];
		p[i] = p[n-1-i];
		p[n-1-i] = tmp; 
	}
}

int main()
{
	int a[] = {1,3,5,7,9};
	int i;
	for(i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");
	func(a, sizeof(a)/sizeof(*a));
	for(i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
