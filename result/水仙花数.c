#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  

int main() {
    int T = 0; // 求解次数  
    int have = 0;//标志是否找到了水仙花数
    printf("请输入进行几次求取指定范围内的水仙花数: ");
    scanf("%d", &T);
    while (T > 0) {
        int m, n; // 范围两端值  
        int a, b, c; // 个位，十位，百位  
        printf("请输入范围两端值(前者不能大于后者且都在100到999之间)，用空格分开: ");
        scanf("%d %d", &m, &n);
        if (m > 999 || m < 100 || n > 999 || n < 100 || m > n) {
            m = 0;//初始化
            n = 0;//初始化
            printf("输入的范围无效，请重新输入或检查范围值。\n");
            continue; // 跳过当前循环的剩余部分，回到while的开始  
        }
        for (int i = m; i <= n; i++) { // 遍历范围m到n，查找水仙花数  
            a = i % 10; // 个位  
            b = (i / 10) % 10; // 十位，先除以10去掉个位，再对10取模  
            c = i / 100; // 百位，直接除以100  
            if (i == a * a * a + b * b * b + c * c * c) {
                printf("%d是一个水仙花数\n", i);
                 have = 1;//范围内找到了水仙花数
            }
        }
        if (have==1) {
            printf("在当前范围内找到了水仙花数。\n");
            have = 0;//初始化
        }
        else {
            printf("在当前范围内没有找到水仙花数。\n");
        }
        T--; // 减少求解次数  
    }
    return 0;
}