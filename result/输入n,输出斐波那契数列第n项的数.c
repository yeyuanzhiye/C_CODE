#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int fibonacci(unsigned int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	unsigned int n;
	printf("输入n值，将为你求出斐波那契数列的第n项：");
	scanf("%u", &n);
	if (n < 1)
	{
		printf("程序错误，请检查你的输入值！！");
		return -1;
	}
	printf("斐波那契数列的第%u项为%u", n, fibonacci(n));
	return 0;
}