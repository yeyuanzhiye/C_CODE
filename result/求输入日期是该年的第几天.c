#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ж��Ƿ�Ϊ����  
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // ������  
    }
    else {
        return 0; // ��������  
    }
}

int main() {
    int year, month, day;
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dayOfYear = 0;
    int judgment;

    // �Ӽ�����������  
    printf("���������ڣ���ʽ��YYYY-MM-DD��: ");
    scanf("%d-%d-%d", &year, &month, &day);

    // ���������·��Ƿ��ں���Χ��  
    if (month < 1 || month > 12) {
        printf("�·��������\n");
        return 1; // �������˳�  
    }

    // �������������Ƿ��ں���Χ��  
    judgment = isLeapYear(year);
    if (judgment) {
        daysInMonth[1] = 29; // ��������꣬��2����29��  
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        printf("�����������\n");
        return 1; // �������˳�  
    }

    // �����Ǹ���ĵڼ���  
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    dayOfYear += day;

    // ������  
    printf("���������%d-%02d-%02d�Ǹ���ĵ�%d�졣\n", year, month, day, dayOfYear);
    return 0; // �����˳�  
}