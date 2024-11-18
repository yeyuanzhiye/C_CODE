#include <stdio.h>  
#include <math.h>  
int main() {
    double d = 300000.0; // 剩余贷款金额  
    double p = 6000.0;   // 每月还款额  
    double r = 0.01;     // 月利率  
    double m = 0;      // 还款月数  
    while (d > 0) {
        d = d * (1 + r) - p;
        m++;
        if (d <= 0) {
            break;
        }
    }
    m = round(m * 10.0) / 10.0;
    printf("需要还款的月数: %.1f\n", m);
    return 0;
}