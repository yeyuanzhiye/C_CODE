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
	printf("����nֵ����Ϊ�����쳲��������еĵ�n�");
	scanf("%u", &n);
	if (n < 1)
	{
		printf("������������������ֵ����");
		return -1;
	}
	printf("쳲��������еĵ�%u��Ϊ%u", n, fibonacci(n));
	return 0;
}