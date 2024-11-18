#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������Ʒ�ṹ��  
struct Product {
    int id;       // ��Ʒ���  
    char name[7]; // ��Ʒ����  
    float price;  // ��Ʒ�۸�  
};

// ������Ʒ����
struct Product products[4] = {
    {1, "����", 3.0},
    {2, "��Ƭ", 4.0},
    {3, "����", 5.0},
    {4, "�ɿ���", 7.5},
};

int main() {
    int choice;      // �û�ѡ�����Ʒ���  
    int quantity;    // �û���Ҫ���������  
    float totalCost; // �ܼ۸�  

    // ��ӡ��Ʒ�б�
    printf("��ӭ�����Զ���������\n");
    printf("������������Ʒ�ɹ�ѡ��\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s ---%.2fԪ\n", products[i].id, products[i].name, products[i].price);
    }

    // ���û�������Ҫ�������Ʒ���  
    printf("����������Ҫ�������Ʒ��ţ�1-4��: ");
    scanf("%d", &choice);

    // ����û��������Ʒ����Ƿ���Ч  
    int isValid = 0;
    for (int i = 0; i < 4; i++) {
        if (products[i].id == choice) {
            isValid = 1;
            break;
        }
    }
    if (!isValid) {
        printf("��Ч�ı�ţ������ԡ�\n");
        return 1; // �˳�����  
    }

    // ���û����빺������  
    printf("����������Ҫ���������: ");
    scanf("%d", &quantity);

    // �����ܼ۸�  
    for (int i = 0; i < 4; i++) {
        if (products[i].id == choice) {
            totalCost = products[i].price * quantity;
            break;
        }
    }

    // ��ӡ������Ϣ���ܼ۸�  
    printf("�㹺����%d��%s���ܼ۸���%.2fԪ��\n", quantity, products[choice - 1].name, totalCost);


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
//	printf("����:%d\n", num);
//	printf("�޷�������:%u\n", (unsigned int)num);
//	printf("ʮ�����ƣ�Сд��:%x\n", num);
//	printf("ʮ�����ƣ���д��:%X\n", num);
//	printf("ʮ�����ƣ�Сд��:%#x\n", num);
//	printf("ʮ�����ƣ�Сд��:%#X\n", num);
//	return 0;
//}


//int main()
//{
//	int a = 97;
//	printf("����:%d\n", a);
//	printf("��Ӧ��ĸ:%c\n", a);
//}
//
//int main()
//{
//    int num = 0;
//    printf("���Զ�������:");
//    printf("��������Ʒ���:");
//      scanf("%d", &num);
//      switch(num)
//      {
//          case 1:
//              printf("������ֳɹ�");
//              break;
//          case 2:
//              printf("������Ƭ�ɹ�");
//                  break;
//              case 3:
//                  printf("��������ɹ�");
//                  break;
//      }
//      return 0;
//}