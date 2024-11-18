#include <stdio.h>
int main()
{
	int k;//定义积
	for (int i = 1; i <= 9; i++) 
	{
		for (int j = 1; j <= i; j++)
		{
			k = i * j;//求积
			printf("%d*%d=%d\n", j, i, k);//打印
		}
	}
	return 0;
}