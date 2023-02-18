#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926


/**
 * 百钱买百鸡:鸡翁一,值钱五; 鸡母一,值钱三; 三鸡雏,值钱一,百钱买百鸡,问: 鸡翁,鸡母,鸡雏各几何?
 *
 */
static void test1(){
	int i, j, k;

	for(i=0; i<=20; i++){
		for(j=0; j<34; j++){
			for(k=0; k<=300; k++){
				if(k % 3 == 0){
					if((i*5 + j*3 + k/3 == 100) && (i+j+k==100)){

						printf("rooster:%d, hen:%d, chick:%d\n", i, j, k);
					}
				}
			}
		}
	}
}

/**
 * 求1000以内的水仙花数
 * 	例如: 153 = 1^3 + 5^3 + 3^3
 * 				1   + 125 + 27 = 153
 *
 */
static void test2(){
	int i;
	puts("begin.");
	for(i = 1; i<1000; i++){
		int a = i / 100;
		int b = (i / 10) % 10;
		int c = i % 10;
		//printf("currnet i=%d\n", i);
		//printf("a=%d,b=%d,c=%d\n", a, b, c);
		//printf("%d\n",a*a*a + b*b*b + c*c*c);
		if((a*a*a + b*b*b + c*c*c) == i){
			printf("%d\n", i);
		}
	}
	puts("end.");
}


/**
 *	求出1000以内的所有质数
 *
 *
 */
static void test3(){
	int i, j, mark;
	for(i=2; i<1000; i++){
		mark = 1;
		for(j=2; j<i; j++){
			if(i%j == 0){
				mark = 0;
				break;
			}
		}
		//printf("mark=%d\n", mark);
		if(mark){
			printf("%d,",i);
		}
	}
}

/**
 *	在终端上实现如下输出:
 *	ABCDEF
 *	BCDEF
 *	CDEF
 *	EF
 *	F
 *
 */
static void test4(){
	int i,j;
	for(j=0; j<=5;j++){
		
		for(i=0+j; i<=5; i++){
			printf("%c",(65+i));
		}
		printf("\n");
	}


}

/**
 *
 * 	输出砖石型
 * 			*
 * 		   ***
 *		  *****
 *		 *******
 *		  *****
 * 		   ***
 *		    *
 */
static void test5(){
	int i,j,k;
	for(i=1; i<=4; i++){
		for(j=4-i; j>0; j--){
			printf(" ");
		}
		for(k=1; k<=i*2-1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	for(i=1; i<=3; i++){
		for(j=1; j<=i; j++){
			printf(" ");
		}
		for(k=1; k<=7-i*2; k++){
			printf("*");
		}
		printf("\n");
	}
}

/**
 * 从终端输入N个数(以字母Q/q作为终止), 求和.
 *
 */
static void test6(){
	int num, sum=0;
	printf("please input the number:");
	while(scanf("%d", &num) == 1){
		sum += num;

		printf("please input the number:");
	}

	printf("sum:%d\n", sum);
}

/**
 *
 *	半径由1开始增长,输出所有圆面积小于100的圆面积
 *
 *
 */
static void test7(){
	float area = 0.0f;
	for(int r=1; ; r++){
		area = PI * r * r;
		if(area > 100)
			break;
		printf("radius=%d,area=%f\n", r, area);
	}

}


int main()
{

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}

