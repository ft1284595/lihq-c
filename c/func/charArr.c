#include <stdio.h>
#include <stdlib.h>

void my_strcpy(char *dest, const char *src)
{
	while(*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

int main()
{
	//char *str1 = "helloworld";
	char str1[] = "helloworld";
	char str2[128] = {0};

	printf("sizeof(str1)=%d\n", sizeof(str1));
	printf("sizeof(str2)=%d\n", sizeof(str2));

	my_strcpy(str2, str1);
	
	printf("%s\n", str2);

	return 0;
}
