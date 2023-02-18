#include <stdio.h> 
#include <stdlib.h>


/**
 *	求斐波那契数列的前10项,并倒序打印
 */
#define LENGTH 10
static void fibonacci(void)
{

	int fib[LENGTH]	= {1,1};
	int i, j, temp;
	for(i=2; i<sizeof(fib)/sizeof(fib[0]); i++){
		fib[i] = fib[i-1] + fib[i-2];
	}

	for(i=0; i<sizeof(fib)/sizeof(fib[0]); i++){
		printf("%d ", fib[i]);
	}
	printf("\n");

	printf("--------------------------------------\n");
	//逆序
	for(i=0, j=(sizeof(fib)/sizeof(fib[0])-1); i<j; i++,j--){
		temp = fib[i];
		fib[i] = fib[j];
		fib[j] = temp;
	}

	for(i=0; i<sizeof(fib)/sizeof(fib[0]); i++){
		printf("%d ", fib[i]);
	}	
	printf("\n");
}

/**
 *
 *	冒泡排序
 */
static void sort1(void){
	int arr[9] = {5,4,7,9,3,8,1,2,6};
	int i,j,temp;

	printf("original array:");
	for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	for(i=0; i<8; i++){
		for(j=0; j<9-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];	
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}


	printf("sorted array:");
	for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * 	选择排序
 *
 */
static void sort2(void){
	//int arr[9] = {5,4,7,9,3,8,1,2,6};
	int arr[9] = {57,40,11,90,13,8,19,2,6};
	int i,j,min,temp;
	int length = sizeof(arr)/sizeof(arr[0]);

	printf("original array:");
	for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
	for(i=0; i<(length-1); i++){
		min = i;
		for(j=i+1; j<=(length-1); j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}	
		if(min != i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	printf("sorted array:");
	for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/**
 * 	进制转换
 *
 */
static void convert_base(void){
	int i=0, num,base;
	int a[256];

	printf("please input a number:");
	scanf("%d", &num);
	printf("please input base:");
	scanf("%d", &base);

	while(num != 0){
		a[i] = num % base;
		num = num / base;
		i++;
	}
#if 0
	for(i--; i>=0; i--){
		if(a[i]>=10){
			printf("%c",a[i]-10+'A');
		}else
			printf("%d", a[i]);
	}
#endif
		i--;

	do{
		if(a[i]>=10){
			printf("%c",a[i]-10+'A');
		}else
			printf("%d", a[i]);
		i--;
	}while(i>=0);

	printf("\n");
	for(int j=0; j<10; j++){
		printf("%d ",a[j]);
	}
	printf("\n");

}

/**
 * 排除法求1000以内的质数
 */
static void prime_number(){
	int a[1001] = {0};
	int i,j;
	for(i=2; i<1001/2; i++){
		for(j=i*2; j<1001; j+=i){
			if(a[j] == 0){
				a[j] = -1;
			}
		}
	}

	for(i=2; i<1001; i++){
		if(a[i] == 0){
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(void){


	//fibonacci();
	
	//sort1();

	//sort2();
	
//	convert_base();

	prime_number();

	return 0;
}
