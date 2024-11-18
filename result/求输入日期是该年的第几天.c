#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 判断是否为闰年  
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // 是闰年  
    }
    else {
        return 0; // 不是闰年  
    }
}

int main() {
    int year, month, day;
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayOfYear = 0;
    int judgment;

    // 从键盘输入日期  
    printf("请输入日期（格式：YYYY-MM-DD）: ");
    scanf("%d-%d-%d", &year, &month, &day);

    // 检查输入的月份是否在合理范围内  
    if (month < 1 || month > 12) {
        printf("月份输入错误！\n");
        return 1; // 非正常退出  
    }

    // 检查输入的天数是否在合理范围内  
    judgment = isLeapYear(year);
    if (judgment) {
        daysInMonth[1] = 29; // 如果是闰年，则2月有29天  
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        printf("天数输入错误！\n");
        return 1; // 非正常退出  
    }

    // 计算是该年的第几天  
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    dayOfYear += day;

    // 输出结果  
    printf("输入的日期%d-%02d-%02d是该年的第%d天。\n", year, month, day, dayOfYear);
    return 0; // 正常退出  
}