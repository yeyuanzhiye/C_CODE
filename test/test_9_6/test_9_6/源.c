#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//int main()
//{
//	printf("c:\\code\\test111\\tests.c");
//	return 0;
//}
//int main()
//{
//	printf("%c\n", '\"');
//	printf("%s\n", "a");
//	printf("%s\n", "\'");
//	printf("%s\n", "\130");
//	printf( "\a\a\a\a\a\a\a\a");
//	return 0;
//}
//int main()
//{
//	int input = 0;
//	printf("˯����(����1��ʾ˯�����������֮ⷴ):");
//	scanf("%d", &input);
//	if (input == 1) {
//		printf("��˯�ú���.......");
//	}
//	else {
//		printf("�������ˣ�����������");
//	}
//	return 0;
//}
//int main()
//{
//	int line = 1;
//	while (line < 99)
//	{
//		line++;
//		printf("�ȼ����������ڵȼ�Ϊ%d\n",line);
//		if (line == 98) {
//			printf("�㲻�������ˣ�����\n");
//				break;
//		}
//	}
//	if (line == 99) {
//		printf("�������ˣ���������\n");
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d", a+b);
//	return 0;
//}
//Add(int x, int y,int z)
//{
//	int e = x + y+z;
//	return e;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b,&c);
//	int sum = Add(a, b,c);
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//		if (a > b )printf("%dΪ�ϴ�ֵ", a);
//		else printf("%dΪ�ϴ�ֵ", b);
//	return 0;
//}
//Add(int a) {
//    int b = 100 * a;
//    return b;
//}
//int main() {
//    int a, b;
//    scanf("%d", &a);
//    b = Add(a);
//    printf("%d", b);
//    return 0;
//}
Add(int r) {
    float  b = (4.0 / 3.0) * 3.14 * r*r*r;
    return b;
}
int main() {
    int r;
    float  v;
    scanf("%d", &r);
    v = Add(r);
    printf("%.2f", v);
    return 0;
}