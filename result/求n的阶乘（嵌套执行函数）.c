#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Print(unsigned int n)
{
	int sum = 0;
	if (n > 0)
	{
		sum = n * Print(n - 1);
	}
	else
	{
		return 1;
	}
	return sum;
}
int main()
{
	unsigned int n = 0;
	unsigned int sum = 0;
	printf("请输入n，将为你求其阶乘(至多求33的阶乘)：");
	scanf("%u", &n);
	if (n < 0)
	{
		printf("程序错误！！！");
		return -1;
	}
	sum = Print(n);
	printf("%u的阶乘为%u", n, sum);
	return 0;
}
