#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

struct TP_types
{
	string name;
	string type;
	char operations[256];
	//string operations;
} types[256];

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string c,d;
	int i = 0;
	char seq1[256]{}, seq2[256]{},seq3[256]{}, p;

	cout << "Типы ТР\n" << endl;

	while (true)
	{
		cout << "Введите имя " << i + 1 << "-го типа: ";
		getline(cin, types[i].name);
		cout << "Введите тип: ";
		getline(cin, types[i].type);
		cout << "Введите операции (или операцию), разрешенные(-ую) в данном типе: ";
		getline(cin, d);
		strcpy_s(types[i].operations, d.c_str());

		cout << "\n\nХотите продолжить ввод? Нажмите ENTER. Если нет, то напишите \"Стоп\": ";
		getline(cin, c);
		cout << endl;

		if ((c == "стоп") || (c == "Стоп"))
		{
			break;
		}

		i++;
	}

	int k = 0, u = 0;

	for (int l = 0; l <= i; l++)
	{
		while (true)
		{
			p = types[l].operations[k];

			if (p == 44)
			{
				k++;
			}
			else if (p == '\0')
			{
				k = 0;
				break;
			}
			else
			{
				seq1[u] = p;
				k++;
				u++;
			}
		}
	}

	for (int i = 0; i < u; i++) ///Повторы
	{
		for (int j = i; j < u; j++)
		{
			if (j == i)
			{
				continue;
			}
			else
			{
				if (seq1[i] == seq1[j])
				{
					seq1[j] = ',';
				}
			}
		}
	}

	u = 0, k = 0;

	while (seq1[u] != '\0')
	{
		if (seq1[u] == 44)
		{
			u++;
		}
		else
		{
			seq2[k] = seq1[u];
			k++;
			u++;
		}
	}

	for (int j = 0, u = 0; j < k; j++)
	{
		cout << "Операция " << seq

		while (types[j].operations[u] != '0')
		{

		}
	}

	cout << "Всего " << k << " операций!\n\nСписики операций для типов." << endl;

	cout << seq2;

	/*
	for (int l = 0; l <= i; l++)
	{
		cout << "\n" << l + 1 << "-й тип: " << types[l].type << ".\nОперации типа: " << types[l].operations << ".\n" << endl;
	}
	*/

	_getch();
	return 0;
}