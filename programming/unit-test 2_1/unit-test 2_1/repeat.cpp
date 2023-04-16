#include <iostream>
#include "repeat.h"
#define a 0
#define PI 3.1415926535
#define b 2*PI


repeat::repeat(int N)
{
	this->N = N;
}

float repeat::Get_F1_Test()
{
	return F1_Test;
}

float repeat::Get_F2_Test()
{
	return F2_Test;
}

float repeat::Get_X()
{
	return X;
}

int repeat::do_while()
{
	int i = 0;
	X = b / N;

	printf(" _________ _________ \n|         |         |\n|   F1!   |   F2!   |\n|_________|_________|\n");

	do
	{
		F1 = 5 - 3 * cos(Y);
		F2 = sqrt(1 + pow(sin(Y), 2)); //0.314159

		if (i == 5)
		{
			F1_Test = F1;
			F2_Test = F2;
		}

		printf("|         |         |\n|%9.7f|%9.7f|\n|_________|_________|\n", F1, F2);

		Y += X;
		i++;

	} while (Y <= b);

	return 0;
}
