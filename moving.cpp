#include "moving.h"
#include "word.h"
#include "basic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <easyx.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define HEIGHT 750
#define WIDTH 570
#define charSize 15 //������Ļ�����С
wchar_t name[20];
void moving::line()//welcome�����Ķ���
{
	BeginBatchDraw();
	while (true)//�����տ��ֵĶ�����
	{
		for (int i = 0; i <= 160; i++)
		{
			Sleep(10);
			loadimage(NULL, _T("background1.jpg"));
			word::date();
			settextstyle(40, 0, _T("����"));
			for (int j = 0; j < 5; j++)
				outtextxy(275 + j * 40, 360, name[j]);
			word::welcome(i);
			FlushBatchDraw();
			if (i == 160)
				break;
		}
		break;
	}
	EndBatchDraw();
}

void moving::transition()
{
	const int heightNum = HEIGHT / charSize;
	const int widthNum = WIDTH / charSize;
	//charRain�洢��Ӧ�ַ���������Ҫ����ַ���ASCII��  
	int charRain[heightNum][widthNum];//�ַ��������ͼ�豸��Ӧ
	int colNum[widthNum];//ÿһ�ж�����
	int colorG[widthNum];//ÿһ�е��ַ���ɫ
	srand(time(0));
	for (int i = 0; i < widthNum; ++i)
	{
		colNum[i] = rand() % (heightNum);
		colorG[i] = 255;
		for (int j = 0; j < colNum[i]; ++j)
		{
			charRain[i][j] = rand() % 26 + 65;
		}
	}
	
	BeginBatchDraw();
	//ÿһ֡�ַ������ƶ���Ȼ������������µ��ַ�
	//ExMessage msg;
	//flushmessage();
	while (true)
	{
		IMAGE logo;
		loadimage(&logo, _T("logo.png"));
		putimage(120, -50, &logo);
		setbkcolor(BLACK);
		setbkmode(BLACK);
		word::gracias();
		for (int i = 0; i < widthNum; ++i)
		{
			if (colNum[i] < heightNum - 1)
			{
				for (int j = colNum[i] - 1; j >= 0; --j)
					charRain[j + 1][i] = charRain[j][i];
				charRain[0][i] = (rand() % 26) + 65;
				colNum[i]++;
			}
			else
			{
				if (colorG[i] > 60)
					colorG[i] -= 35;
				else
				{
					colNum[i] = (rand() % (heightNum * 9 / 10)) + heightNum / 10;
					colorG[i] = (rand() % 75) + 180;
					for (int j = 0; j < colNum[i]; ++j)
						charRain[j][i]= (rand() % 26) + 65;
				}
			}
		}
		//��������ַ���
		setbkmode(TRANSPARENT);
		settextcolor(GREEN);
		settextstyle(10, 10, _T("����"));
		for (int i = 0; i < widthNum; ++i)
		{
			int x = i * charSize;
			for (int j = 0; j < colNum[i]; ++j)
			{
				int y = j * charSize;
				setcolor(RGB(0, colorG[i], 0));
				outtextxy(x, y, charRain[j][i]);
				
			}
		}
		FlushBatchDraw();
		Sleep(50);
		clearrectangle(0, 0, WIDTH - 1, HEIGHT - 1);
		
		/*
		��ȡ��Ϣ,�����ǰ��Ϣ������û�У���һֱ�ȴ���û��ͬʱѭ���ͻ�ȡ�����Ϣ
		msg = getmessage(EM_MOUSE);
		if (msg.message == WM_LBUTTONDOWN)
			break;
		*/
		
	}
	EndBatchDraw();
	
}

void moving::username()
{
	InputBox(name, 10, L"�������û���");
	BeginBatchDraw();
	while (true)//�����տ��ֵĶ�����
	{
		for (int i = 0; i <= 160; i++)
		{
			Sleep(10);
			loadimage(NULL, _T("background1.jpg"));
			word::date();
			setbkmode(TRANSPARENT);
			settextcolor(BLACK);
			settextstyle(40, 0, _T("����"));
			for (int j = 0; j < 5; j++)
				outtextxy(275 + j * 40, 200 + i, name[j]);
			FlushBatchDraw();
			if (i == 160)
				break;
		}
		break;
	}
	EndBatchDraw();
}

void moving::click1(int r,int g,int b)
{
	setbkmode(TRANSPARENT);
	settextcolor(RGB(r, g, b));
	settextstyle(20, 0, _T("΢���ź�"));
	outtextxy(225, 550, _T("����������"));
	ExMessage m;//�����Ϣ�ṹ��
	flushmessage();
	while (true)
	{
		m = getmessage(EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN)
		{
			loadimage(NULL, _T("background1.jpg"));
			break;
		}
	}
}

void moving::cakeWord()//����ͼƬ
{
	BeginBatchDraw();
	for (int i = 0; i <= 360; i += 2)
	{
		Sleep(10);
		loadimage(NULL, _T("background1.jpg"));
		word::cake(i);
		FlushBatchDraw();
		if (i == 360)
			break;
	}
	EndBatchDraw();
}

void moving::couplet()//����
{
	BeginBatchDraw();
	for (int i = 0; i <= 280; i += 4)
	{
		Sleep(10);
		loadimage(NULL, _T("background1.jpg"));
		word::cake(360);
		word::couplet(i, i);
		FlushBatchDraw();
		if (i == 280)
			break;
	}


	for (int i = 500, t = 0; i >= 40 && t <= 276; i -= 5, t += 3)
	{
		Sleep(10);
		loadimage(NULL, _T("background1.jpg"));
		word::cake(360);
		word::couplet(280, 280);
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(i, 0, _T("����"));
		TCHAR horizontal[10] = _T("���������й�");
		for (int j = 0; j < 7; j++)
			outtextxy(160 + j * 40, t, horizontal[j]);
		FlushBatchDraw();
		if (t == 276)
			break;
	}

	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(40, 0, _T("����"));
	outtextxy(200, 330, _T("���տ���"));
	EndBatchDraw();
}

void moving::finalp()
{
	//loadimage(NULL, _T("finalbk,jpg"));
	BeginBatchDraw();
	for (int i = 0; i <= 60; i ++)
	{
		Sleep(5);
		loadimage(NULL, _T("finalbk.jpg"));
		word::finalword(i);
		FlushBatchDraw();
		if (i == 60)
			break;
	}
	EndBatchDraw();
}