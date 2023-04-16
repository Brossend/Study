#include "sixth.h"
#include <iostream>

using namespace std;

bool sixth::ex6_1(int SIZE, float seq[])
{
	bool TF = false;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (seq[j] > seq[i])
			{
				TF = true;
				break;
			}
			else if (seq[j] == seq[i + 1])
			{
				TF = true;
				break;
			}
		}
	}

	return TF;
}

void sixth::metod()
{
	cout << "\nПервое задание!\n\"Дано 10 вещественных чисел. Определить, образуют ли они возрастающую последовательность.\"\n\nВведите количество вещественных чисел 1-й последовательности: ";
	cin >> SIZE1;

	float* seq = new float[SIZE1];

	if (SIZE1 > 1) // Проверка на количество чисел в последовательности. 1 число - НЕ последовательность
	{

		for (int i = 0; i < SIZE1; i++)
		{
			cout << "Введите " << i + 1 << "-e вещественнoe числo 1-й последовательности: ";
			cin >> seq[i];
		}
		if (ex6_1(SIZE1, seq) == false)
		{
			cout << "\n1-я Последовательность возрастающая!" << endl;
		}
		else
		{
			cout << "\n1-я Последовательность НЕ возрастающая!" << endl;
		}
	}
	else
	{
		cout << "\nВы ввели 1 число! Это не последовательность!" << endl;
	}

	cout << "\nВведите количество вещественных чисел 2-й последовательности: ";
	cin >> SIZE2;

	float* seq2 = new float[SIZE2];

	if (SIZE2 > 1) // Проверка на количество чисел в последовательности. 1 число - НЕ последовательность
	{
		for (int i = 0; i < SIZE2; i++)
		{
			cout << "Введите " << i + 1 << "-e вещественнoe числo 2-й последовательности: ";
			cin >> seq2[i];
		}
		if (ex6_1(SIZE2, seq2) == false)
		{
			cout << "\n2-я Последовательность возрастающая!" << endl;
		}
		else
		{
			cout << "\n2-я Последовательность НЕ возрастающая!" << endl;
		}
	}
	else
	{
		cout << "\nВы ввели 1 число! Это не последовательность!" << endl;
	}

	cout << "\nКонец программы, нажмите что-нибудь для завершения!" << endl;

	delete[] seq;
}