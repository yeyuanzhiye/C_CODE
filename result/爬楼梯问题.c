#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int zhoufa(unsigned int n)//计算n级楼梯走法，相当于第二项为2的斐波那契数列
{
	unsigned int sum = 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return zhoufa(n - 1) + zhoufa(n - 2);//到达第n级是从的n-1级走一步或从第n-2级走两步，即等于走n-1和n-2级的走法之和
}

 int main()
{
	unsigned int n;
	printf("一个人爬楼梯，他每次可以走1级或者2级，输入楼梯的级数，求不同走法数：\n");
	scanf("%u",&n);
	if (n < 1)
	{
		printf("程序错误，请检查你的输入值！！\n");
		return -1;
	}
	printf("级数为%u的楼梯有%u种走法", n, zhoufa(n));
	return 0;
}