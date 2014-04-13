#pragma once

namespace Console
{
	const int BLACK       = 0;
    const int DARKBLUE    = 1;
    const int DARKGREEN   = 2;
    const int DARKCYAN    = 3;
    const int DARKRED     = 4;
    const int DARKPINK    = 5;
	const int DARKYELLOW  = 6;
    const int DARKWHITE   = 7;
	const int GRAY        = 8;
    const int ROYALBLUE   = 9;
	const int GREEN       = 10;
    const int CYAN        = 11;
	const int RED         = 12;
    const int PINK        = 13;
	const int YELLOW      = 14;
    const int WHITE       = 15;

	void gotoXY(int xpos, int ypos);
	void setColour(int dwFront, int dwBack);
}