#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func1()
{
	printf("this is func1()....\n");
}

void func2()
{
	printf("this is func2()....\n");
}


int main()
{
	printf("main start.\n");
	
	atexit(func1);
	atexit(func2);

	printf("main end.\n");
	_exit(10);
	//exit(0);
	//return 0;
}
