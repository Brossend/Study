#include <iostream>
#include <conio.h>
#define SIZE 4

using namespace std;

void shift(int Temp[SIZE][SIZE], int A[SIZE][SIZE], int offset, int* v, int* n);

int main()
{
	setlocale(LC_ALL, "ru");

	int A[SIZE][SIZE]{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} }, B[SIZE][SIZE]{ {16,15,14,13}, {12,11,10,9}, {8,7,6,5}, {4,3,2,1} },
		Temp[SIZE][SIZE]{ {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, v_a = 0, n_a = 0, v_b = 0, n_b = 0, offset;
	cout << "Введите на соклько хотите сместить массив: ";
	cin >> offset;
	cout << "\n\n     A    Результат!    B\n\n";
	shift(Temp, A, offset, &v_a, &n_a);
	shift(Temp, B, offset, &v_b, &n_b);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("|%2d", A[i][j]);
		}
		cout << "|\t";
		for (int j = 0; j < SIZE; j++)
		{
			printf("|%2d", B[i][j]);
		}
		cout << "|\n";
	}
	cout << "\nМассив A. Сумма выше диагонали: " << v_a << "\n\t  Сумма ниже диагонали: " << n_a <<
		"\n\nМассив B. Сумма выше диагонали: " << v_b << "\n\t  Сумма ниже диагонали: " << n_b << endl;
	_getch();
	return 0;
}
void shift(int Temp[SIZE][SIZE], int A[SIZE][SIZE], int offset, int* v, int* n)
{
	int k = 0, gd = 0;
	for (int l = 0; l < offset; l++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			Temp[i][0] = k;
			k = A[i][SIZE - 1];
			for (int j = 0; j < SIZE - 1; j++)
			{
				Temp[i][j + 1] = A[i][j];
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				A[i][j] = Temp[i][j];
			}
		}
		k = 0;
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (gd == j)
			{
				continue;
			}
			else
			{
				if (j > gd)
				{
					*v += A[i][j];
				}
				else if (j < gd)
				{
					*n += A[i][j];
				}
			}
		}
		gd++;
	}
}
