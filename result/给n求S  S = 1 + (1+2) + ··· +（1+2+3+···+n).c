#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;//����ֵ
	int x = 0;//Ӧ��ֵ
	int S = 0;//���
	scanf("%d", &n);//����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)//��Ӧ��ֵ
		{
			x += j;
		}
		S += x;
		x = 0;//��ʼ��Ӧ��ֵ
	}
	printf("S=%d\n", S);//������
	return 0;
}