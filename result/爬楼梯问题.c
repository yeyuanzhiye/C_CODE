#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int zhoufa(unsigned int n)//����n��¥���߷����൱�ڵڶ���Ϊ2��쳲���������
{
	unsigned int sum = 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return zhoufa(n - 1) + zhoufa(n - 2);//�����n���Ǵӵ�n-1����һ����ӵ�n-2������������������n-1��n-2�����߷�֮��
}

 int main()
{
	unsigned int n;
	printf("һ������¥�ݣ���ÿ�ο�����1������2��������¥�ݵļ�������ͬ�߷�����\n");
	scanf("%u",&n);
	if (n < 1)
	{
		printf("������������������ֵ����\n");
		return -1;
	}
	printf("����Ϊ%u��¥����%u���߷�", n, zhoufa(n));
	return 0;
}