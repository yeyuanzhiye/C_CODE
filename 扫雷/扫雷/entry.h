//ͷ�ļ���
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include <windows.h> // ���� MessageBox��Windows API
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//ȫ�ֱ���������

clock_t startTime; // ��¼��Ϸ��ʼʱ��ʱ��

// ����ȫ��ָ�룬���ڶ�̬�����ڴ�(��̬�����С)
int** mine = NULL;
int rows = 9;//����
int cols = 9;//����
int mine_num = 19;//����

// ��ȡ��Ļ��Ⱥ͸߶�
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

//�˵����ڴ�С
int x = 1280;
int y = 720;
// ���㴰����ʼλ����ʹ�����
int windowX = (screenWidth - x) / 2;
int windowY = (screenHeight - y) / 2;
//�ֱ�Ϊ������ť���ϵ�x,y���꣬���µ�x,y����
int address[9][4] = {
	{x / 8,y / 8, 7 * x / 8, 3 * y / 8},//����
	{x / 8,3 * y / 8,5 * x / 16, y / 2},//�����Ѷ�
	{5 * x / 16,3 * y / 8,  x / 2, y / 2},//�е��Ѷ�
	{x / 2,3 * y / 8,11 * x / 16, y / 2},//ר���Ѷ�
	{11 * x / 16,3 * y / 8,7 * x / 8, y / 2},//�Զ���
	{x / 8,y / 2, 7 * x / 8, 5 * y / 8},//������ť
	{ x / 8,5 * y / 8,7 * x / 8, 3 * y / 4 }, //��ʼ��Ϸ��ť
	{ 7 * x / 8,0, x,  y / 8 } ,//�л����ع���
	{ 0,0, x/8,  y / 8 } //�л����㹦��
};
int selectedDifficulty = -1; // ��¼��ѡ�е��Ѷ�
int lastSelectedButton = -1; // ��¼��һ�α�ѡ�е��Ѷ�
char lastSelectedButtonname[100] = "";// ��¼��һ�α�ѡ�е��Ѷ���

// �����������������������
#define MAX_ROWS 42
#define MAX_COLS 24
#define MAX_MINES 1008
#define IMG_SIZE 40//�����С

IMAGE img[13];//����ͼƬ
int num = 0;//�Ѵ򿪵ķ��׸���
int mx;//������ڸ�����
int my;//������ڸ�����
bool move = false;//�Ƿ����û��㹦��
bool revoke = false;//�Ƿ����ó��ع���
bool leftButtonProcessed = false;// ����ȫ�ֱ��������ڱ���������Ƿ��Ѿ�������
bool rightButtonProcessed = false;// ����ȫ�ֱ��������ڱ������Ҽ��Ƿ��Ѿ�������