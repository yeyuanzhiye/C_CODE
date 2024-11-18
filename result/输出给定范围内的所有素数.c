#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdbool.h>  

bool isPrime(int num) {// 判断一个数是否为素数的函数  
    if (num <= 1) {
        return false; // 小于或等于1的数不是素数  
    }
    for (int i = 2; i * i <= num; i++) { // 从2开始检查到sqrt(num)的整数取为i  
        if (num % i == 0) { // 如果num能被i整除  
            return false; // 则num不是素数  
        }
    }
    return true; // 如果循环结束都没有找到能整除的数，则num是素数  
} 

int main() {
    int lower, upper;
    // 输入给定范围的下限和上限  
    printf("请输入给定范围的下限: ");
    scanf("%d", &lower);
    printf("请输入给定范围的上限: ");
    scanf("%d", &upper);
    // 输出给定范围内的所有素数  
    printf("在范围 %d 到 %d 内的素数是:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}