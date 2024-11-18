#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;//输入值
	int x = 0;//应加值
	int S = 0;//结果
	scanf("%d", &n);//输入
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)//求应加值
		{
			x += j;
		}
		S += x;
		x = 0;//初始化应加值
	}
	printf("S=%d\n", S);//输出结果
	return 0;
}