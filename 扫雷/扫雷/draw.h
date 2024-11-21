//头文件等
#pragma onceR
#include "entry.h"

//提前声明
void drawButton(int buttonIndex, COLORREF color, const char* str);

void drawMenu() //画菜单
{
	// 创建菜单窗口
	initgraph(x, y);
	//绘制背景
	setbkcolor(RGB(102, 204, 255));
	cleardevice();
	//绘制图形与字体
	setfillcolor(LIGHTGRAY);//设置图形填充颜色
	setbkmode(TRANSPARENT);//设置背景模式,字体背景透明化
	settextcolor(BLACK);
	// 绘制标题
	settextstyle(150, 80, "宋体"); // 设置字体大小和样式
	drawButton(0, RGB(170, 140, 150), "扫雷游戏");
	// 绘制难度按钮
	settextstyle(50, 25, "宋体"); // 设置字体大小和样式
	drawButton(1, RGB(90, 180, 140), "基础难度");
	drawButton(2, RGB(90, 180, 140), "中等难度");
	drawButton(3, RGB(90, 180, 140), "专家难度");
	drawButton(4, RGB(90, 180, 140), "自定义");
	// 绘制开始游戏和结束游戏按钮
	drawButton(5, RGB(90, 180, 140), "开始游戏");
	drawButton(6, RGB(90, 180, 140), "结束游戏");
	//额外功能
	settextstyle(0, 0, "宋体"); // 设置字体大小和样式

	if (revoke) drawButton(7, YELLOW, "撤回功能（开中）");
	else        drawButton(7, RGB(90, 180, 140), "撤回功能（关中）");

	if (move)   drawButton(8, YELLOW, "滑点功能（开中）");
	else        drawButton(8, RGB(90, 180, 140), "滑点功能（关中）");
}
//函数声明
void drawCoveredCell(int x, int y) {
	putimage(x, y, &img[10]); // 绘制遮掩格
}
void drawUncoveredCell(int x, int y, int num) {
	putimage(x, y, &img[num]); // 绘制被遮掩格（显示雷数）
}
void drawFlaggedCell(int x, int y) {
	putimage(x, y, &img[11]); // 绘制旗帜
}
void drawExplodedCell(int x, int y) {
	putimage(x, y, &img[12]); // 绘制爆炸效果
}

void gameDraw() {//游戏绘画
	BeginBatchDraw();
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			int x = (i - 1) * IMG_SIZE;
			int y = (j - 1) * IMG_SIZE;

			if (mine[i][j] >= 100) {
				drawExplodedCell(x, y); // 点到雷了，炸了
			}
			else if (mine[i][j] >= 40) {
				drawFlaggedCell(x, y); // 右键之后，绘制旗帜
			}
			else if (mine[i][j] >= 20) {
				drawCoveredCell(x, y); // 被打开前，绘制遮掩格
			}
			else {
				drawUncoveredCell(x, y, mine[i][j]); // 被打开后，绘制被遮掩格（显示雷数）
			}
		}
	}
	// 绘制状态栏
	setfillcolor(RGB(102, 204, 255)); // 设置状态栏填充颜色
	solidrectangle(0, getheight() - IMG_SIZE, getwidth(), getheight()); // 填充状态栏，假设状态栏高度为 30
	// 显示当前时间
	clock_t currentTime = clock();
	double timeSpent = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
	char timeStr[100];
	char numStr[100];
	sprintf(timeStr, "用时: %.2f 秒", timeSpent);
	sprintf(numStr, "未开非雷格: %d", rows * cols - mine_num - num);
	settextcolor(WHITE);// 设置字体颜色
	settextstyle(20, 0, "Consolas"); // 设置字体大小和样式
	// 在状态栏显示时间
	outtextxy(10, getheight() - IMG_SIZE + 10, timeStr); // 显示时间
	outtextxy(getwidth() / 2, getheight() - IMG_SIZE + 10, numStr); // 显示剩余未打开的非雷格数
	EndBatchDraw();
}

void draw(int rx, int ry, int rw, int rh, const char* str, COLORREF color)//画菜单矩形底层
{
	//绘制矩形
	setfillcolor(color);//设置图形填充颜色
	fillrectangle(rx, ry, rx + rw, ry + rh);
	//绘制文字(居中)
	settextcolor(RED);
	int hSpace = (rw - textwidth(str)) / 2;
	int vSpace = (rh - textheight(str)) / 2;
	outtextxy(rx + hSpace, ry + vSpace, str);
}
void drawButton(int buttonIndex, COLORREF color, const char* str) {//画菜单矩形格子
	// 根据按钮索引绘制按钮
	int* addr = address[buttonIndex];
	draw(addr[0], addr[1], addr[2] - addr[0], addr[3] - addr[1], str, color);
}
void updateDifficulty(int num, const char* str)//画菜单难度变化
{
	if (lastSelectedButton != num) {
		drawButton(lastSelectedButton, RGB(90, 180, 140), lastSelectedButtonname); // 重绘旧按钮为默认颜色
		lastSelectedButton = num;
		// 复制字符串到 lastSelectedButtonname
		strncpy(lastSelectedButtonname, str, sizeof(lastSelectedButtonname) - 1);
		lastSelectedButtonname[sizeof(lastSelectedButtonname) - 1] = '\0'; // 确保字符串以 null 结尾
	}
	selectedDifficulty = num;
	drawButton(num, YELLOW, str); // 绘制新选中的按钮为高亮颜色
}