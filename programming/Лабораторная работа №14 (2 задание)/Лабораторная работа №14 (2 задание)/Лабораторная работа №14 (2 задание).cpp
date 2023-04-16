//Удалить из стека все отрицательные элементы.

#include <iostream>
#include <conio.h>
#include <stack>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	stack <int> st_ck1, st_ck2;

	int num, u, n = 0;

	cout << "Введите сколько чисел в стеке: ";
	cin >> num;

	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент в stack: ";
		cin >> u;

		st_ck1.push(u);
	}

	cout << "\nИсходный stack: ";

	for (int i = 0; i < num; i++)
	{
		cout << st_ck1.top() << " ";

		u = st_ck1.top();

		if (u < 0)
		{
		}
		else
		{
			st_ck2.push(u);

			n++;
		}

		st_ck1.pop();
	}

	cout << "\n\nStack с результатом: ";

	for (int i = 0; i < n; i++)
	{
		cout << st_ck2.top() << " ";

		st_ck2.pop();
	}

	_getch();
	return 0;
}