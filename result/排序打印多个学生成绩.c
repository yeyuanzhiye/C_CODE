#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    // 定义一个学生的成绩数组  
    int student1_scores[] = { 85, 90, 78, 92, 88 };
    int n = sizeof(student1_scores) / sizeof(student1_scores[0]);//成绩个数

    // 输出学生1的成绩  
    printf("学生1的成绩:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", student1_scores[i]);
    }
    printf("\n\n");

    // 定义所有学生成绩的数组  
    int student_num = 3;// 设置学生个数
    int all_scores[3][5] = {
        {85, 90, 78, 92, 88}, // 学生1的成绩  
        {76, 84, 91, 87, 79}, // 学生2的成绩  
        {89, 77, 82, 85, 93}  // 学生3的成绩  
    };

    // 排序所有学生的成绩  
    for (int k = 0; k < 3; k++) {//排序第k+1个学生的成绩
    	for (int i = 0; i < n - 1; i++) {//冒泡排序
		for (int j = 0; j < n - i - 1; j++) {
			if (all_scores[k][j] > all_scores[k][j + 1]) {
				// 交换位置
				int temp = all_scores[k][j];
                all_scores[k][j] = all_scores[k][j + 1];
                all_scores[k][j + 1] = temp;
			}
		}
	}
    }
    // 输出所有学生的成绩  
    printf("所有学生的成绩:\n");
    for (int i = 0; i < student_num; i++) {
        printf("学生%d的成绩: ", i + 1);
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
//	int numbers[5] = { 64, 25, 12, 22, 11 }, n = 5;; // 定义数组和长度
//	// 冒泡排序
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (numbers[j] > numbers[j + 1]) {
//				// 交换位置
//				int temp = numbers[j];
//				numbers[j] = numbers[j + 1];
//				numbers[j + 1] = temp;
//			}
//		}
//	}
//		// 输出排序后的数组
//		printf("排序后的数组: ");
//	for (int i = 0; i < n; i++) {
//		printf("%d ", numbers[i]);
//	}
//	return 0;
//}