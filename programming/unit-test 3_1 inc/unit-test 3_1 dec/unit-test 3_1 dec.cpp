#include <iostream>
#include <conio.h>
#include "varrr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	varrr A;

	A.metod();

	A.print();

	_getch();
	return(0);
}