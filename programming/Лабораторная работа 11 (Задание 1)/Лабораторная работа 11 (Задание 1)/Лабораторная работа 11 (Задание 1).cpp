#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	string file1 = "D1.txt";
	string file2 = "D2.txt";

	ifstream fin;
	fin.open(file1);

	float seq[4][4]{}, A = 0;

	if (!fin.is_open())
	{
		cout << "Ошибка имени файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!\n" << endl;

		for (int i = 0; i < 4; i++) //Считывание чисел в массив
		{
			for (int j = 0; j < 4; j++)
			{
				fin >> seq[i][j];
			}
		}

		fin.close();

		for (int i = 0; i < 4; i++) //Замена первой и последней строки
		{
			A = seq[3][i];
			seq[3][i] = seq[0][i];
			seq[0][i] = A;
		}

		ofstream fout;
		fout.open(file2);

		for (int i = 0; i < 4; i++) //Вывод чисел
		{
			for (int j = 0; j < 4; j++)
			{
				fout << seq[i][j] << " ";
			}
			fout << "\n";
		}

		fout.close();

		cout << "Операция выполнена!" << endl;
	}

	_getch();
	return 0;
}