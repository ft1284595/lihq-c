#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sqstack.h"

int get_priority(int op)
{
	switch(op)
	{
		case '+':
		case '-':
			 return 1;
		case '*':
		case '/':
			 return 2;
		case '(':
			 return 0;
	}
}

void compute(sqstack *opStack, sqstack *numStack)
{
	int num1, num2;
	int op;
	int result;
	
	st_pop(numStack, &num2);
	st_pop(numStack, &num1);
	
	st_pop(opStack, &op);

	switch(op)
	{
		case '+':
			result = num1 + num2;
			printf("%s: %d %c %d = %d\n", __FUNCTION__, num1, op, num2, result);
			break;
		case '-':
			result = num1 - num2;
			printf("%s: %d %c %d = %d\n", __FUNCTION__, num1, op, num2, result);
			break;
		case '*':
			result = num1 * num2;
			printf("%s: %d %c %d = %d\n", __FUNCTION__, num1, op, num2, result);
			break;
		case '/':
			result = num1 / num2;
			printf("%s: %d %c %d = %d\n", __FUNCTION__, num1, op, num2, result);
			break;
		default:
			exit(-9);
	}
	st_push(numStack, &result);

}

int main()
{
	//char str[] = "(11+3-0+1*2)*2-5";
	char str[] = "(11+3*3+1*2)*2-5";
	//char str[] = "1+(11+3+(0+1))*2-5";
	//char str[] = "1+(11+3+(0+1))*(2+1)-5";
	//char str[] = "1+(11+3+(0+1))*(2+1)-5*2";
	//char str[] = "1+2+3";
	int i = 0;
	int ret;
	int value = 0;
	int flag = 0;
	datatype opInStack;
	int finalRes;
	sqstack *numStack;
	sqstack *opStack;

	numStack = st_create();
	opStack = st_create();

	while(str[i] != '\0')
	{
		printf("%c\n", str[i]);
		sleep(1);
		if(str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			value = value * 10 + (str[i] - '0');
		}
		else		//+,-,*,/,(,)
		{
			if(flag)	//先把前面读到的数字入栈,然后重置flag
			{
				st_push(numStack, &value);
				flag = 0;
				value = 0;
			}
			if(str[i] == ')')		//不入栈
			{
				st_top(opStack, &opInStack);
				while(opInStack != '(')
				{
					compute(opStack, numStack);
					st_top(opStack, &opInStack);
				}
				st_pop(opStack, &opInStack);
			}
			else		//+,-,*,/,(
			{
				if(str[i] == '(')	//直接入栈, 因为(后面肯定要匹配)
				{
					int tmp = str[i];	
					st_push(opStack, &tmp);
				}
				else	//+,-,*,/ 比较栈顶符号和当前读到的符号,看谁的优先级高
				{
					if(!st_isempty(opStack))
					{
						ret = st_top(opStack, &opInStack);
						if(get_priority(str[i]) > get_priority(opInStack)) //比栈顶的优先级高
						{
							int tmp = str[i];	
							st_push(opStack, &tmp);
						}
						else
						{
							while(get_priority(str[i]) <= get_priority(opInStack))	//比栈顶的优先级低,或者优先级相同
							{

								compute(opStack, numStack);
								ret = st_top(opStack, &opInStack);
							}
							int tmp = str[i];	
							st_push(opStack, &tmp);
						}
					}
					else	//opStack是空栈
					{
						int tmp = str[i];
						st_push(opStack, &tmp);
					}
				}
			}

		}
		i++;
	}

	if(flag)
	{
		st_push(numStack, &value);
	}

	while(!st_isempty(opStack))
	{
		compute(opStack, numStack);
	}

	st_top(numStack, &finalRes);	
	printf("finalRes=%d\n", finalRes);

	st_destory(numStack);
	st_destory(opStack);
#if 0
#endif
	return 0;
}
