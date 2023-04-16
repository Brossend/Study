#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "var.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int N;

	while (true)
	{
		cout << "\nВведите количество точек равное 20 (по заданию): ";
		cin >> N;

		if (N == 20)
		{
			var A(N);

			A.metod();

			break;
		}
		else
		{
			cout << "\nОшибка! По заданию введите количество точек равное 20!" << endl;
		}
	}

	_getch();
	return(0);
}