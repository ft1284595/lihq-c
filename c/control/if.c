#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a = 1, b = 1, c = 2;

	if(a == b){
		if(b == c)
			printf("a == b == c\n");
	}
	else
		printf("a != b\n");
	
	
	exit(0);
}
