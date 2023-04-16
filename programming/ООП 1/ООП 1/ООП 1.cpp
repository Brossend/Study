#include <iostream>
#include <conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define BOOLEAN int

enum Boolean { False, True };

class boolean
{
public:
	int TRue = 1;
	int FAlse = 0;
	double EQUALS(double a, double b) {
		if (a == b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Равно, ==.
	double UNEQUAL(double a, double b) {
		if (a != b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Неравно, !=.
	double MORE(double a, double b) {
		if (a > b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Больше для любого числа.
	double MORE_OR_EQUAL(double a, double b) {
		if (a >= b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Больше или равно для любого числа.
	double LESS(double a, double b) {
		if (a < b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Меньше для любого числа.
	double LESS_OR_EQUAL(double a, double b) {
		if (a <= b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Меньше или равно для любого числа.
	int AND(int a, int b) {
		if ((a == 1) && (b == 1))
		{
			return 1;
		}
		else if (((a > 1) || (a < 0)) || ((b > 1) || (b < 0)))
		{
			cout << "Переменная(-ые) не равна true (1) или false (0)";
			return -1;
		}
		else
		{
			return 0;
		}
	}
	//Конъюнкция, логическое умножение, "И", &&.
	int OR(int a, int b) {
		if ((a == 0) && (b == 0))
		{
			return 0;
		}
		else if (((a > 1) || (a < 0)) || ((b > 1) || (b < 0)))
		{
			cout << "Переменная(-ые) не равна true (1) или false (0)";
			return -1;
		}
		else
		{
			return 1;
		}
	}
	//Дизъюнкция, логическое сложение, "ИЛИ", ||.
	int NOT(int a) {
		if (a == 1)
		{
			return 0;
		}
		else if (a == 0)
		{
			return 1;
		}
		else
		{
			cout << "Переменная не равна true (1) или false (0)";
			return -1;
		}
	}
	//Инверсия, "НЕ", !.
	int logical_progression(int a, int b) {
		if ((a == 1) && (b == 0))
		{
			return 0;
		}
		else if (((a > 1) || (a < 0)) || ((b > 1) || (b < 0)))
		{
			cout << "Переменная(-ые) не равна true (1) или false (0)";
			return -1;
		}
		else
		{
			return 1;
		}
	}
	//Импликация, логическое следование. (Если первый true, а второй false, то 0.
	int logical_equality(int a, int b) {
		if (a == b)
		{
			return 1;
		}
		else if (((a > 1) || (a < 0)) || ((b > 1) || (b < 0)))
		{
			cout << "Переменная(-ые) не равна true (1) или false (0)";
			return -1;
		}
		else
		{
			return 0;
		}
	}
	//Эквиваленция, логическое равенство, а также исключающее ИЛИ.

} boole;

int main()
{
	setlocale(LC_ALL, "ru");

	double a = 0, b = 0;

	cout << "______________________\nТрадиционный способ с использованием препроцессора." << endl;

	BOOLEAN A = TRUE; //Использование препроцессора.

	if (!A)
	{
		cout << " Результат: " << FALSE << endl;
	}
	else
	{
		cout << " Результат: " << TRUE << endl;
	}

	cout << "\n\n______________________\nANSI C и С++ c использованием перечислимых типов." << endl;

	BOOLEAN B = False; //Перечисляемый тип

	if (!B)
	{
		cout << " Результат: " << False << endl;
	}
	else
	{
		cout << " Результат: " << True << endl;
	}

	cout << "\n\n______________________\nКак класс в C++." << endl;

	int C = boole.TRue; //Класс

	if (!C)
	{
		cout << " Результат: " << boole.FAlse << endl;
	}
	else
	{
		cout << " Результат: " << boole.TRue << endl;;
	}

	cout << "\n\n______________________\nРавно, ==. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.EQUALS(a, b) << endl;

	cout << "\n\n______________________\nНеравно, !=. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.UNEQUAL(a, b) << endl;

	cout << "\n\n______________________\nБольше для любых чисел. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.MORE(a, b) << endl;

	cout << "\n\n______________________\nБольше или равно для любых чисел. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.MORE_OR_EQUAL(a, b) << endl;

	cout << "\n\n______________________\nМеньше для любых чисел. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.LESS(a, b) << endl;

	cout << "\n\n______________________\nМеньше или равно для любых чисел. Введите два числа!" << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.LESS_OR_EQUAL(a, b) << endl;

	cout << "\n\n______________________\nКонъюнкция, логическое умножение, \"И\", &&. Введите два числа 1 или 0 (True/False)!\n";
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.AND(a, b) << endl;

	cout << "\n\n______________________\nДизъюнкция, логическое сложение, \"ИЛИ\", ||. Введите два числа 1 или 0 (True/False)!\n";
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.OR(a, b) << endl;

	cout << "\n\n______________________\nИнверсия, \"НЕ\", !. \nВведите число 1 или 0 (True/False): ";
	cin >> a;
	cout << " Результат: " << boole.NOT(a) << endl;

	cout << "\n\n______________________\nИмпликация, логическое следование. (Если первый true, а второй false, то 0)." << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.logical_progression(a, b) << endl;

	cout << "\n\n______________________\nЭквиваленция, логическое равенство, а также исключающее ИЛИ." << endl;
	cout << "Введите A: ";
	cin >> a;
	cout << "Введите B: ";
	cin >> b;
	cout << " Результат: " << boole.logical_equality(a, b) << endl;

	_getch();
	return 0;
}