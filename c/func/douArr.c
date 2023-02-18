#include <stdio.h>
#include <stdlib.h>

#define M	3
#define N	4


/**
 *
 * 将二维数组看做一个大的一位数组来打印
 * 缺点就是不能体现出来行的边界
 * 数组作为形参会退化为指针, 所以不能用sizeof来计算数组的长度
 * sizeof(数组名) = 指针的大小
 *
 */
void print_arr1(int *p, int n)
{
	int i;
	for(i=0; i<n; i++)
		//printf("%d ", *(p+i));
		printf("%d ", p[i]);

	printf("\n");
}

/**
 * 二维数组体现不出来行的边界肯定不好用,
 * 要体现出行的边界,就得用数组指针做形参来接受参数
 * 数组指针中列的数值是确定的,
 * 然后还要传过来有几行
 */
void print_arr2(int (*p)[N], int r)
{
	int i,j;
	for(i=0; i<r; i++)
	{
		for(j=0; j<N; j++)
		{
			//printf("%-4d ", p[i][j]);
			printf("%-4d", *(*(p+i)+j));
		}
		printf("\n");
	}
}

int main()
{

	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};

	//print_arr1(*a, M*N);
	//print_arr1(a[0], M*N);
	print_arr2(a, M);
#if 0
	int i,j;

	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%-4d ", a[i][j]);
		}
		printf("\n");
	}
#endif
	return 0;
}
