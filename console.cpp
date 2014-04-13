#include "consoleColours.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>

void Console::gotoXY (int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X= xpos; scrn.Y= ypos;
	SetConsoleCursorPosition(hOutput,scrn);
}

void Console::setColour(int dwFront, int dwBack)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * dwBack + dwFront);
}

