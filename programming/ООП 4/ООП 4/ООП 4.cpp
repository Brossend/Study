#include <iostream>
#include <conio.h>
#define SIZE 3

using namespace std;

class polinom
{
public:
	int h = 0;
	int* seq = new int[SIZE];

	void print_result_minus()
	{
		cout << "Действие \"минус\"!" << endl;

		for (int i = 0; i < SIZE; i++)
		{
			cout << i + 1 << "-й коэффициент: " << seq[i] << "\t";
		}
		cout << "\n" << endl;

		delete[] seq;
	}

	void print_result_division()
	{
		cout << "Действие \"деление\"!" << endl;

		for (int i = 0; i < h; i++)
		{
			cout << "Результат деления:\n" << h << "-й коэффициент: " << seq[i] << "\t";
		}

		cout << "\n" << endl;

		delete[] seq;
	}
};

polinom operator - (polinom a, polinom b)
{
	polinom sum;

	for (int i = 0; i < SIZE; i++)
	{
		sum.seq[i] = a.seq[i] - b.seq[i];
	}

	return sum;
}

polinom operator / (polinom a, polinom b)
{
	polinom sum;

	int* A = new int[SIZE];
	sum.h;

	for (int i = 0; i < SIZE; i++)
	{
		b.seq[i] = b.seq[i] * a.seq[0];
		sum.seq[i] = a.seq[0];
	}

	sum.h++;

	for (int i = 0; i < SIZE; i++)
	{
		A[i] = a.seq[i] - b.seq[i];
	}

	delete[] A;

	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");

	polinom A, B;

	cout << "______________________________________\n1-й полином!" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Введите коэффициент " << i + 1 << "-го элемента: ";
		cin >> A.seq[i];
	}

	cout << "\n______________________________________\n2-й полином!" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Введите коэффициент " << i + 1 << "-го элемента: ";
		cin >> B.seq[i];
	}

	cout << "\n______________________________________" << endl;

	polinom C1 = A - B;

	C1.print_result_minus();

	polinom C2 = A / B;

	C2.print_result_division();

	_getch();
	return 0;
}