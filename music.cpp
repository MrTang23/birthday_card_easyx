#include "music.h"
#include <graphics.h>
#include <MMstream.h>
#include<conio.h>
#include <iostream>
#pragma comment (lib,"winmm.lib")
using namespace std;
music::music()
{
	mciSendString(_T("open seeYouAgain.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat "), 0, 0, 0);
}