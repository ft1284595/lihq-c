#include <stdio.h>
#include <stdlib.h>

void func(){
	int x = 0;
	x = x + 1;
	printf("%p->%d\n", &x, x);
}

int main(){

	/*
	auto int i;
	int j;

	printf("i = %d\n", i);
	printf("j = %d\n", j);
	*/

	func();
	func();
	func();

	exit(0);
}
