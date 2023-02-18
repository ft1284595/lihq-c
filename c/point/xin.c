#include <stdio.h>
#include <stdlib.h>



int main()
{
	int a[2][3] = {1,2,3,4,5,6};
	int **p = NULL;

	p = (int **)a;
	printf("sizeof(p)=%d\n", sizeof(p));
	printf("(int)*p=%d\n", (int)*p);
	p++;
	printf("(int)*p=%d\n", (int)*p);
	p++;
	printf("(int)*p=%d\n", (int)*p);

	exit(0);
}

#if 0
int main()
{
	int a[2][3] = {1,2,3,4,5,6};
	int **p = NULL;

	p = a;

	exit(0);
}
#endif

#if 0
//使用数组指针遍历3维数组
int main()
{
	int a[2][3][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
	int (*p)[3][4] = a;
	int i,j,k;

	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			for(k=0; k<4; k++){
				printf("%d\n", (*(*(p+i)+j))[k]);
			}
		}
	}

	exit(0);
}
#endif

#if 0
//使用指针遍历二维数组
int main()
{
	int a[2][3] = {1,2,3,4,5,6};
	int (*p)[3] = a;
	int i,j;

	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			//printf("%d ", (*(p+i))[j]);
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}

	exit(0);
}
#endif
