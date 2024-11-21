//头文件等

#pragma onceR
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include <windows.h> // 用于 MessageBox
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

//变量声明区

clock_t startTime; // 记录游戏开始时的时间
// 定义全局指针，用于动态分配内存
int** mine = NULL;
int rows = 9;//行数
int cols=9;//列数
int mine_num=19;//雷数
//菜单窗口大小
int x = 1280;
int y = 720;
//分别为各个按钮左上的x,y坐标，右下的x,y坐标
int address[8][4] = {
	{x / 8,y / 8, 7 * x / 8, 3 * y / 8},//标题
	{x / 8,3 * y / 8,5 * x / 16, y / 2},//基础难度
	{5 * x / 16,3 * y / 8,  x / 2, y / 2},//中等难度
	{x / 2,3 * y / 8,11 * x / 16, y / 2},//专家难度
	{11 * x / 16,3 * y / 8,7 * x / 8, y / 2},//自定义
	{x / 8,y / 2, 7 * x / 8, 5 * y / 8},//结束按钮
	{ x / 8,5 * y / 8,7 * x / 8, 3 * y / 4 }, //开始游戏按钮
	{ 7 * x / 8,0, x,  y / 8 } //切换撤回功能
};
int selectedDifficulty = -1; // 记录被选中的难度
int lastSelectedButton = -1; // 记录上一次被选中的难度
char lastSelectedButtonname[100] = "";// 记录上一次被选中的难度名
// 定义最大行数、列数和雷数
#define MAX_ROWS 40
#define MAX_COLS 25
#define MAX_MINES 1000
#define IMG_SIZE 40//单格大小

//载入图片
IMAGE img[13];
int num = 0;//已打开的非雷格数
int mx;//鼠标所在格行数
int my;//鼠标所在格列数
bool stop = false;//是否停止鼠标操作
bool revoke = false;//是否启用撤回功能

//函数声明区

void gameinit(int rows, int cols, int mine_num)//初始化游戏
{
	stop = false;//允许鼠标在游戏中的操作
	//创建窗口
	initgraph(rows * IMG_SIZE, cols * IMG_SIZE + IMG_SIZE, EX_SHOWCONSOLE);
	//加载游戏资源
	char filename[666];
	for (int i = 0; i < 13; i++)
	{
		sprintf(filename, "img/%d.gif", i);
		loadimage(img + i, filename, IMG_SIZE, IMG_SIZE);
	}
	num = 0;//初始化已打开的非雷格数
	// 设置随机数生成器种子
	srand((unsigned int)time(NULL));
	// 初始化所有格子
	mine = (int**)malloc((rows + 2) * sizeof(int*));
	for (int i = 0; i < rows + 2; i++) {
		mine[i] = (int*)malloc((cols + 2) * sizeof(int));
		for (int j = 0; j < cols + 2; j++) {
			mine[i][j] = 0;
		}
	}
	//初始化雷的位置
	int row, col;
	for (int i = 0; i < mine_num;)//随机生成mine_num个雷
	{
		//  随机行，列数   1到行，列数的位置
		row = rand() % rows + 1;
		col = rand() % cols + 1;
		if (mine[row][col] == 0)//如果随机位置无雷，生成雷
		{
			mine[row][col] = 9;//标记该处为雷(该值同时用于标记九宫格内雷数，因不可能为9，选择9作为该处有雷)
			i++;//已生成的雷数加一
		}
	}
	//提示九宫格内雷数
	for (int i = 1; i <= rows; i++)//遍历全图
	{
		for (int j = 1; j <= cols; j++)
		{
			if (mine[i][j] == 9)//如果该处有雷
			{
				for (int a = i - 1; a <= i + 1; a++)
				{
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (mine[a][b] != 9) mine[a][b]++;//九宫格内非雷的位置显示的数加一
					}
				}
			}
		}
	}
	//遮掩地图
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			mine[i][j] += 20;//全部加20遮掩
		}
	}
	// 初始化最后开始计时
	startTime = clock();
}
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
void gameDraw() {
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
	solidrectangle(0, getheight()-IMG_SIZE, getwidth(), getheight()); // 填充状态栏，假设状态栏高度为 30

    // 显示当前时间
    clock_t currentTime = clock();
    double timeSpent = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
    char timeStr[100];
    char numStr[100];
    sprintf(timeStr, "用时: %.2f 秒", timeSpent);
    sprintf(numStr, "未开非雷格: %d",rows * cols - mine_num-num);

    // 设置字体颜色
    settextcolor(WHITE);
    // 设置字体样式
    settextstyle(20, 0, _T("Consolas")); // 设置字体大小和样式

    // 在状态栏显示时间
    outtextxy(10, getheight() - IMG_SIZE+10, timeStr); // 显示时间
	outtextxy(getwidth()/2, getheight() - IMG_SIZE + 10, numStr); // 显示剩余未打开的非雷格数
	EndBatchDraw();
}
void open(int r, int c) {
	if (mine[r][c] == 0)// 若该位置为空格，则周围无雷
	{
		for (int i = r - 1; i <= r + 1; i++)
		{
			for (int j = c - 1; j <= c + 1; j++)
			{
				if (mine[i][j] >= 20)//直接打开周围全部被遮掩的格子
				{
					mine[i][j] -= 20;
					num++;
					open(i, j);//鉴定被打开的格子是否为空格，是的话继续递归打开
				}
			}
		}
	}
}
void mouseClick()
{
	ExMessage ms;//定义鼠标消息
	if (stop == false && peekmessage(&ms, EX_MOUSE))//只读取鼠标
	{
		//记录鼠标所在格
		mx = ms.x / IMG_SIZE + 1;
		my = ms.y / IMG_SIZE + 1;
		if (ms.lbutton)//鼠标左键
		{
			if (mine[mx][my] >= 20 && mine[mx][my] < 40)//只打开被遮掩且不为旗帜的格子
			{
				mine[mx][my] -= 20;
				if (mine[mx][my] != 9) num++;//若打开的不为雷，已打开非雷格数加一
				if (mine[mx][my] == 0) // 如果被打开的是空格，则递归打开周围格子
				{
					open(mx, my);
				}
			}
		}
		else if (ms.rbutton)//鼠标右键
		{
			if (mine[mx][my] >= 20 && mine[mx][my] < 40) // 如果是遮掩的格子且不是旗帜，则标记为旗帜
			{
				mine[mx][my] += 20;
			}
			else if (mine[mx][my] >= 40) // 如果已经是旗帜，则取消标记
			{
				mine[mx][my] -= 20;
			}
		}
	}
}
bool isOver()//判定游戏是否结束
{
	if (mine[mx][my] == 9)//点到雷了
	{
		stop = true;//禁用鼠标在游戏中的操作
		mine[mx][my] += 100;
		PlaySound("audio/Explosion.wav", NULL, SND_FILENAME | SND_ASYNC);//播放爆炸音效（wav）
		Sleep(500);
		gameDraw();
		if (revoke) {
			int ok = MessageBox(NULL, "是否撤回上一步", "你不幸死亡了，但你能撤回！", MB_OKCANCEL);
			if (ok == IDOK)
			{
				mine[mx][my] -= 80;//重新遮掩被打开的雷
				stop = false;//允许鼠标在游戏中的操作
			}
			else
			{
				return true;//返回菜单
			}
		}
		else
		{
			int ok = MessageBox(NULL, "是否立刻开始新的游戏", "你不幸死亡了！！！", MB_OKCANCEL);
			if (ok == IDOK)
			{
				closegraph(); // 关闭当前图形窗口
				gameinit(rows, cols, mine_num);//初始化游戏
			}
			else
			{
				return true;//返回菜单
			}
		}
	}
	if (num == rows * cols - mine_num)//打开格子数等于总个数-雷数-->赢了
	{
		stop = true;//禁用鼠标在游戏中的操作
		PlaySound("audio/Victory.wav", NULL, SND_FILENAME | SND_ASYNC);//播放胜利音效（wav）
		Sleep(500);
		int ok = MessageBox(NULL, "是否立刻开始新的游戏", "你赢了！！！", MB_OKCANCEL);
		if (ok == IDOK)
		{
			closegraph(); // 关闭当前图形窗口
			gameinit(rows,cols,mine_num);//初始化游戏
		}
		else
		{
			return true;//返回菜单
		}
	}
	return false; // 如果游戏没有结束，返回 false
}
void draw(int rx, int ry, int rw, int rh, const char* str, COLORREF color)
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
void drawButton(int buttonIndex, COLORREF color, const char* str) {
	// 根据按钮索引绘制按钮
	int* addr = address[buttonIndex];
	draw(addr[0], addr[1], addr[2] - addr[0], addr[3] - addr[1], str, color);
}
void updateDifficulty(int num,const char* str)
{
	if (lastSelectedButton != num) {
		drawButton(lastSelectedButton, RGB(90, 180, 140), lastSelectedButtonname); // 重绘旧按钮为默认颜色
		lastSelectedButton = num;
		// 复制字符串到 lastSelectedButtonname
		strncpy(lastSelectedButtonname, str, sizeof(lastSelectedButtonname) - 1);
		lastSelectedButtonname[sizeof(lastSelectedButtonname) - 1] = '\0'; // 确保字符串以 null 结尾
	}
	selectedDifficulty = num;
	drawButton(num, YELLOW,str); // 绘制新选中的按钮为高亮颜色
}
bool trueaddress(int num, int x, int y) {//检测鼠标是否在对应的位置
	return x > address[num][0] && x < address[num][2] && y > address[num][1] && y < address[num][3];
}
int showMenu() {
	// 创建菜单窗口
	initgraph(x, y, EX_SHOWCONSOLE);
	//绘制背景
	setbkcolor(RGB(102, 204, 255));
	cleardevice();
	//绘制图形与字体
	setfillcolor(LIGHTGRAY);//设置图形填充颜色
	setbkmode(TRANSPARENT);//设置背景模式,字体背景透明化
	settextcolor(BLACK);
	// 绘制标题
	drawButton(0, RGB(170,140,150), "扫雷游戏");
	// 绘制难度按钮
	drawButton(1, RGB(90, 180, 140), "基础难度");
	drawButton(2, RGB(90, 180, 140), "中等难度");
	drawButton(3, RGB(90, 180, 140), "专家难度");
	drawButton(4, RGB(90, 180, 140), "自定义");
	// 绘制开始游戏和结束游戏按钮
	drawButton(5, RGB(90, 180, 140), "开始游戏");
	drawButton(6, RGB(90, 180, 140), "结束游戏");
	drawButton(7, RGB(90, 180, 140), "撤回功能（关闭中）");
	while (true) {
		ExMessage ms;//定义鼠标消息
		if (peekmessage(&ms, EX_MOUSE)) {
			if (ms.lbutton) {
				int x = ms.x;
				int y = ms.y;
				if (trueaddress(1, x, y)) {
					updateDifficulty(1, "基础难度");
				}
				else if (trueaddress(2, x, y)) {
					updateDifficulty(2, "中等难度");
				}
				else if (trueaddress(3, x, y)) {
					updateDifficulty(3, "专家难度");
				}
				else if (trueaddress(4, x, y)) {
					updateDifficulty(4, "自定义");
				}
				else if (trueaddress(5, x, y)) {
					if (selectedDifficulty != -1) {//如果已经选择了难度
						closegraph();
						return selectedDifficulty;//开始游戏
					}
				}
				else if (trueaddress(6, x, y)) {
					closegraph();
					return 6;//结束游戏
				}
				else if (trueaddress(7, x, y)) {
					if (revoke==true)//启用撤回功能
					{
						revoke = false;//禁用撤回功能
						drawButton(7, RGB(90, 180, 140), "撤回功能（关闭中）"); // 绘制新选中的按钮为高亮颜色
					}
					else {
						revoke = true;//启用撤回功能
						drawButton(7, YELLOW, "撤回功能（启用中）");
					}
				}
			}
		}
	}
}
void getCustomSettings() {//自定义
	printf("请输入行数（3-%d）: ", MAX_ROWS);
	scanf("%d", &rows);
	while (rows < 3 || rows > MAX_ROWS) {
		printf("行数输入无效，请输入一个介于3到%d之间的值: ", MAX_ROWS);
		scanf("%d", &rows);
	}

	printf("请输入列数（3-%d）: ", MAX_COLS);
	scanf("%d", &cols);
	while (cols < 3 || cols > MAX_COLS) {
		printf("列数输入无效，请输入一个介于3到%d之间的值: ", MAX_COLS);
		scanf("%d", &cols);
	}

	printf("请输入雷数（1-%d）: ", MAX_MINES);
	scanf("%d", &mine_num);
	while (mine_num < 1 || mine_num >(rows * cols)) {
		printf("雷数输入无效，请输入一个介于1到%d之间的值: ", rows * cols);
		scanf("%d", &mine_num);
	}
}
void gamefree() {//内存释放
	// 检查 mine 指针是否非 NULL，确保内存已被分配
	if (mine != NULL) {
		// 释放每一行的内存
		for (int i = 0; i < rows; i++) {
			free(mine[i]);
		}
		// 释放行指针数组的内存
		free(mine);
		// 将 mine 设置为 NULL，避免悬空指针
		mine = NULL;
	}
}
void gamestart()//开始游戏
{
	closegraph(); // 关闭之前的图形窗口
	gamefree(); // 在重新初始化之前释放之前的内存
	gameinit(rows, cols, mine_num); // 使用全局变量初始化游戏
	while (true) { // 游戏中。。。
		mouseClick();
		gameDraw();
		if (isOver()) {
			gamefree();
			closegraph(); // 游戏结束时关闭图形窗口
			break; // 返回菜单
		}
	}
	closegraph(); // 游戏结束时关闭图形窗口
}