#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �������������Լ��  
int gongyue(int a, int b) {//�������������Լ���������н�С��������������������������Լ��
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ������������С������  
int gongbei(int a, int b) {//����������С����������ͨ�����ǵĳ˻��������ǵ����Լ��������
    int gcd = gongyue(a, b);
    return (a * b) / gcd;
}

int main()
{
	int a, b;
	printf("�ֱ�������������,������������������Լ������С��������\n");
    scanf("%d %d", &a, &b);
	printf("%d��%d���Լ������С�������ֱ�Ϊ%d��%d\n", a, b, gongyue(a, b), gongbei(a, b));
	return 0;
}