#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 求两个数的最大公约数  
int gongyue(int a, int b) {//两个整数的最大公约数等于其中较小的数和这两个数相除余数的最大公约数
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 求两个数的最小公倍数  
int gongbei(int a, int b) {//两个数的最小公倍数可以通过它们的乘积除以它们的最大公约数来计算
    int gcd = gongyue(a, b);
    return (a * b) / gcd;
}

int main()
{
	int a, b;
	printf("分别输入两个整数,将输出这两个数的最大公约数和最小公倍数：\n");
    scanf("%d %d", &a, &b);
	printf("%d和%d最大公约数和最小公倍数分别为%d和%d\n", a, b, gongyue(a, b), gongbei(a, b));
	return 0;
}