#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <math.h>

#define a 0
#define PI 3.1415926535
#define b 2*PI
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER 13

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void XY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void Non_cursor(bool show, short size)
{
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(hStdOut, &cur_info);
	cur_info.bVisible = show; // изменяем видимость курсора
	cur_info.dwSize = size;   // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &cur_info);
}

int menu(int line)
{
	int Y = 12;

	XY(50, 12);

	string menu[]{ "1> Заставка", "2> Таблица", "3> Графики", "4> Уравнение", "5> Интеграл", "6> Об авторе", "7> Выход" };

	for (int i = 0; i < 7; i++)
	{
		if ((i + 12) == line)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		XY(50, Y++);
		cout << menu[i];
	}
	return 0;
}

void about_the_author()
{
	int Y = 12;
	string about_the_author[]{ "Расчетно-графическая работа", "По дисциплине \"программирование\"", "Разработал:", "Студент 1-го курса ОмГТУ", "Лямцев Иван Алексеевич, группа ПИ-212" };

	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	for (int i = 0; i < 5; i++)
	{
		XY(40, Y++);
		cout << about_the_author[i];
	}

	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	XY(0, 25);
	cout << "Нажмите любую клавишу, чтобы выйти в меню..." << endl;
}

void timeline()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "11 вариант" << endl;

	XY(40, 10);

	cout << "X";

	XY(19, 3);

	cout << "Y";

	XY(19, 10);

	cout << "0";

	XY(22, 10);

	cout << "1";

	XY(19, 9);

	cout << "1";

	{
		XY(42, 4);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "F(x) = 5 - 3*cos(x)";
	}
	{
		XY(42, 8);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "F(x) = sqrt(1 + pow(sin(y), 2))";
	}

	XY(0, 15);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Нажмите любую клавишу, чтобы выйти в меню..." << endl;

	Sleep(1);


	HDC dc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(128, 0, 128));

	SelectObject(dc, Pen);
	MoveToEx(dc, 10, 155, NULL);
	LineTo(dc, 330, 155);
	MoveToEx(dc, 170, 50, NULL);
	LineTo(dc, 170, 170);

	for (int i = 60; i < 170; i += 10) // Засечки Оу
	{
		MoveToEx(dc, 168, i, NULL);
		LineTo(dc, 171, i);
	}
	for (int i = 20; i < 330; i += 10) // Засечки Ох
	{
		MoveToEx(dc, i, 153, NULL);
		LineTo(dc, i, 156);
	}

	for (int i = 52; i <= 55; i++) // Стрелочка Oy
	{
		if (i <= 53)
		{
			MoveToEx(dc, 168, i, NULL);
			LineTo(dc, 171, i);
		}
		else
		{
			MoveToEx(dc, 167, i, NULL);
			LineTo(dc, 172, i);
		}
	}
	for (int i = 328; i >= 325; i--) // Стрелочка Ox
	{
		if (i >= 326)
		{
			MoveToEx(dc, i, 153, NULL);
			LineTo(dc, i, 156);
		}
		else
		{
			MoveToEx(dc, i, 152, NULL);
			LineTo(dc, i, 157);
		}
	}

	DeleteObject(Pen);

	for (float x = -15; x <= 15; x += 0.01) // 170:155 - центр
	{
		SetPixel(dc, 10 * x + 170, -10 * (5 - 3 * cos(x)) + 155, RGB(0, 255, 255));
	}

	for (float x = -15; x <= 15; x += 0.01)
	{
		SetPixel(dc, 10 * x + 170, -10 * (sqrt(1 + pow(sin(x), 2))) + 155, RGB(249, 241, 165));
	}
}

void integral()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "11 вариант" << endl;

	double A, B, sum1 = 0;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << "\nВведите начало промежутка: ";
	cin >> A;
	cout << "\nВведите конец промежутка: ";
	cin >> B;

	int N = 1500;
	double h = (B - A) / N, sum2 = (exp(2 * A) * sin(2 * A)) + (exp(2 * B) * sin(2 * B));

	for (int i = 0; i <= N - 1; i++) //Метод Прямоугольников
	{
		sum1 += h * (exp(2 * (A + i * h)) * sin(2 * (A + i * h)));
	}

	for (int i = 1; i <= N - 1; i++) // Метод Трапеций
	{
		sum2 += 2 * (exp(2 * (A + i * h)) * sin(2 * (A + i * h)));
	}
	sum2 *= h / 2;

	XY(0, 6);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Метод прямоугольников:\nОтвет = " << sum1 << "\nПри a = " << A << ", b = " << B << ", n = 1500!" << endl;

	XY(0, 10);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Метод трапеции:\nОтвет = " << sum2 << "\nПри a = " << A << ", b = " << B << ", n = 1500!" << endl;

	XY(0, 14);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Нажмите любую клавишу, чтобы выйти в меню..." << endl;
}

void chart()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "11 вариант" << endl;

	int Y = 12;
	const int N = 20;
	double X, y = 0, seq[3][22], max1, max2, min1, min2;

	X = b / N;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	printf(" _________ _________ _________ _________ \n|         |         |         |         |\n|    N    |    X    |   F1!   |   F2!   |\n|_________|_________|_________|_________|\n");

	max1 = 5 - 3 * cos(0.314);
	max2 = sqrt(1 + pow(sin(0.314), 2));
	min1 = 5 - 3 * cos(0.314);
	min2 = sqrt(1 + pow(sin(0.314), 2));

	for (int i = 0; y <= b; y += X, i++)
	{
		Sleep(1);
		seq[0][i] = y;
		seq[1][i] = 5 - 3 * cos(y);
		seq[2][i] = sqrt(1 + pow(sin(y), 2));

		if (seq[1][i] > max1)
		{
			max1 = seq[1][i];
		}
		else if (seq[2][i] > max2)
		{
			max2 = seq[2][i];
		}
		else if (seq[1][i] < min1)
		{
			min1 = seq[1][i];
		}
		else if (seq[2][i] < min2)
		{
			min2 = seq[2][i];
		}
	}

	for (int i = 0; i < 21; i++)
	{
		if (seq[1][i] == max1)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else if (seq[2][i] == max2)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else if (seq[1][i] == min1)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else if (seq[2][i] == min2)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}

		printf("|         |         |         |         |\n|%5d    |%9.7f|%9.7f|%9.7f|\n|_________|_________|_________|_________|\n", i, seq[0][i], seq[1][i], seq[2][i]);

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}

	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\nМаксимальное значение первой функции: " << max1 << "!\nМаксимальное значение второй функции: " << max2 << "!" << endl;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\nМинимальное значение первой функции: " << min1 << "!\nМинимальное значение второй функции: " << min2 << "!" << endl;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\nНажмите любую клавишу, чтобы выйти в меню..." << endl;
}

void animation()
{
	HWND hwnd = GetConsoleWindow();
	HDC dc = GetDC(hwnd);

	XY(20, 15);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "ПРЕДУПРЕЖДЕНИЕ! Нажмите клавишу SPACEBAR, чтобы выйти в меню из заставки!" << endl;

	Sleep(1500);

	system("cls");

	int x1 = 0, x2 = 90, y1 = -90, y2 = 0,
		x11 = 300, x22 = 340, y11 = -500, y22 = -590,
		x111 = 700, x222 = 740, y111 = -1000, y222 = -1090,
		x1111 = 540, x2222 = 580, y1111 = -1500, y2222 = -1590;

	for (;; y1 += 7, y2 += 7, y11 += 7, y22 += 7, y111 += 7, y222 += 7, y1111 += 7, y2222 += 7)
	{

		SelectObject(dc, GetStockObject(DC_BRUSH)); // 1
		SetDCBrushColor(dc, RGB(97, 214, 214));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(97, 214, 214));

		Rectangle(dc, x1, y1 - 7, x2, y2 - 7);

		SelectObject(dc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(dc, RGB(0, 255, 255));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(0, 0, 0));

		Rectangle(dc, x1, y1, x2, y2);

		SelectObject(dc, GetStockObject(DC_BRUSH)); // 2
		SetDCBrushColor(dc, RGB(181, 178, 90));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(181, 178, 90));

		Rectangle(dc, x11, y11 - 7, x22, y22 - 7);

		SelectObject(dc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(dc, RGB(216, 213, 105));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(0, 0, 0));

		Rectangle(dc, x11, y11, x22, y22);

		SelectObject(dc, GetStockObject(DC_BRUSH)); // 3
		SetDCBrushColor(dc, RGB(88, 121, 198));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(88, 121, 198));

		Rectangle(dc, x111, y111 - 7, x222, y222 - 7);

		SelectObject(dc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(dc, RGB(106, 145, 236));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(0, 0, 0));

		Rectangle(dc, x111, y111, x222, y222);

		SelectObject(dc, GetStockObject(DC_BRUSH)); // 4
		SetDCBrushColor(dc, RGB(136, 23, 152));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(136, 23, 152));

		Rectangle(dc, x1111, y1111 - 7, x2222, y2222 - 7);

		SelectObject(dc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(dc, RGB(168, 28, 186));
		SelectObject(dc, GetStockObject(DC_PEN));
		SetDCPenColor(dc, RGB(0, 0, 0));

		Rectangle(dc, x1111, y1111, x2222, y2222);

		Sleep(10);

		if (y2 > 700) // 1
		{
			y1 = -90;
			y2 = 0;

			if ((x2 > 850) && (x1 > 850))
			{
				x1 = 0 + rand() % 200;
				x2 = 90 + rand() % 200;
			}
			else
			{
				x1 += rand() % 200;
				x2 += rand() % 200;
			}
		}
		if (y22 > 700) // 2
		{
			y11 = -500;
			y22 = -590;

			if ((x22 > 850) && (x11 > 850))
			{
				x11 = 60 + rand() % 200;
				x22 = 150 + rand() % 200;
			}
			else
			{
				x11 += rand() % 200;
				x22 += rand() % 200;
			}
		}
		if (y222 > 700) // 3
		{
			y111 = -1000;
			y222 = -1090;

			if ((x222 > 850) && (x111 > 850))
			{
				x111 = 10 + rand() % 200;
				x222 = 100 + rand() % 200;
			}
			else
			{
				x111 += rand() % 200;
				x222 += rand() % 200;
			}
		}
		if (y2222 > 700) // 4
		{
			y1111 = -1500;
			y2222 = -1590;

			if ((x2222 > 850) && (x1111 > 850))
			{
				x1111 = 10 + rand() % 200;
				x2222 = 100 + rand() % 200;
			}
			else
			{
				x1111 += rand() % 200;
				x2222 += rand() % 200;
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) // Функция для считывания клавиши пробела
		{
			break;
		}
	}
}

double equation(double x)
{
	return 2 * cbrt(pow(x, 2) + 1) - 3 * sin(x) - 5;
}

void equation_score()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "15 вариант" << endl;

	double A1, B1, A, B, C, X, E = 0.001;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << "\nВведите начало промежутка: ";
	cin >> A1;
	cout << "\nВведите конец промежутка: ";
	cin >> B1;

	A = A1;
	B = B1;

	while (abs(B - A) > E) // Метод хорд
	{
		C = A - (((B - A) / (equation(B) - equation(A)) * equation(A)));

		if ((equation(A) * equation(C)) > 0)
		{
			A = C;
		}
		else
		{
			B = C;
		}
	}

	X = (A + B) / 2;

	A = A1;
	B = B1;

	while ((B - A) > 0.001) // Метод бисекции
	{
		C = (A + B) / 2;

		if (((equation(C) > 0) && (equation(B) > 0)) || ((equation(C) < 0) && (equation(B) < 0)) || (((equation(C) == 0) && (equation(B) == 0))))
		{
			B = C;
		}
		else
		{
			A = C;
		}
	}

	A = A1;
	B = B1;

	XY(0, 6);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Метод хорд:\nОтвет: " << X << ",\nпри а = " << A << ", b = " << B << "!" << endl;

	XY(0, 10);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Метод бисекции:\nОтвет: " << C << ",\nпри а = " << A << ", b = " << B << "!" << endl;

	XY(0, 14);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Нажмите любую клавишу, чтобы выйти в меню..." << endl;
}

int main()
{
	SetConsoleTitle(L"РГР, Лямцев И.А., ПИ-212");
	setlocale(LC_ALL, "ru");
	Non_cursor(false, 100);

	int X = 50, Y = 12;
	char button;

	while (true)
	{
		if (Y > 18) // Два условия проверки координат активной "кнопки".Нужно, чтобы координата активной кнопки не уходила за пределы выбора
		{
			Y = 12;
		}
		else if (Y < 12)
		{
			Y = 18;
		}

		menu(Y);

		XY(X, Y);

		button = _getch(); //Считывание нажатой клавиши
		if (button == -32) //Условие для считывания клавиши и перевода из 2 байтной кодировки в 1 байтную 
		{
			button = _getch(); //Повторное считывание нажатой клавиши
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
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

			XY(0, 25);

			cout << "Завершение работы программы..." << endl;

			Sleep(500);

			return(0);
		}
		case ENTER:
		{

			switch (Y)
			{
			case 12:
			{
				system("cls");

				Sleep(1);

				animation();

				system("cls");

				break;
			}
			case 13:
			{
				system("cls");

				Sleep(1);

				chart();

				_getch();

				system("cls");

				break;
			}
			case 14:
			{
				system("cls");

				Sleep(1);

				timeline();

				_getch();

				system("cls");

				break;
			}
			case 15:
			{
				system("cls");

				Sleep(1);

				equation_score();

				_getch();

				system("cls");

				break;
			}
			case 16:
			{
				system("cls");

				integral();

				_getch();

				system("cls");

				break;
			}
			case 17:
			{
				system("cls");

				Sleep(60);

				about_the_author();

				_getch();

				system("cls");

				break;
			}
			case 18:
			{
				XY(0, 25);

				SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

				cout << "Завершение работы программы..." << endl;

				Sleep(500);

				return(0);
			}
			}
		}
		}
	}
}