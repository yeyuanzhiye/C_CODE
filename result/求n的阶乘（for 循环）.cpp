#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int s, i,num;
	printf("请输入整数a，将为你求出a的阶乘：");
	scanf("%d", &num);
	for (s = 1, i = 1; i < num; i++) {
		s = s * (i+1);
	}
	printf("%d的阶乘为% d\n",num,s);
	return 0;
}
