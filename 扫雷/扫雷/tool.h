//头文件等
#pragma onceR
#include "draw.h"
//提前声明
void gamefree();
void gameinit(int rows, int cols, int mine_num);
void mouseClick();
void open(int r, int c);
bool isOver();

//函数声明区
bool trueaddress(int num, int x, int y) {//检测鼠标是否在对应的位置
	return x > address[num][0] && x < address[num][2] && y > address[num][1] && y < address[num][3];
}
int menuClick()//菜单鼠标动作
{
	while (true) {
		ExMessage ms;//定义鼠标消息
		if (peekmessage(&ms, EX_MOUSE)) {
			if (ms.lbutton) {
				int x = ms.x;
				int y = ms.y;
				if (trueaddress(1, x, y)) {
					settextstyle(50, 25, "宋体"); // 设置字体大小和样式
					updateDifficulty(1, "基础难度");
				}
				else if (trueaddress(2, x, y)) {
					settextstyle(50, 25, "宋体"); // 设置字体大小和样式
					updateDifficulty(2, "中等难度");
				}
				else if (trueaddress(3, x, y)) {
					settextstyle(50, 25, "宋体"); // 设置字体大小和样式
					updateDifficulty(3, "专家难度");
				}
				else if (trueaddress(4, x, y)) {
					settextstyle(50, 25, "宋体"); // 设置字体大小和样式
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
					if (revoke == true)//启用撤回功能
					{
						revoke = false;//禁用撤回功能
						settextstyle(0, 0, "宋体"); // 设置字体大小和样式
						drawButton(7, RGB(90, 180, 140), "撤回功能（关中）"); // 绘制新选中的按钮为高亮颜色
					}
					else {
						revoke = true;//启用撤回功能
						settextstyle(0, 0, "宋体"); // 设置字体大小和样式
						drawButton(7, YELLOW, "撤回功能（开中）");
					}
				}
				else if (trueaddress(8, x, y)) {
					if (move == true)//启用滑点功能
					{
						move = false;//禁用滑点功能
						settextstyle(0, 0, "宋体"); // 设置字体大小和样式
						drawButton(8, RGB(90, 180, 140), "滑点功能（关中）"); // 绘制新选中的按钮为高亮颜色
					}
					else {
						move = true;//启用滑点功能
						settextstyle(0, 0, "宋体"); // 设置字体大小和样式
						drawButton(8, YELLOW, "滑点功能（开中）");
					}
				}
			}
		}
	}
}
int showMenu() {//菜单
	drawMenu();//画菜单
	return menuClick();//菜单鼠标动作
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
void gameinit(int rows, int cols, int mine_num)//初始化游戏
{
	//创建窗口
	initgraph(rows * IMG_SIZE, cols * IMG_SIZE + IMG_SIZE);
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
void mouseClick()//游戏中鼠标动作
{
	ExMessage ms; // 定义鼠标消息
	if (peekmessage(&ms, EX_MOUSE)) // 只读取鼠标消息
	{
		// 记录鼠标所在格
		mx = ms.x / IMG_SIZE + 1;
		my = ms.y / IMG_SIZE + 1;

		// 处理左键点击
		if (ms.lbutton && !leftButtonProcessed) // 鼠标左键 且 未被标记为已处理
		{
			if (!move) //如果没开滑点
			{
				leftButtonProcessed = true; // 标记左键已被处理
			}
			if (mine[mx][my] >= 20 && mine[mx][my] < 40) // 只打开被遮掩且不为旗帜的格子
			{
				mine[mx][my] -= 20;
				if (mine[mx][my] != 9) num++; // 若打开的不为雷，已打开非雷格数加一
				if (mine[mx][my] == 0) // 如果被打开的是空格，则递归打开周围格子
				{
					open(mx, my);
				}
			}
		}
		else if (!ms.lbutton) // 如果左键未被按下，则重置处理标记
		{
			leftButtonProcessed = false;
		}

		// 处理右键点击
		if (ms.rbutton && !rightButtonProcessed) // 鼠标右键 且 未被标记为已处理
		{
			if (!move) //如果没开滑点
			{
				rightButtonProcessed = true; // 标记右键已被处理
			}
			if (mine[mx][my] >= 20 && mine[mx][my] < 40) // 如果是遮掩的格子且不是旗帜，则标记为旗帜
			{
				mine[mx][my] += 20;
			}
			else if (mine[mx][my] >= 40) // 如果已经是旗帜，则取消标记
			{
				mine[mx][my] -= 20;
			}
		}
		else if (!ms.rbutton) // 如果右键未被按下，则重置处理标记
		{
			rightButtonProcessed = false;
		}
	}
}
void open(int r, int c) {//自动开格子
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
bool isOver()//判定游戏是否结束
{
	if (mine[mx][my] == 9)//点到雷了
	{
		mine[mx][my] += 100;
		PlaySound("audio/Explosion.wav", NULL, SND_FILENAME | SND_ASYNC);//播放爆炸音效（wav）
		Sleep(500);
		gameDraw();//马上更新游戏图层
		if (revoke) {//如果启用了撤回功能
			int ok = MessageBox(NULL, "是否撤回上一步", "你不幸死亡了，但你能撤回！", MB_OKCANCEL);
			if (ok == IDOK)
			{
				mine[mx][my] -= 80;//重新遮掩被打开的雷
			}
			else
			{
				selectedDifficulty = -1;//初始化难度选择
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
				selectedDifficulty = -1;//初始化难度选择
				return true;//返回菜单
			}
		}
	}
	if (num == rows * cols - mine_num)//打开格子数等于总个数-雷数-->赢了
	{
		PlaySound("audio/Victory.wav", NULL, SND_FILENAME | SND_ASYNC);//播放胜利音效（wav）
		Sleep(500);
		int ok = MessageBox(NULL, "是否立刻开始新的游戏", "你赢了！！！", MB_OKCANCEL);
		if (ok == IDOK)
		{
			closegraph(); // 关闭当前图形窗口
			gameinit(rows, cols, mine_num);//初始化游戏
		}
		else
		{
			selectedDifficulty = -1;//初始化难度选择
			return true;//返回菜单
		}
	}
	return false; // 如果游戏没有结束，返回 false
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