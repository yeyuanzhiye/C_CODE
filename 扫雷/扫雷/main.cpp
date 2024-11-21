#include "tool.h"

int main()
{
	int menuChoice;//记录点击的按钮
	do {
		menuChoice = showMenu();
		switch (menuChoice) {
		case 1: // 基础难度
			rows = 9; cols = 9; mine_num = 10; gamestart(); break;
		case 2: // 中等难度
			rows = 16; cols = 16; mine_num = 40; gamestart(); break;
		case 3: // 专家难度
			rows = 30; cols = 16; mine_num = 99; gamestart();  break;
		case 4: // 自定义难度
			getCustomSettings(); gamestart(); break;
		case 6: // 结束游戏
			break;
		}
	} while (menuChoice != 6);
	gamefree(); // 在程序结束前释放内存
	return 0;
}