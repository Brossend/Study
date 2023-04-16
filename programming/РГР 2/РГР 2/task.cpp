#include <iostream>
#include <Windows.h>
#include "task.h"
#include "Sys.h"
#include "game_of_life.h"

HANDLE hStdOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow();
HDC dc = GetDC(hwnd);

using namespace std;

enum class colorr : unsigned short
{
	black, blue, green, cyan, red, magenta, brown, lightgray, darkgray,
	lightblue, lightgreen, lightcyan, lightred, lightmagenta, yellow, white
};

void set_col(colorr foreground, colorr background)
{
	SetConsoleTextAttribute(hStdOut2, ((short)background << 4) | (short)foreground);
}

void about_the_author()
{
	int Y = 12;
	string about_the_author[]{ "��������-����������� ������", "�� ���������� \"����������������\"", "����������:", "������� 1-�� ����� �����", "������ ���� ����������, ������ ��-212" };

	set_col(colorr::lightcyan, colorr::blue);

	for (int i = 0; i < 5; i++)
	{
		XY(40, Y++);
		cout << about_the_author[i];
	}

	set_col(colorr::lightcyan, colorr::blue);
	XY(0, 25);
	cout << "������� ����� �������, ����� ����� � ����..." << endl;
}

void animation()
{
	float i = 0, k = 980, u = 490;

	XY(23, 15);
	set_col(colorr::lightcyan, colorr::blue);
	cout << "��������������! ������� ������� SPACEBAR, ����� ����� � ���� �� ��������!" << endl;

	Sleep(1500);

	system("cls");

	while (true)
	{

		HPEN p2 = CreatePen(PS_SOLID, 4, RGB(1, 92, 101));

		SelectObject(dc, p2);

		MoveToEx(dc, 0, 0, NULL); // ��������� �����
		LineTo(dc, 490, 490);
		MoveToEx(dc, 490, 490, NULL); // ��������� ������
		LineTo(dc, 980, 0);

		MoveToEx(dc, 0, 490, NULL); // ��� ��������� �����
		LineTo(dc, 490, 0);

		MoveToEx(dc, 980, 490, NULL); // ��� ��������� �����
		LineTo(dc, 490, 0);

		DeleteObject(p2);

		HPEN p3 = CreatePen(PS_SOLID, 2, RGB(136, 110, 215));

		SelectObject(dc, p3);

		MoveToEx(dc, 0, i, NULL); // ������ �����
		LineTo(dc, 980, i);

		MoveToEx(dc, 0, u, NULL); // ������� �����
		LineTo(dc, 980, u);

		MoveToEx(dc, i, 0, NULL); // ����� �����
		LineTo(dc, i, 490);
		MoveToEx(dc, k, 0, NULL); // ������ �����
		LineTo(dc, k, 490);

		DeleteObject(p3);

		HPEN p4 = CreatePen(PS_SOLID, 3, RGB(255, 232, 115));

		SelectObject(dc, p4);

		MoveToEx(dc, i, 0, NULL); // ����� �����
		LineTo(dc, k, 490);

		MoveToEx(dc, i, 490, NULL); // ����� �����
		LineTo(dc, k, 0);

		MoveToEx(dc, i, 0, NULL); // 1v ����� �����
		LineTo(dc, 0, 490);

		MoveToEx(dc, 0, 0, NULL); // 1n ����� �����
		LineTo(dc, i, 490);

		MoveToEx(dc, 980, 0, NULL); // 3v ����� �����
		LineTo(dc, k, 490);

		MoveToEx(dc, k, 0, NULL); // 3n ����� �����
		LineTo(dc, 980, 490);

		DeleteObject(p4);

		HPEN p1 = CreatePen(PS_SOLID, 6, RGB(255, 181, 115));

		SelectObject(dc, p1);

		MoveToEx(dc, 0, 490, NULL);
		LineTo(dc, 980, 490); // ����� ������
		MoveToEx(dc, 0, 0, NULL);
		LineTo(dc, 980, 0); // ����� �������

		MoveToEx(dc, 980, 0, NULL);
		LineTo(dc, 980, 490); // ����� ������
		MoveToEx(dc, 0, 0, NULL);
		LineTo(dc, 0, 490); // ����� �����

		DeleteObject(p1);

		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}

		if (i == 490)
		{
			for (float j = 490; j > 0; j -= 0.5)
			{

				HPEN p2 = CreatePen(PS_SOLID, 4, RGB(210, 247, 0));

				SelectObject(dc, p2);

				MoveToEx(dc, 0, 0, NULL); // ���� ��������� �����
				LineTo(dc, 490, 490);
				MoveToEx(dc, 490, 490, NULL); // ��������� ������
				LineTo(dc, 980, 0);

				MoveToEx(dc, 0, 490, NULL); // ��� ��������� �����
				LineTo(dc, 490, 0);

				MoveToEx(dc, 980, 490, NULL); // ��� ��������� �����
				LineTo(dc, 490, 0);

				DeleteObject(p2);

				HPEN p3 = CreatePen(PS_SOLID, 2, RGB(0, 178, 92));

				SelectObject(dc, p3);

				MoveToEx(dc, 0, j, NULL); // ������ �����
				LineTo(dc, 980, j);

				MoveToEx(dc, 0, u, NULL); // ������� �����
				LineTo(dc, 980, u);

				MoveToEx(dc, i, 0, NULL); // ����� �����
				LineTo(dc, i, 490);
				MoveToEx(dc, k, 0, NULL); // ������ �����
				LineTo(dc, k, 490);

				DeleteObject(p3);

				HPEN p4 = CreatePen(PS_SOLID, 3, RGB(255, 65, 0));

				SelectObject(dc, p4);

				MoveToEx(dc, i, 0, NULL); // 2����� �����
				LineTo(dc, k, 490);

				MoveToEx(dc, i, 490, NULL); // 2����� �����
				LineTo(dc, k, 0);

				MoveToEx(dc, k, 0, NULL); // 1v ����� �����
				LineTo(dc, 0, 490);

				MoveToEx(dc, 0, 0, NULL); // 1n ����� �����
				LineTo(dc, k, 490);

				MoveToEx(dc, 980, 0, NULL); // 3v ����� �����
				LineTo(dc, i, 490);

				MoveToEx(dc, i, 0, NULL); // 3n ����� �����
				LineTo(dc, 980, 490);

				DeleteObject(p4);

				HPEN p1 = CreatePen(PS_SOLID, 6, RGB(156, 2, 167));

				SelectObject(dc, p1);

				MoveToEx(dc, 0, 490, NULL);
				LineTo(dc, 980, 490); // ����� ������
				MoveToEx(dc, 0, 0, NULL);
				LineTo(dc, 980, 0); // ����� �������
				MoveToEx(dc, 980, 0, NULL);
				LineTo(dc, 980, 490); // ����� ������
				MoveToEx(dc, 0, 0, NULL);
				LineTo(dc, 0, 490); // ����� �����

				DeleteObject(p1);

				if (GetAsyncKeyState(VK_SPACE))
				{
					break;
				}

				u += 0.5;
				i += 0.5;
				k -= 0.5;
			}
			k = 980;
			i = 0;
			u = 490;
		}
		else
		{
			i += 0.5;
			k -= 0.5;
			u -= 0.5;
		}
	}
}

void g_o_l()
{
	XY(27, 15);
	set_col(colorr::lightcyan, colorr::blue);
	cout << "�� ��������� ���� \"�����\"! ������ ������������� ��������� �������!" << endl;

	Sleep(1500);

	system("cls");

	game_of_life game;

	game.start_game();
}