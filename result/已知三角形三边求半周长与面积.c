#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

int main()
{
	double a, b, c;
	double s, area;
	printf("�ֱ��������������߱߳����ÿո�ֿ�����");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\n");
	if (a + b > c && a + c > b && b + c > a)
	{
		// ������ܳ�  
		s = (a + b + c) / 2;
		// ʹ�ú��׹�ʽ�������  
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		// ������  
		printf("�����ε������: %lf\n", area);
	}
	else printf("���������ֵ�޷����������Σ�����");
	return 0;
}