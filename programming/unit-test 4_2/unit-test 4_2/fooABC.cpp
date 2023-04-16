#include "fooABC.h"
#include <iostream>

using namespace std;

int fooABC::FooABC()
{
	int a = 0, b = 0, c = 0, sum;

	for (int i = 0; i < 6; i++)
	{
		if (A[i] >= 0)
		{
			a++;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (B[i] >= 0)
		{
			b++;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (C[i] >= 0)
		{
			c++;
		}
	}

	sum = a + b + c;

	return sum;
}

void fooABC::print()
{
	cout << "Количество неотрицательных чисел в трех массивах равно: " << FooABC();
}
