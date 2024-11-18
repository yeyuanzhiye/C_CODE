#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdbool.h>  

bool isPrime(int num) {// �ж�һ�����Ƿ�Ϊ�����ĺ���  
    if (num <= 1) {
        return false; // С�ڻ����1������������  
    }
    for (int i = 2; i * i <= num; i++) { // ��2��ʼ��鵽sqrt(num)������ȡΪi  
        if (num % i == 0) { // ���num�ܱ�i����  
            return false; // ��num��������  
        }
    }
    return true; // ���ѭ��������û���ҵ���������������num������  
} 

int main() {
    int lower, upper;
    // ���������Χ�����޺�����  
    printf("�����������Χ������: ");
    scanf("%d", &lower);
    printf("�����������Χ������: ");
    scanf("%d", &upper);
    // ���������Χ�ڵ���������  
    printf("�ڷ�Χ %d �� %d �ڵ�������:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}