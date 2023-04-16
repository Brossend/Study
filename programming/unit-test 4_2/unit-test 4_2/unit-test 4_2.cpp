#include <iostream>
#include <conio.h>
#include "fooABC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	fooABC obj;

	obj.print();

	_getch();
	return(0);
}