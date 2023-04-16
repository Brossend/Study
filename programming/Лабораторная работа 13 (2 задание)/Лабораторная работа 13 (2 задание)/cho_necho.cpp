#include "cho_necho.h"

int cho_necho1(int seq[4][4], int* ch, int* nch)
{
	*ch = 0;
	*nch = 0;
	for (int i = 0; i < 4; i++) // —чет четных и нечетных 1 матрица
	{
		for (int j = 0; j < 4; j++)
		{
			if ((seq[i][j] % 2) == 0)
			{
				*ch += 1;
			}
			else
			{
				*nch += 1;
			}
		}
	}
	return 0;
}


int cho_necho2(int seq[6][6], int* ch, int* nch)
{
	*ch = 0;
	*nch = 0;
	for (int i = 0; i < 6; i++) // —чет четных и нечетных 2 матрица
	{
		for (int j = 0; j < 6; j++)
		{
			if ((seq[i][j] % 2) == 0)
			{
				*ch += 1;
			}
			else
			{
				*nch += 1;
			}
		}
	}
	return 0;
}
