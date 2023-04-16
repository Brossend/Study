#include <iostream>
#include <conio.h>
#include "var.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	var A;

	A.check();

	A.print();

	_getch();
	return(0);
}