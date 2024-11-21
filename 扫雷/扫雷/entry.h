//头文件等
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include <windows.h> // 用于 MessageBox和Windows API
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//全局变量声明区

clock_t startTime; // 记录游戏开始时的时间

// 定义全局指针，用于动态分配内存(动态数组大小)
int** mine = NULL;
int rows = 9;//行数
int cols = 9;//列数
int mine_num = 19;//雷数

// 获取屏幕宽度和高度
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

//菜单窗口大小
int x = 1280;
int y = 720;
// 计算窗口起始位置以使其居中
int windowX = (screenWidth - x) / 2;
int windowY = (screenHeight - y) / 2;
//分别为各个按钮左上的x,y坐标，右下的x,y坐标
int address[9][4] = {
	{x / 8,y / 8, 7 * x / 8, 3 * y / 8},//标题
	{x / 8,3 * y / 8,5 * x / 16, y / 2},//基础难度
	{5 * x / 16,3 * y / 8,  x / 2, y / 2},//中等难度
	{x / 2,3 * y / 8,11 * x / 16, y / 2},//专家难度
	{11 * x / 16,3 * y / 8,7 * x / 8, y / 2},//自定义
	{x / 8,y / 2, 7 * x / 8, 5 * y / 8},//结束按钮
	{ x / 8,5 * y / 8,7 * x / 8, 3 * y / 4 }, //开始游戏按钮
	{ 7 * x / 8,0, x,  y / 8 } ,//切换撤回功能
	{ 0,0, x/8,  y / 8 } //切换滑点功能
};
int selectedDifficulty = -1; // 记录被选中的难度
int lastSelectedButton = -1; // 记录上一次被选中的难度
char lastSelectedButtonname[100] = "";// 记录上一次被选中的难度名

// 定义最大行数、列数和雷数
#define MAX_ROWS 42
#define MAX_COLS 24
#define MAX_MINES 1008
#define IMG_SIZE 40//单格大小

IMAGE img[13];//载入图片
int num = 0;//已打开的非雷格数
int mx;//鼠标所在格行数
int my;//鼠标所在格列数
bool move = false;//是否启用滑点功能
bool revoke = false;//是否启用撤回功能
bool leftButtonProcessed = false;// 定义全局变量，用于标记鼠标左键是否已经被处理
bool rightButtonProcessed = false;// 定义全局变量，用于标记鼠标右键是否已经被处理