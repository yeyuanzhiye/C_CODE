#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    // ����һ��ѧ���ĳɼ�����  
    int student1_scores[] = { 85, 90, 78, 92, 88 };
    int n = sizeof(student1_scores) / sizeof(student1_scores[0]);//�ɼ�����

    // ���ѧ��1�ĳɼ�  
    printf("ѧ��1�ĳɼ�:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", student1_scores[i]);
    }
    printf("\n\n");

    // ��������ѧ���ɼ�������  
    int student_num = 3;// ����ѧ������
    int all_scores[3][5] = {
        {85, 90, 78, 92, 88}, // ѧ��1�ĳɼ�  
        {76, 84, 91, 87, 79}, // ѧ��2�ĳɼ�  
        {89, 77, 82, 85, 93}  // ѧ��3�ĳɼ�  
    };

    // ��������ѧ���ĳɼ�  
    for (int k = 0; k < 3; k++) {//�����k+1��ѧ���ĳɼ�
    	for (int i = 0; i < n - 1; i++) {//ð������
		for (int j = 0; j < n - i - 1; j++) {
			if (all_scores[k][j] > all_scores[k][j + 1]) {
				// ����λ��
				int temp = all_scores[k][j];
                all_scores[k][j] = all_scores[k][j + 1];
                all_scores[k][j + 1] = temp;
			}
		}
	}
    }
    // �������ѧ���ĳɼ�  
    printf("����ѧ���ĳɼ�:\n");
    for (int i = 0; i < student_num; i++) {
        printf("ѧ��%d�ĳɼ�: ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%d ", all_scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


//int main()
//{
//	int a[10] = { 1,1 };
//	for (int i = 2; i < 10; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//int main() {
//	int numbers[5] = { 64, 25, 12, 22, 11 }, n = 5;; // ��������ͳ���
//	// ð������
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (numbers[j] > numbers[j + 1]) {
//				// ����λ��
//				int temp = numbers[j];
//				numbers[j] = numbers[j + 1];
//				numbers[j + 1] = temp;
//			}
//		}
//	}
//		// �������������
//		printf("����������: ");
//	for (int i = 0; i < n; i++) {
//		printf("%d ", numbers[i]);
//	}
//	return 0;
//}