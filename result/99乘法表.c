#include <stdio.h>
int main()
{
	int k;//�����
	for (int i = 1; i <= 9; i++) 
	{
		for (int j = 1; j <= i; j++)
		{
			k = i * j;//���
			printf("%d*%d=%d\n", j, i, k);//��ӡ
		}
	}
	return 0;
}