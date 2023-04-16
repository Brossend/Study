#include <iostream>
#include <conio.h>

using namespace std;

class Time
{
private:
	int hours;
	int minuts;
	int seconds;

	friend int time_build_up(int t, Time& value); //Дружественная функция
public:
	Time(int hours, int minuts, int seconds)
	{
		this->hours = hours;
		this->minuts = minuts;
		this->seconds = seconds;
	}
	void print_time()
	{
		cout << "Часы: " << hours << "\nМинуты: " << minuts << "\nСекунды: " << seconds << endl;
	}
};

int time_build_up(int t, Time& value) //Дружественная функция
{
	value.seconds = value.seconds + t;

	while (true)
	{
		if (value.seconds > 59)
		{
			value.minuts += 1;

			value.seconds = value.seconds - 60;

			if (value.minuts > 59)
			{
				value.hours += 1;
				value.minuts = 0;
			}
			if (value.hours > 23)
			{
				value.hours = 0;
			}
			if (value.seconds <= 0)
			{
				value.seconds *= -1;
				break;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Time C1(21, 53, 12);

	int t;

	cout << "Введите количество секунд, на которое хотите изменить время: ";
	cin >> t;

	time_build_up(t, C1);

	C1.print_time();

	_getch();
	return 0;
}