#include <iostream>
#include <Windows.h>
#include <string>
#include "Sys.h"

HANDLE hStdOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwndd = GetConsoleWindow();
HDC hdc = GetDC(hwndd);

using namespace std;

enum class color : unsigned short
{
	black, blue, green, cyan, red, magenta, brown, lightgray, darkgray,
	lightblue, lightgreen, lightcyan, lightred, lightmagenta, yellow, white
};

void XY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut1, { x, y });
}

void Non_cursor(bool show, short size)
{
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(hStdOut1, &cur_info);
	cur_info.bVisible = show;
	cur_info.dwSize = size;
	SetConsoleCursorInfo(hStdOut1, &cur_info);
}

void set_col(color foreground, color background)
{
	SetConsoleTextAttribute(hStdOut1, ((short)background << 4) | (short)foreground);
}

int exit_out()
{
	XY(0, 25);

	set_col(color::lightcyan, color::blue);

	cout << "Завершение работы программы..." << endl;

	Sleep(500);

	exit(0);
}

int menu(int line)
{
	int Y = 14;

	XY(53, 14);

	string menu[]{ "1> Заставка", "2> Игра \"Жизнь\"", "3> Об авторе", "4> Выход" };

	for (int i = 0; i < 4; i++)
	{
		if ((i + 14) == line)
		{
			set_col(color::white, color::blue);
		}
		else
		{
			set_col(color::lightcyan, color::blue);
		}
		XY(53, Y++);
		cout << menu[i];
	}
	return 0;
}