#include <stdio.h>
#include <stdlib.h>

struct simple_st{
	int i;
	char c;
	float f;	
	char ch1;
};

struct simple1_st{
	int i;
	char c;
	float f;	
	char ch1;
}__attribute__((packed));

struct info_st{
	char c;
	//char sh;
	//short sh;
	int	sh;
	//double sh;
	char ch[9];
};

int main()
{

#if 1
	struct simple_st simple;
	struct simple1_st simple1;

	printf("sizeof(simple)=%d\n", sizeof(simple));
	printf("sizeof(simple1)=%d\n", sizeof(simple1));
#endif
#if 0
	struct info_st	info;
	printf("sizeof(char)=%d\n", sizeof(char));
	printf("sizeof(short)=%d\n", sizeof(short));
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(double)=%d\n", sizeof(double));
	printf("---------------------------------------------------\n");
	printf("sizeof(info)=%d\n", sizeof(info));
#endif

	return 0;
}
