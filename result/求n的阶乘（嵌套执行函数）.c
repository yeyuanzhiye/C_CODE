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
	printf("������n����Ϊ������׳�(������33�Ľ׳�)��");
	scanf("%u", &n);
	if (n < 0)
	{
		printf("������󣡣���");
		return -1;
	}
	sum = Print(n);
	printf("%u�Ľ׳�Ϊ%u", n, sum);
	return 0;
}
