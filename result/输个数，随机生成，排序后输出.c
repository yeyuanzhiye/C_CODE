//C语言程序中数组的特点和作用
//特点：
//固定大小：数组在声明时其大小是固定的，一旦定义就不能改变。
//连续存储：数组中的元素在内存中是连续存储的，这使得数组在访问元素时具有较高的效率。
//类型相同：数组中的所有元素必须是相同类型的。
//作用：
//数据组织：可以将一组相关的数据组织在一起，便于管理和操作。
//批量处理：可以方便地对一组数据进行批量处理，如遍历、排序、查找等。
//节省空间：数组中的元素在内存中连续存储，相较于链表等数据结构，节省了指针的空间。
// 
//多维数组
//定义：
//多维数组是指数组的数组，即数组的每个元素本身也是一个数组。常见的多维数组有二维数组、三维数组等。
//举例：
//以二维数组为例，假设有一个二维数组 int arr[3][4]，它表示有3个行向量，每个行向量包含4个元素。
//存取操作：
//计算机通过行索引和列索引来存取二维数组中的元素。例如，arr[i][j] 表示第 i 行第 j 列的元素。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 10000 // 假设元素个数的上限为10000

// 选择排序函数
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 交换元素
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// 打印数组函数，每行20个数据
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// “伪随机数”生成函数（简单示例，不是真正的随机）
int pseudoRandom(int index, int mod) {
    // 使用一个简单的线性同余生成器作为示例
    // 注意：这不是一个好的随机数生成器，仅用于演示
    return (index * 1103515245 + 12345) % mod;
}

int main() {
    int n;
    int arr[MAX_N]; // 使用静态数组

    printf("请输入要排序的元素个数（100到%d之间）：", MAX_N);
    scanf("%d", &n);

    // 检查输入是否合法
    if (n < 100 || n > MAX_N) {
        printf("元素个数必须在100到%d之间！\n", MAX_N);
        return 1;
    }

    // “生成”伪随机数填充数组
    for (int i = 0; i < n; i++) {
        arr[i] = pseudoRandom(i, 10001); // 生成0到10000之间的“伪随机数”
    }

    // 输出排序前的数据
    printf("排序前的数据：\n");
    printArray(arr, n);

    // 对数组进行排序
    selectionSort(arr, n);

    // 输出排序后的数据
    printf("排序后的数据：\n");
    printArray(arr, n);

    return 0;
}