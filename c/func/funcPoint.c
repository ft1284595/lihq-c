#include <stdio.h>
#include <stdlib.h>

#define M 5

/*
 * 指针函数
 */
int * findElement(int *a, int index)
{
	return a+index;
}


int add(int a, int b){

	return a+b;
}

int sub(int a, int b){
	return a-b;
}

void printArr(int *a, int length)
{
	int i;
	for(i=0; i<length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
#if 0
	int *res;
	//指向指针函数的函数指针
	int *(*p)(int*, int);

	int a[M] = {1,2,3,4,5};
	printArr(a, M);
	res = findElement(a, 2);
	*res = 7;
	printArr(a, M);
	p = &findElement;
	res = p(a,1);
	*res = 25;
	printArr(a, M);
#else
	//函数指针数组
	int (*funcArr[2])(int, int);
	int i;
	funcArr[0] = add;
	funcArr[1] = sub;

	for(i=0; i<2; i++)
	{
		printf("funcArr[%d]()=%d\n",i,funcArr[i](3,5));
	}
#endif
	

	return 0;
}
