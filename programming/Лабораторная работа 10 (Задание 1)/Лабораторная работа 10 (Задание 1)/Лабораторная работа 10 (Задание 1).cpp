#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int sum, alfa;
	char seq1[]{ 'S','U','M','\0' }, seq2[]{ 'A','L','F','A','\0' };

	sum = seq1[0] + seq1[1] + seq1[2];
	alfa = 'A' + 'L' + 'F' + 'A';

	cout << "SUM = " << sum << "!\nALFA = " << alfa << "!" << endl;

	if (sum > alfa)
	{
		cout << "\nSUM больше!" << endl;
	}
	else if (alfa > sum)
	{
		cout << "\nALFA больше!" << endl;
	}
	else
	{
		cout << "\nALFA и SUM равны!" << endl;
	}

	_getch();
	return 0;
}