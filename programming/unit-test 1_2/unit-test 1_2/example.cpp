#include "example.h"
#include <iostream>

using namespace std;

example::example(int a)
{
	this->a = a;
}

int example::Get_result()
{
	return result;;
}

int example::residue()
{
	rem = a % 5;
	return 0;
}

void example::print()
{
	switch (rem)
	{
	case 0:
		result = 0;
		cout << "����" << endl;
		break;
	case 1:
		result = 1;
		cout << "����" << endl;
		break;

	case 2:
		result = 2;
		cout << "���" << endl;
		break;

	case 3:
		result = 3;
		cout << "���" << endl;
		break;

	case 4:
		result = 4;
		cout << "������" << endl;
		break;
	}
}
