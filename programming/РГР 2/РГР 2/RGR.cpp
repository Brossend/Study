#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Sys.h"
#include "task.h"

#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	SetConsoleTitle(L"РГР второй семестр, Лямцев И.А., ПИ-212");
	setlocale(LC_ALL, "ru");

	int X = 53, Y = 14;
	char button;

	while (true)
	{
		Non_cursor(false, 100);
		system("mode con cols=123 lines=31");
		system("color 1F");

		if (Y > 17)
		{
			Y = 14;
		}
		else if (Y < 14)
		{
			Y = 17;
		}

		menu(Y);

		XY(X, Y);

		button = _getch();

		if (button == -32)
		{
			button = _getch();
		}

		switch (button)
		{
		case UP:
		{
			Y--;
			break;
		}
		case DOWN:
		{
			Y++;
			break;
		}
		case ESC:
		{
			exit_out();
		}
		case ENTER:
		{

			switch (Y)
			{
			case 14:
			{
				system("cls");

				animation();

				Sleep(1);

				system("cls");

				break;
			}
			case 15:
			{
				system("cls");

				g_o_l();

				Sleep(1);

				_getch();

				system("cls");

				break;
			}
			case 16:
			{
				system("cls");

				Sleep(60);

				about_the_author();

				_getch();

				system("cls");

				break;
			}
			case 17:
			{
				exit_out();
			}
			}
		}
		}
	}
}