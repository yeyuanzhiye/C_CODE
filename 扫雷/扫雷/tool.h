//ͷ�ļ���

#pragma onceR
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include <windows.h> // ���� MessageBox
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

//����������

clock_t startTime; // ��¼��Ϸ��ʼʱ��ʱ��
// ����ȫ��ָ�룬���ڶ�̬�����ڴ�
int** mine = NULL;
int rows = 9;//����
int cols=9;//����
int mine_num=19;//����
//�˵����ڴ�С
int x = 1280;
int y = 720;
//�ֱ�Ϊ������ť���ϵ�x,y���꣬���µ�x,y����
int address[8][4] = {
	{x / 8,y / 8, 7 * x / 8, 3 * y / 8},//����
	{x / 8,3 * y / 8,5 * x / 16, y / 2},//�����Ѷ�
	{5 * x / 16,3 * y / 8,  x / 2, y / 2},//�е��Ѷ�
	{x / 2,3 * y / 8,11 * x / 16, y / 2},//ר���Ѷ�
	{11 * x / 16,3 * y / 8,7 * x / 8, y / 2},//�Զ���
	{x / 8,y / 2, 7 * x / 8, 5 * y / 8},//������ť
	{ x / 8,5 * y / 8,7 * x / 8, 3 * y / 4 }, //��ʼ��Ϸ��ť
	{ 7 * x / 8,0, x,  y / 8 } //�л����ع���
};
int selectedDifficulty = -1; // ��¼��ѡ�е��Ѷ�
int lastSelectedButton = -1; // ��¼��һ�α�ѡ�е��Ѷ�
char lastSelectedButtonname[100] = "";// ��¼��һ�α�ѡ�е��Ѷ���
// �����������������������
#define MAX_ROWS 40
#define MAX_COLS 25
#define MAX_MINES 1000
#define IMG_SIZE 40//�����С

//����ͼƬ
IMAGE img[13];
int num = 0;//�Ѵ򿪵ķ��׸���
int mx;//������ڸ�����
int my;//������ڸ�����
bool stop = false;//�Ƿ�ֹͣ������
bool revoke = false;//�Ƿ����ó��ع���

//����������

void gameinit(int rows, int cols, int mine_num)//��ʼ����Ϸ
{
	stop = false;//�����������Ϸ�еĲ���
	//��������
	initgraph(rows * IMG_SIZE, cols * IMG_SIZE + IMG_SIZE, EX_SHOWCONSOLE);
	//������Ϸ��Դ
	char filename[666];
	for (int i = 0; i < 13; i++)
	{
		sprintf(filename, "img/%d.gif", i);
		loadimage(img + i, filename, IMG_SIZE, IMG_SIZE);
	}
	num = 0;//��ʼ���Ѵ򿪵ķ��׸���
	// �������������������
	srand((unsigned int)time(NULL));
	// ��ʼ�����и���
	mine = (int**)malloc((rows + 2) * sizeof(int*));
	for (int i = 0; i < rows + 2; i++) {
		mine[i] = (int*)malloc((cols + 2) * sizeof(int));
		for (int j = 0; j < cols + 2; j++) {
			mine[i][j] = 0;
		}
	}
	//��ʼ���׵�λ��
	int row, col;
	for (int i = 0; i < mine_num;)//�������mine_num����
	{
		//  ����У�����   1���У�������λ��
		row = rand() % rows + 1;
		col = rand() % cols + 1;
		if (mine[row][col] == 0)//������λ�����ף�������
		{
			mine[row][col] = 9;//��Ǹô�Ϊ��(��ֵͬʱ���ڱ�ǾŹ������������򲻿���Ϊ9��ѡ��9��Ϊ�ô�����)
			i++;//�����ɵ�������һ
		}
	}
	//��ʾ�Ź���������
	for (int i = 1; i <= rows; i++)//����ȫͼ
	{
		for (int j = 1; j <= cols; j++)
		{
			if (mine[i][j] == 9)//����ô�����
			{
				for (int a = i - 1; a <= i + 1; a++)
				{
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (mine[a][b] != 9) mine[a][b]++;//�Ź����ڷ��׵�λ����ʾ������һ
					}
				}
			}
		}
	}
	//���ڵ�ͼ
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			mine[i][j] += 20;//ȫ����20����
		}
	}
	// ��ʼ�����ʼ��ʱ
	startTime = clock();
}
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
void gameDraw() {
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
	solidrectangle(0, getheight()-IMG_SIZE, getwidth(), getheight()); // ���״̬��������״̬���߶�Ϊ 30

    // ��ʾ��ǰʱ��
    clock_t currentTime = clock();
    double timeSpent = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
    char timeStr[100];
    char numStr[100];
    sprintf(timeStr, "��ʱ: %.2f ��", timeSpent);
    sprintf(numStr, "δ�����׸�: %d",rows * cols - mine_num-num);

    // ����������ɫ
    settextcolor(WHITE);
    // ����������ʽ
    settextstyle(20, 0, _T("Consolas")); // ���������С����ʽ

    // ��״̬����ʾʱ��
    outtextxy(10, getheight() - IMG_SIZE+10, timeStr); // ��ʾʱ��
	outtextxy(getwidth()/2, getheight() - IMG_SIZE + 10, numStr); // ��ʾʣ��δ�򿪵ķ��׸���
	EndBatchDraw();
}
void open(int r, int c) {
	if (mine[r][c] == 0)// ����λ��Ϊ�ո�����Χ����
	{
		for (int i = r - 1; i <= r + 1; i++)
		{
			for (int j = c - 1; j <= c + 1; j++)
			{
				if (mine[i][j] >= 20)//ֱ�Ӵ���Χȫ�������ڵĸ���
				{
					mine[i][j] -= 20;
					num++;
					open(i, j);//�������򿪵ĸ����Ƿ�Ϊ�ո��ǵĻ������ݹ��
				}
			}
		}
	}
}
void mouseClick()
{
	ExMessage ms;//���������Ϣ
	if (stop == false && peekmessage(&ms, EX_MOUSE))//ֻ��ȡ���
	{
		//��¼������ڸ�
		mx = ms.x / IMG_SIZE + 1;
		my = ms.y / IMG_SIZE + 1;
		if (ms.lbutton)//������
		{
			if (mine[mx][my] >= 20 && mine[mx][my] < 40)//ֻ�򿪱������Ҳ�Ϊ���ĵĸ���
			{
				mine[mx][my] -= 20;
				if (mine[mx][my] != 9) num++;//���򿪵Ĳ�Ϊ�ף��Ѵ򿪷��׸�����һ
				if (mine[mx][my] == 0) // ������򿪵��ǿո���ݹ����Χ����
				{
					open(mx, my);
				}
			}
		}
		else if (ms.rbutton)//����Ҽ�
		{
			if (mine[mx][my] >= 20 && mine[mx][my] < 40) // ��������ڵĸ����Ҳ������ģ�����Ϊ����
			{
				mine[mx][my] += 20;
			}
			else if (mine[mx][my] >= 40) // ����Ѿ������ģ���ȡ�����
			{
				mine[mx][my] -= 20;
			}
		}
	}
}
bool isOver()//�ж���Ϸ�Ƿ����
{
	if (mine[mx][my] == 9)//�㵽����
	{
		stop = true;//�����������Ϸ�еĲ���
		mine[mx][my] += 100;
		PlaySound("audio/Explosion.wav", NULL, SND_FILENAME | SND_ASYNC);//���ű�ը��Ч��wav��
		Sleep(500);
		gameDraw();
		if (revoke) {
			int ok = MessageBox(NULL, "�Ƿ񳷻���һ��", "�㲻�������ˣ������ܳ��أ�", MB_OKCANCEL);
			if (ok == IDOK)
			{
				mine[mx][my] -= 80;//�������ڱ��򿪵���
				stop = false;//�����������Ϸ�еĲ���
			}
			else
			{
				return true;//���ز˵�
			}
		}
		else
		{
			int ok = MessageBox(NULL, "�Ƿ����̿�ʼ�µ���Ϸ", "�㲻�������ˣ�����", MB_OKCANCEL);
			if (ok == IDOK)
			{
				closegraph(); // �رյ�ǰͼ�δ���
				gameinit(rows, cols, mine_num);//��ʼ����Ϸ
			}
			else
			{
				return true;//���ز˵�
			}
		}
	}
	if (num == rows * cols - mine_num)//�򿪸����������ܸ���-����-->Ӯ��
	{
		stop = true;//�����������Ϸ�еĲ���
		PlaySound("audio/Victory.wav", NULL, SND_FILENAME | SND_ASYNC);//����ʤ����Ч��wav��
		Sleep(500);
		int ok = MessageBox(NULL, "�Ƿ����̿�ʼ�µ���Ϸ", "��Ӯ�ˣ�����", MB_OKCANCEL);
		if (ok == IDOK)
		{
			closegraph(); // �رյ�ǰͼ�δ���
			gameinit(rows,cols,mine_num);//��ʼ����Ϸ
		}
		else
		{
			return true;//���ز˵�
		}
	}
	return false; // �����Ϸû�н��������� false
}
void draw(int rx, int ry, int rw, int rh, const char* str, COLORREF color)
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
void drawButton(int buttonIndex, COLORREF color, const char* str) {
	// ���ݰ�ť�������ư�ť
	int* addr = address[buttonIndex];
	draw(addr[0], addr[1], addr[2] - addr[0], addr[3] - addr[1], str, color);
}
void updateDifficulty(int num,const char* str)
{
	if (lastSelectedButton != num) {
		drawButton(lastSelectedButton, RGB(90, 180, 140), lastSelectedButtonname); // �ػ�ɰ�ťΪĬ����ɫ
		lastSelectedButton = num;
		// �����ַ����� lastSelectedButtonname
		strncpy(lastSelectedButtonname, str, sizeof(lastSelectedButtonname) - 1);
		lastSelectedButtonname[sizeof(lastSelectedButtonname) - 1] = '\0'; // ȷ���ַ����� null ��β
	}
	selectedDifficulty = num;
	drawButton(num, YELLOW,str); // ������ѡ�еİ�ťΪ������ɫ
}
bool trueaddress(int num, int x, int y) {//�������Ƿ��ڶ�Ӧ��λ��
	return x > address[num][0] && x < address[num][2] && y > address[num][1] && y < address[num][3];
}
int showMenu() {
	// �����˵�����
	initgraph(x, y, EX_SHOWCONSOLE);
	//���Ʊ���
	setbkcolor(RGB(102, 204, 255));
	cleardevice();
	//����ͼ��������
	setfillcolor(LIGHTGRAY);//����ͼ�������ɫ
	setbkmode(TRANSPARENT);//���ñ���ģʽ,���屳��͸����
	settextcolor(BLACK);
	// ���Ʊ���
	drawButton(0, RGB(170,140,150), "ɨ����Ϸ");
	// �����ѶȰ�ť
	drawButton(1, RGB(90, 180, 140), "�����Ѷ�");
	drawButton(2, RGB(90, 180, 140), "�е��Ѷ�");
	drawButton(3, RGB(90, 180, 140), "ר���Ѷ�");
	drawButton(4, RGB(90, 180, 140), "�Զ���");
	// ���ƿ�ʼ��Ϸ�ͽ�����Ϸ��ť
	drawButton(5, RGB(90, 180, 140), "��ʼ��Ϸ");
	drawButton(6, RGB(90, 180, 140), "������Ϸ");
	drawButton(7, RGB(90, 180, 140), "���ع��ܣ��ر��У�");
	while (true) {
		ExMessage ms;//���������Ϣ
		if (peekmessage(&ms, EX_MOUSE)) {
			if (ms.lbutton) {
				int x = ms.x;
				int y = ms.y;
				if (trueaddress(1, x, y)) {
					updateDifficulty(1, "�����Ѷ�");
				}
				else if (trueaddress(2, x, y)) {
					updateDifficulty(2, "�е��Ѷ�");
				}
				else if (trueaddress(3, x, y)) {
					updateDifficulty(3, "ר���Ѷ�");
				}
				else if (trueaddress(4, x, y)) {
					updateDifficulty(4, "�Զ���");
				}
				else if (trueaddress(5, x, y)) {
					if (selectedDifficulty != -1) {//����Ѿ�ѡ�����Ѷ�
						closegraph();
						return selectedDifficulty;//��ʼ��Ϸ
					}
				}
				else if (trueaddress(6, x, y)) {
					closegraph();
					return 6;//������Ϸ
				}
				else if (trueaddress(7, x, y)) {
					if (revoke==true)//���ó��ع���
					{
						revoke = false;//���ó��ع���
						drawButton(7, RGB(90, 180, 140), "���ع��ܣ��ر��У�"); // ������ѡ�еİ�ťΪ������ɫ
					}
					else {
						revoke = true;//���ó��ع���
						drawButton(7, YELLOW, "���ع��ܣ������У�");
					}
				}
			}
		}
	}
}
void getCustomSettings() {//�Զ���
	printf("������������3-%d��: ", MAX_ROWS);
	scanf("%d", &rows);
	while (rows < 3 || rows > MAX_ROWS) {
		printf("����������Ч��������һ������3��%d֮���ֵ: ", MAX_ROWS);
		scanf("%d", &rows);
	}

	printf("������������3-%d��: ", MAX_COLS);
	scanf("%d", &cols);
	while (cols < 3 || cols > MAX_COLS) {
		printf("����������Ч��������һ������3��%d֮���ֵ: ", MAX_COLS);
		scanf("%d", &cols);
	}

	printf("������������1-%d��: ", MAX_MINES);
	scanf("%d", &mine_num);
	while (mine_num < 1 || mine_num >(rows * cols)) {
		printf("����������Ч��������һ������1��%d֮���ֵ: ", rows * cols);
		scanf("%d", &mine_num);
	}
}
void gamefree() {//�ڴ��ͷ�
	// ��� mine ָ���Ƿ�� NULL��ȷ���ڴ��ѱ�����
	if (mine != NULL) {
		// �ͷ�ÿһ�е��ڴ�
		for (int i = 0; i < rows; i++) {
			free(mine[i]);
		}
		// �ͷ���ָ��������ڴ�
		free(mine);
		// �� mine ����Ϊ NULL����������ָ��
		mine = NULL;
	}
}
void gamestart()//��ʼ��Ϸ
{
	closegraph(); // �ر�֮ǰ��ͼ�δ���
	gamefree(); // �����³�ʼ��֮ǰ�ͷ�֮ǰ���ڴ�
	gameinit(rows, cols, mine_num); // ʹ��ȫ�ֱ�����ʼ����Ϸ
	while (true) { // ��Ϸ�С�����
		mouseClick();
		gameDraw();
		if (isOver()) {
			gamefree();
			closegraph(); // ��Ϸ����ʱ�ر�ͼ�δ���
			break; // ���ز˵�
		}
	}
	closegraph(); // ��Ϸ����ʱ�ر�ͼ�δ���
}