#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

int main()
{
	double a, b, c;
	double s, area;
	printf("分别输入三角形三边边长（用空格分开）：");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\n");
	if (a + b > c && a + c > b && b + c > a)
	{
		// 计算半周长  
		s = (a + b + c) / 2;
		// 使用海伦公式计算面积  
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		// 输出面积  
		printf("三角形的面积是: %lf\n", area);
	}
	else printf("错误！输入的值无法构成三角形！！！");
	return 0;
}