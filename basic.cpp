#include "basic.h"
#include "music.h"
#include "moving.h"
#include "word.h"
#include <graphics.h>
#include <MMstream.h>
#include<conio.h>
#include <iostream>
#pragma comment (lib,"winmm.lib")
using namespace std;
basic::basic()
{
	initgraph(569,750);
	loadimage(NULL, _T("background1.jpg"));
	mciSendString(_T("open seeYouAgain.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat "), 0, 0, 0);
}

void basic::wholeProcess()
{
	moving demo;
	demo.click1(0, 0, 0);
	demo.username();
	demo.line();
	demo.click1(0, 0, 0);
	demo.cakeWord();
	demo.couplet();
	demo.click1(0, 0, 0);
	demo.finalp();
	demo.click1(255, 255, 255);
	demo.transition();
	_getch();
	closegraph();
}

