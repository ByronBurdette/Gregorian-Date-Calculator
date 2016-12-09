
#ifndef CURSOR_H
#define CURSOR_H


#include<Windows.h>


using namespace std;


class Cursor
{
private:

public: void placeCursor(HANDLE screen, int row, int col)
		{
			COORD position;												//	declare "position" of windows struct type COORD

			position.X = row;											//	member variable "X" gets what's stored in "row"
			position.Y = col;											//	member variable "Y" gets what's stored in "col"

			SetConsoleCursorPosition(screen, position);					/*	call standard windows function "SetConsoleCursorPosition" to place		*/
		}																/*	the cursor on the starndard output at cell "position"					*/
};
#endif