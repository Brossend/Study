#include <iostream>
#include <conio.h>
#define SIZE 5

using namespace std;

int u(int A[SIZE][SIZE], int B[SIZE][SIZE], int RESULT[SIZE][SIZE], int* sum_plus, int* sum_minus, int* sum_zero);

int main()
{
	setlocale(LC_ALL, "ru");

	int sum_plus = 0, sum_minus = 0, sum_zero = 0, A[SIZE][SIZE]{ {1,0,-3,0,5}, {0,8,0,4,34}, {-9,2,-89,0,5}, {0,22,0,-41,5}, {0,-2,0,44,5} },
		C[SIZE][SIZE]{ {0,2,33,-66,0}, {21,0,-73,0,5}, {0,2,85,0,-5}, {56,0,-3,4,0}, {1,0,38,-4,0} }, RESULT[SIZE][SIZE]{ {0,0,0,0,0}, {0,0,0,0,0},
		{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };

	u(A, A, RESULT, &sum_plus, &sum_minus, &sum_zero);

	cout << "\t     Результат!\n" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "|";
		for (int j = 0; j < SIZE; j++)
		{
			printf("%6d|", RESULT[i][j]);
		}
		cout << "\n";
	}

	cout << "\nКоличество положительных: " << sum_plus << "\nКоличество отрицательных: " <<
		sum_minus << "\nКоличество нулевых: " << sum_zero << endl;

	_getch();
	return 0;
}

int u(int A[SIZE][SIZE], int B[SIZE][SIZE], int RESULT[SIZE][SIZE], int* sum_plus, int* sum_minus, int* sum_zero)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < SIZE; l++)
			{
				RESULT[i][j] += A[i][l] * B[l][j];
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (RESULT[i][j] == 0)
			{
				*sum_zero += 1;
			}
			else if (RESULT[i][j] > 0)
			{
				*sum_plus += 1;
			}
			else
			{
				*sum_minus += 1;
			}
		}
	}

	return 0;
}