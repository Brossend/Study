#include "varrr.h"
#include <iostream>

using namespace std;

varrr::~varrr()
{
	delete[]seq;
}

int varrr::Get_TF()
{
	return TF;
}

void varrr::metod()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (seq[j] > seq[i])
			{
				TF = true;
				break;
			}
		}
	}
}

void varrr::print()
{
	if (TF == false)
	{
		cout << "Последовательность возрастающая!" << endl;
	}
	else
	{
		cout << "Последовательность НЕ возрастающая!" << endl;
	}
}