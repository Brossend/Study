#include "var.h"
#include <iostream>

using namespace std;

int var::Get_TF()
{
	return TF;
}

void var::check()
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

void var::print()
{
	if (TF == false)
	{
		cout << "������������������ ������������!" << endl;
	}
	else
	{
		cout << "������������������ �� ������������!" << endl;
	}
}

var::~var()
{
	delete[] seq;
}
