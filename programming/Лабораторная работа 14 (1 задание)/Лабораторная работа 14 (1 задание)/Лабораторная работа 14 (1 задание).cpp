#include <iostream>
#include <conio.h>
#include <queue>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	queue <int> line, line_sq;

	int num, u;

	cout << "Введите количество элементов в очереди: ";
	cin >> num;

	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "Введите " << i + 1 << " элемент в очередь: ";
		cin >> u;

		line.push(u);
	}

	cout << "\nИсходная очередь: ";

	for (int i = 0; i < num; i++)
	{
		cout << line.front() << " ";

		u = line.front();

		if (((i + 1) % 2) == 0)
		{
			u = u * u;
			line_sq.push(u);
		}
		else
		{
			line_sq.push(u);
		}

		line.pop();
	}

	cout << "\nРезультативная очередь: ";

	for (int i = 0; i < num; i++)
	{
		cout << line_sq.front() << " ";

		line_sq.pop();
	}

	_getch();
	return 0;
}