#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

int main() {
    double sum = 0.0;// �����  
    int n = 1000000; // ���������������������Խ�࣬���Խ��ȷ   
    int sign = 1; // �����������ʾ��ǰ��ķ��ţ�1��-1�� 
    // ʹ��ѭ�������㼶���ĺ�  
    for (int i = 0; i < n; i++) {
        sum += sign * (1.0 / (2.0 * i + 1));
        // �л�����  
        sign = -sign;
    }
    // ͨ������4���õ��еĽ���ֵ  
    double pi = sum * 4;
    // ������  
    printf("ʹ��%d��õ��ĦеĽ���ֵ��: %.50f\n", n, pi);
    return 0;
}