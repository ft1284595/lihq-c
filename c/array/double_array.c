#include <stdio.h>
#include <stdlib.h>

#define M 	2
#define N	3

static void change(void){

	//二维数组,行列互换
	
	int i,j;
	int a[M][N] = {1,2,3,4,5,6}, b[N][M];

	for(i=0; i<M; i++){
		for(j=0; j<N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			b[j][i] = a[i][j];
		}
	}

	printf("---------------------------------\n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}

}

/**
 * 	求二维数组中值最大的那个元素和其下标
 */
static void max(void){
	int i,j;
	int a[M][N] = {1,120,34,6,79,8};
	int max=a[0][0], x=0, y=0;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%d ", a[i][j]);
			if(a[i][j] > max){
				max = a[i][j];
				x = i;
				y = j;
			}
		}
		printf("\n");
	}

	printf("the largest element is a[%d][%d]=%d\n", x, y, max);
}

/**
 * 求二维数组各行和各列的和
 *
 */
static void sum(void){
	int i, j;
	int rowSum, colSum = 0;
	int a[M][N] = {1,2,3,4,5,6};
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			rowSum += a[i][j];
		}
		printf("row%dSum=%d\n", i, rowSum);
		rowSum = 0;
	}

	for(j=0; j<N; j++){
		for(i=0; i<M; i++){
			colSum += a[i][j];
		}
		printf("col%dSum=%d\n", j, colSum);
		colSum = 0;
	}


}

/**
 * 求二维数组各行和各列的和
 *    tips: 将所要计算的矩阵扩大一行和一列,
 *    新增的这一行一列中存放矩阵每行和每列的和
 *    二维数组的最后一个元素可以用来计算整个矩阵的和
 */
static void sum1(void){
	//假设我们要计算4x3大小的矩阵,那么我们的二维数组应该是5x4的大小
	int a[5][4] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int i,j;

	for(i=0; i<4; i++){
		for(j=0; j<3; j++){
			a[4][3] += a[i][j];
			a[i][3] += a[i][j];
			a[4][j] += a[i][j];
		}
	}

	for(i=0; i<5; i++){
		for(j=0; j<4; j++){
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

/**
 * 矩阵相乘最重要的方法是一般矩阵乘积
 * 它只有在第一个矩阵的列数（column）和第二个矩阵的行数（row）相同时才有意义
 * 一般单指矩阵乘积时，指的便是一般矩阵乘积。一个m×n的矩阵就是m×n个数排成m行n列的一个数阵
 * 设A为 m x p 的矩阵，B为 p x n 的矩阵，那么称 m x n 的矩阵C为矩阵A与B的乘积，记作C=AB
 * 
 * https://www.ruanyifeng.com/blog/2015/09/matrix-multiplication.html
 *
 */
static void mul(void){
	int a[2][3] = {1,2,3,4,5,6};
	int b[3][2] = {7,8,9,10,11,12};
	int c[2][2] = {0};
	int i,j,k;

	for(i=0; i<2; i++){
		for(k=0; k<2; k++){
			for(j=0; j<3; j++){
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}

	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%4d", c[i][j]);
		}
		printf("\n");
	}

}

int main(void){

	//change();
	//max();
	//sum();
	//sum1();
	mul();
	return 0;
}
