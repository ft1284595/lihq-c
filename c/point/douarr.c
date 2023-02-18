#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a[2][3] = {1,2,3,4,5,6};
	int i, j;
	//int *p = a; 		//编译Warning
	int *p = &a[0][0];
	for(i=0; i<6; i++)
		printf("%d ", p[i]);
	printf("\n");
	p = *a;
	for(i=0; i<6; i++)
	{
		printf("%d ", *p);
		p++;
	}
	
#if 0
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%p->%d\n", &a[i][j], a[i][j]);

			printf("%p->%d\n", *(a+i)+j, *(*(a+i)+j));
		}
		printf("\n");
	}
#endif
	exit(0);
}
