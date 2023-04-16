#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "first.h"
#include "sixth.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int choise;

	while (true)
	{
		cout << "Выберете номер лабораторной работы! (1-я или 6-я)\n>>> ";
		cin >> choise;

		if (choise == 1)
		{
			cout << "\nВы выбрали первую лабораторную работу!" << endl;

			Sleep(150);

			int x1, x2;

			first A;

			cout << "\nПервое задание!\n\"Вычислить функцию.\"\n\nВведите X1: ";
			cin >> x1;

			A.Set_x1(x1);

			cout << "Ответ первого задания для X1: " << A.ex1_x1() << "!\n\nВведите X2: ";
			cin >> x2;

			A.Set_x2(x2);

			cout << "Ответ первого задания для X2: " << A.ex1_x2() << "!\n\nКонец программы, нажмите что-нибудь для завершения!" << endl;

			break;
		}
		else if (choise == 6)
		{

			cout << "\nВы выбрали вторую лабораторную работу!" << endl;

			Sleep(150);

			sixth A;

			A.metod();

			break;
		}
		else
		{
			cout << "\nВы выбрали не 1-ю или 6-ю лабораторную работу!" << endl;
		}
	}

	_getch();
	return(0);
}