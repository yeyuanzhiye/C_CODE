#include "tool.h"

int main()
{
	int menuChoice;//��¼����İ�ť
	do {
		menuChoice = showMenu();
		switch (menuChoice) {
		case 1: // �����Ѷ�
			rows = 9; cols = 9; mine_num = 10; gamestart(); break;
		case 2: // �е��Ѷ�
			rows = 16; cols = 16; mine_num = 40; gamestart(); break;
		case 3: // ר���Ѷ�
			rows = 30; cols = 16; mine_num = 99; gamestart();  break;
		case 4: // �Զ����Ѷ�
			getCustomSettings(); gamestart(); break;
		case 6: // ������Ϸ
			break;
		}
	} while (menuChoice != 6);
	gamefree(); // �ڳ������ǰ�ͷ��ڴ�
	return 0;
}