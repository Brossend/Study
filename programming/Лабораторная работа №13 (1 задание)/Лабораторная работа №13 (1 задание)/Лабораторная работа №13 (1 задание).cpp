#include <iostream>
#include <conio.h>
#include "fooABC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	extern int A[], B[], C[];

	cout << "Количество неотрицательных чисел в трех массивах равно: " << fooABC(A, B, C, 6, 8, 7) << endl;

	_getch();
	return(0);
}