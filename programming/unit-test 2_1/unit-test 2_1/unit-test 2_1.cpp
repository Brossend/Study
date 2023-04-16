#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include "repeat.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	repeat A1(20);

	A1.do_while();

	_getch();
	return(0);
}