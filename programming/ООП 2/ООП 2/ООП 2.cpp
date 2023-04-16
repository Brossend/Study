#include <iostream>
#include <conio.h>
#include <math.h>
#define PI 3.1415926535

using namespace std;

class cyl
{
	double radial;
	double height;
	double volume = 0;
	double full_volume = 0;

	double Volume()
	{
		volume = PI * pow(radial, 2) * height;

		return 0;
	}

	double Full_volume()
	{
		full_volume = 2 * PI * radial * (height + radial);

		return 0;
	}

public:
	cyl(double r, double h)
	{
		radial = r;
		height = h;

		cout << "Данные цилиндра введны! Вычислен цилиндр по введенным данным!\n" << endl;
	}
	cyl()
	{
		radial = 5;
		height = 9;

		cout << "Данные не введены! Вычислен цилиндр с высотой 9 и радиусом 5!\n" << endl;
	}
	~cyl()
	{
		cout << "\nУдаление..." << endl;
	}
	void print_result()
	{
		Volume();
		Full_volume();

		cout << "Введенные данные.\nРадиус: " << radial << "\nВысота: " << height
			<< "\n---------------------------------\nПлощадь полной поверхности цилиндра: "
			<< full_volume << "\nОбъем цилиндра: " << volume << "\n---------------------------------\n" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	double r, h;

	cout << "Введите радиус цилиндра: ";
	cin >> r;
	cout << "Введите высоту цилиндра: ";
	cin >> h;

	cout << "\n---------------------------------" << endl;

	cyl test1(r, h);
	test1.print_result(); //Цилиндр с данными

	cyl test2;
	test2.print_result(); //Цилиндр  без введенных данных!

	_getch();
	return 0;
}