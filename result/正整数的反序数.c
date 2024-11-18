#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long num=0;//初始化原始数字和其反序数
    long long a=0;//初始化原始数字和其反序数
    printf("输入一个正整数: ");
    scanf("%d", &num);//输入
    while (num != 0) {
        int b = num % 10;//取“原始数字中间值”最后一位
        a = a * 10 + b;//将“反序数中间值”所有数字左移，右边补b
        num /= 10;//去除“原始数字中间值”最后一位
    }
    printf("反序数: %d\n", a);//输出
    return 0;
}