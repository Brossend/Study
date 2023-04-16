#include "switch_zero.h"

int switch_zero1(int seq[4][4])
{
	for (int i = 0; i < 4; i++) // Обнуление четных элементов 1 матрица
	{
		for (int j = 0; j < 4; j++)
		{
			if (((i % 2) == true) && ((j % 2) == true))
			{
				seq[i][j] = 0;
			}
		}
	}
	return 0;
}

int switch_zero2(int seq[6][6])
{
	for (int i = 0; i < 6; i++) // Обнуление четных элементов 2 матрица
	{
		for (int j = 0; j < 6; j++)
		{
			if (((i % 2) == true) && ((j % 2) == true))
			{
				seq[i][j] = 0;
			}
		}
	}
	return 0;
}
