#include "fooABC.h"

int fooABC(int A[], int B[], int C[], int s_a, int s_b, int s_c)
{
	int a = 0, b = 0, c = 0, sum;

	for (int i = 0; i < s_a; i++)
	{
		if (A[i] >= 0)
		{
			a++;
		}
	}
	for (int i = 0; i < s_b; i++)
	{
		if (B[i] >= 0)
		{
			b++;
		}
	}
	for (int i = 0; i < s_c; i++)
	{
		if (C[i] >= 0)
		{
			c++;
		}
	}

	sum = a + b + c;

	return sum;
}
