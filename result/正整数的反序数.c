#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long num=0;//��ʼ��ԭʼ���ֺ��䷴����
    long long a=0;//��ʼ��ԭʼ���ֺ��䷴����
    printf("����һ��������: ");
    scanf("%d", &num);//����
    while (num != 0) {
        int b = num % 10;//ȡ��ԭʼ�����м�ֵ�����һλ
        a = a * 10 + b;//�����������м�ֵ�������������ƣ��ұ߲�b
        num /= 10;//ȥ����ԭʼ�����м�ֵ�����һλ
    }
    printf("������: %d\n", a);//���
    return 0;
}