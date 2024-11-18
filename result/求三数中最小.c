#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
mini(float a,float b,float c)
{
	return (a > b) ? ((b > c) ? c:b ): ((a > c) ? c : a);
}
int main()
{
	float a, b, c,re;
	scanf("%f %f %f", &a, &b, &c);
	re = mini(a, b, c);
	printf("%f", re);
}