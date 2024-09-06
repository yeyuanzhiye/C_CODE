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
//	printf("睡觉吗？(输入1表示睡，输入其他这反之):");
//	scanf("%d", &input);
//	if (input == 1) {
//		printf("你睡得很香.......");
//	}
//	else {
//		printf("你累死了！！！！！！");
//	}
//	return 0;
//}
//int main()
//{
//	int line = 1;
//	while (line < 99)
//	{
//		line++;
//		printf("等级提升！现在等级为%d\n",line);
//		if (line == 98) {
//			printf("你不幸死亡了！！！\n");
//				break;
//		}
//	}
//	if (line == 99) {
//		printf("你满级了！！！！！\n");
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
//		if (a > b )printf("%d为较大值", a);
//		else printf("%d为较大值", b);
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