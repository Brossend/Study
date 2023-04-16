#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

class computer
{
public:
	string name_computer;

	computer()
	{
		cout << "Создался класс \"computer\"!" << endl;
	}
	~computer()
	{
		cout << "Имя компьютера: " << name_computer << "\t\t\t\t\t\t\tКласс \"computer\" удален!" << endl;
	}
};

class peripheral_device : public computer
{
public:
	string name_peripheral_device;

	peripheral_device()
	{
		cout << "Создался класс \"peripheral_device\"!" << endl;
	}
	~peripheral_device()
	{
		cout << "Имя периферийного устройства: " << name_peripheral_device << "\t\t\tКласс \"peripheral_device\" удален!" << endl;
	}
};

class keyboard : public peripheral_device
{
public:
	string name_keyboard;

	keyboard()
	{
		cout << "Создался класс \"keyboard\"!" << endl;
	}
	~keyboard()
	{
		cout << "Имя клавиатуры: " << name_keyboard << "\t\t\tКласс \"keyboard\" удален!" << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "ru"); //'system("chcp 1251");' Для русского в файле.

	keyboard PC;

	string file;

	fstream fin;

	while (true)
	{
		cout << "\nВведите название файла: ";
		cin >> file;

		fin.open(file);

		if (!fin.is_open())
		{
			cout << "Файл не открыт! Попробуйте ввести название заново!" << endl;
		}
		else
		{
			cout << "Файл открыт!" << endl;

			fin >> PC.name_computer;
			fin >> PC.name_peripheral_device;
			fin >> PC.name_keyboard;

			fin.close();

			cout << "Работа с файлом завершена!\n" << endl;

			break;
		}
	}

	_getch();
	return 0;
}