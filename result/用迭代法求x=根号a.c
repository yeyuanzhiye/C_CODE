#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double a, x0, x1;
    int iteration = 0; // 用于记录迭代次数  
    printf("请输入一个非负数: ");
    scanf("%lf", &a);// 输入要计算平方根的数 a  

    // 检查输入是否为非负数  
    if (a < 0) {
        printf("错误: 不能计算负数的平方根。\n");
        return 1; // 返回非零值表示错误  
    }

    x0 = a / 2.0;// 初始猜测值

    // 迭代计算平方根  
    do {
        x1 = 0.5 * (x0 + a / x0); // 使用迭代公式计算新的x1  
        iteration++; // 增加迭代次数  

        // 检查x1和x0之间的差异是否小于阈值  
        if (x1 - x0 < 1e-5 && x0 - x1 < 1e-5) {
            break; // 如果差异在阈值范围内，则停止迭代  
        }

        x0 = x1; // 更新x0为x1的值以便进行下一次迭代  
    } while (1); // 无限循环

    // 输出结果  
    printf("平方根约为: %lf\n", x1);
    printf("迭代次数: %d\n", iteration);

    return 0; // 返回零表示成功  
}