#include <stdio.h>
#include <stdlib.h>

union test_un {
	short s1;
	int i;
	short s2;
};

int main()
{
	printf("sizeof(int)=%d\n", sizeof(int));
	union test_un t1;
	t1.i = 0x1234578;
	printf("s1=%x\n",t1.s1);
	printf("s2=%x\n",t1.s2);
	return 0;
}
