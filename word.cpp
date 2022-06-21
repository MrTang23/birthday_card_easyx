#include "word.h"
#include "moving.h"
#include <graphics.h>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

void word::welcome(int t)
{
	setbkmode (TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(60, 0, _T("楷体"));
	outtextxy(275, t+280, _T("祝你"));
	TCHAR wel[10] = _T("生日快乐!");
	settextstyle(40, 0, _T("仿宋"));
	for (int i = 0; i < 6; i++)//变量i为竖排输出，同时输出数组
		outtextxy(t, t+170+i*40, wel[i]);//输出祝福语，变量t为坐标改变
}

void word::date()
{
	time_t t;
	t = time(NULL);
	tm* pt = gmtime(&t);
	TCHAR month[16];
	_itot(pt->tm_mon+1, month, 10);
	TCHAR day[5]; 
	_itot(pt->tm_mday+1, day, 10);//_itot第三个参数应该是十进制的意思
	TCHAR date[10] = { _T('今'),_T('天'),_T('是'),month[0],_T('月'),day[0],day[1],_T('日')};
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("楷体"));
	for(int i=0;i<8;i++)
		outtextxy(180+i*30, 280, date[i]);
}

void word::cake(int i)//实现蛋糕背景透明
{
	IMAGE cakeblackbk,cakewhitebk;
	loadimage(&cakeblackbk, _T("cakeblackbk.png"));
	loadimage(&cakewhitebk, _T("cakewhitebk.png"));
	putimage(180, i, &cakewhitebk, SRCAND);//宏，与
	putimage(180, i, &cakeblackbk, SRCPAINT);//宏，或
}

void word::couplet(int i, int j)
{
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("楷体"));
	TCHAR verticalCoupletRight1[10] = _T("智者不入爱河");
	TCHAR verticalCoupletLeft1[10] = _T("冤种重蹈覆辙");
	TCHAR verticalCoupletRight2[10] = _T("寡王一路硕博");
	TCHAR verticalCoupletLeft2[10] = _T("我们终成富婆");
	for (int t = 0; t < 6; t++)
	{
		outtextxy(400, i + t * 40, verticalCoupletRight1[t]);
		outtextxy(130, i + t * 40, verticalCoupletLeft1[t]);
		outtextxy(440, i + 30+t * 40, verticalCoupletRight2[t]);
		outtextxy(90, i + 30+t * 40, verticalCoupletLeft2[t]);
	}

}

void word::finalword(int i)
{
	TCHAR groupName[5] = _T("摸鱼小队");
	TCHAR membersName[15] = _T("汤宗朔孙浩源沈嘉诚蒋天乐");
	TCHAR worktzs[7] = _T("界面一和整理");
	TCHAR workshy[7] = _T("界面二和图片");
	TCHAR worksjc[7] = _T("界面三和文档");
	TCHAR workjtl[7] = _T("所有排版背景");
	for (int j = 0; j < 4; j++)
	{
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		settextstyle(i+10, 0, _T("楷体"));
		outtextxy(155 + j * 70, i-30, groupName[j]);
	}

	for (int j = 0; j < 3; j++)
	{
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		settextstyle(i-20, 0, _T("黑体"));
		outtextxy(j * 50 + i , 200, membersName[j]);
		outtextxy(j * 50 + i, 275, membersName[j+3]);
		outtextxy(j * 50 + i, 350, membersName[j+6]);
		outtextxy(j * 50 + i, 425, membersName[j+9]);
	}

	for (int j = 6; j >=0; j--)
	{
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		settextstyle(i - 30, 0, _T("仿宋"));
		outtextxy(575 - (6 - j) * 30 - i, 200, worktzs[j]);
		outtextxy(575 - (6 - j) * 30 - i, 275, workshy[j]);
		outtextxy(575 - (6 - j) * 30 - i, 350, worksjc[j]);
		outtextxy(575 - (6 - j) * 30 - i, 425, workjtl[j]);
	}
}

void word::gracias()
{
	settextcolor(WHITE);
	settextstyle(60, 0, _T("楷体"));
	outtextxy(150, 190, _T("非常简陋"));
	outtextxy(150, 250, _T("感谢观看"));
	settextstyle(40, 0, _T("楷体"));
	outtextxy(100, 370, _T("祝：事业有成/永不挂科"));
	outtextxy(150, 410, _T("——计2103 汤宗朔"));
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(150, 600, _T("bgm:see you again"));
}

