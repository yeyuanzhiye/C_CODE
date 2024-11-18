#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 定义商品结构体  
struct Product {
    int id;       // 商品编号  
    char name[7]; // 商品名称  
    float price;  // 商品价格  
};

// 创建商品数组
struct Product products[4] = {
    {1, "可乐", 3.0},
    {2, "薯片", 4.0},
    {3, "泡面", 5.0},
    {4, "巧克力", 7.5},
};

int main() {
    int choice;      // 用户选择的商品编号  
    int quantity;    // 用户想要购买的数量  
    float totalCost; // 总价格  

    // 打印商品列表
    printf("欢迎来到自动贩卖机！\n");
    printf("我们有以下商品可供选择：\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s ---%.2f元\n", products[i].id, products[i].name, products[i].price);
    }

    // 让用户输入想要购买的商品编号  
    printf("请输入你想要购买的商品编号（1-4）: ");
    scanf("%d", &choice);

    // 检查用户输入的商品编号是否有效  
    int isValid = 0;
    for (int i = 0; i < 4; i++) {
        if (products[i].id == choice) {
            isValid = 1;
            break;
        }
    }
    if (!isValid) {
        printf("无效的编号，请重试。\n");
        return 1; // 退出程序  
    }

    // 让用户输入购买数量  
    printf("请输入你想要购买的数量: ");
    scanf("%d", &quantity);

    // 计算总价格  
    for (int i = 0; i < 4; i++) {
        if (products[i].id == choice) {
            totalCost = products[i].price * quantity;
            break;
        }
    }

    // 打印购买信息和总价格  
    printf("你购买了%d个%s，总价格是%.2f元。\n", quantity, products[choice - 1].name, totalCost);


    return 0;
}

//int main()
//{
//	int c;
//	printf("Enter a value:");
//	c = getchar();
//	printf("\nYou entered:");
//	putchar(c);
//	printf("\n");
//	return 0;
//} 


//int main()
//{
//	int a = 0;
//	int b = 0;
//	float c = 0;
//	scanf("%d %d %f", &a, &b, &c);
//	printf("a=%d b=%d c=%f", a, b, c);
//	return 0;
//}

//int main()
//{
//	int num =42;
//	printf("整数:%d\n", num);
//	printf("无符号整数:%u\n", (unsigned int)num);
//	printf("十六进制（小写）:%x\n", num);
//	printf("十六进制（大写）:%X\n", num);
//	printf("十六进制（小写）:%#x\n", num);
//	printf("十六进制（小写）:%#X\n", num);
//	return 0;
//}


//int main()
//{
//	int a = 97;
//	printf("数字:%d\n", a);
//	printf("对应字母:%c\n", a);
//}
//
//int main()
//{
//    int num = 0;
//    printf("本自动贩卖机:");
//    printf("请输入商品编号:");
//      scanf("%d", &num);
//      switch(num)
//      {
//          case 1:
//              printf("购买可乐成功");
//              break;
//          case 2:
//              printf("购买薯片成功");
//                  break;
//              case 3:
//                  printf("购买泡面成功");
//                  break;
//      }
//      return 0;
//}