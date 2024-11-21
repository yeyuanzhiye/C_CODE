//ͷ�ļ���
#pragma onceR
#include "entry.h"

//��ǰ����
void drawButton(int buttonIndex, COLORREF color, const char* str);

void drawMenu() //���˵�
{
	// �����˵�����
	initgraph(x, y);
	//���Ʊ���
	setbkcolor(RGB(102, 204, 255));
	cleardevice();
	//����ͼ��������
	setfillcolor(LIGHTGRAY);//����ͼ�������ɫ
	setbkmode(TRANSPARENT);//���ñ���ģʽ,���屳��͸����
	settextcolor(BLACK);
	// ���Ʊ���
	settextstyle(150, 80, "����"); // ���������С����ʽ
	drawButton(0, RGB(170, 140, 150), "ɨ����Ϸ");
	// �����ѶȰ�ť
	settextstyle(50, 25, "����"); // ���������С����ʽ
	drawButton(1, RGB(90, 180, 140), "�����Ѷ�");
	drawButton(2, RGB(90, 180, 140), "�е��Ѷ�");
	drawButton(3, RGB(90, 180, 140), "ר���Ѷ�");
	drawButton(4, RGB(90, 180, 140), "�Զ���");
	// ���ƿ�ʼ��Ϸ�ͽ�����Ϸ��ť
	drawButton(5, RGB(90, 180, 140), "��ʼ��Ϸ");
	drawButton(6, RGB(90, 180, 140), "������Ϸ");
	//���⹦��
	settextstyle(0, 0, "����"); // ���������С����ʽ

	if (revoke) drawButton(7, YELLOW, "���ع��ܣ����У�");
	else        drawButton(7, RGB(90, 180, 140), "���ع��ܣ����У�");

	if (move)   drawButton(8, YELLOW, "���㹦�ܣ����У�");
	else        drawButton(8, RGB(90, 180, 140), "���㹦�ܣ����У�");
}
//��������
void drawCoveredCell(int x, int y) {
	putimage(x, y, &img[10]); // �������ڸ�
}
void drawUncoveredCell(int x, int y, int num) {
	putimage(x, y, &img[num]); // ���Ʊ����ڸ���ʾ������
}
void drawFlaggedCell(int x, int y) {
	putimage(x, y, &img[11]); // ��������
}
void drawExplodedCell(int x, int y) {
	putimage(x, y, &img[12]); // ���Ʊ�ըЧ��
}

void gameDraw() {//��Ϸ�滭
	BeginBatchDraw();
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			int x = (i - 1) * IMG_SIZE;
			int y = (j - 1) * IMG_SIZE;

			if (mine[i][j] >= 100) {
				drawExplodedCell(x, y); // �㵽���ˣ�ը��
			}
			else if (mine[i][j] >= 40) {
				drawFlaggedCell(x, y); // �Ҽ�֮�󣬻�������
			}
			else if (mine[i][j] >= 20) {
				drawCoveredCell(x, y); // ����ǰ���������ڸ�
			}
			else {
				drawUncoveredCell(x, y, mine[i][j]); // ���򿪺󣬻��Ʊ����ڸ���ʾ������
			}
		}
	}
	// ����״̬��
	setfillcolor(RGB(102, 204, 255)); // ����״̬�������ɫ
	solidrectangle(0, getheight() - IMG_SIZE, getwidth(), getheight()); // ���״̬��������״̬���߶�Ϊ 30
	// ��ʾ��ǰʱ��
	clock_t currentTime = clock();
	double timeSpent = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
	char timeStr[100];
	char numStr[100];
	sprintf(timeStr, "��ʱ: %.2f ��", timeSpent);
	sprintf(numStr, "δ�����׸�: %d", rows * cols - mine_num - num);
	settextcolor(WHITE);// ����������ɫ
	settextstyle(20, 0, "Consolas"); // ���������С����ʽ
	// ��״̬����ʾʱ��
	outtextxy(10, getheight() - IMG_SIZE + 10, timeStr); // ��ʾʱ��
	outtextxy(getwidth() / 2, getheight() - IMG_SIZE + 10, numStr); // ��ʾʣ��δ�򿪵ķ��׸���
	EndBatchDraw();
}

void draw(int rx, int ry, int rw, int rh, const char* str, COLORREF color)//���˵����εײ�
{
	//���ƾ���
	setfillcolor(color);//����ͼ�������ɫ
	fillrectangle(rx, ry, rx + rw, ry + rh);
	//��������(����)
	settextcolor(RED);
	int hSpace = (rw - textwidth(str)) / 2;
	int vSpace = (rh - textheight(str)) / 2;
	outtextxy(rx + hSpace, ry + vSpace, str);
}
void drawButton(int buttonIndex, COLORREF color, const char* str) {//���˵����θ���
	// ���ݰ�ť�������ư�ť
	int* addr = address[buttonIndex];
	draw(addr[0], addr[1], addr[2] - addr[0], addr[3] - addr[1], str, color);
}
void updateDifficulty(int num, const char* str)//���˵��Ѷȱ仯
{
	if (lastSelectedButton != num) {
		drawButton(lastSelectedButton, RGB(90, 180, 140), lastSelectedButtonname); // �ػ�ɰ�ťΪĬ����ɫ
		lastSelectedButton = num;
		// �����ַ����� lastSelectedButtonname
		strncpy(lastSelectedButtonname, str, sizeof(lastSelectedButtonname) - 1);
		lastSelectedButtonname[sizeof(lastSelectedButtonname) - 1] = '\0'; // ȷ���ַ����� null ��β
	}
	selectedDifficulty = num;
	drawButton(num, YELLOW, str); // ������ѡ�еİ�ťΪ������ɫ
}