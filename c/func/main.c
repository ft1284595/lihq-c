#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("hello!\n");

	printf("sizeof(argv)=%d\n", sizeof(&argv)/sizeof(argv[0]));

	//return 0;
}


