#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

int main() {
    double sum = 0.0;// 定义和  
    int n = 1000000; // 定义迭代次数，迭代次数越多，结果越精确   
    int sign = 1; // 定义变量来表示当前项的符号（1或-1） 
    // 使用循环来计算级数的和  
    for (int i = 0; i < n; i++) {
        sum += sign * (1.0 / (2.0 * i + 1));
        // 切换符号  
        sign = -sign;
    }
    // 通过乘以4来得到π的近似值  
    double pi = sum * 4;
    // 输出结果  
    printf("使用%d项得到的π的近似值是: %.50f\n", n, pi);
    return 0;
}