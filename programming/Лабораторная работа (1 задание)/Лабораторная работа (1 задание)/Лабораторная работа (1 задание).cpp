#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

char lab10(char seq[])
{
	int i = 0, k = 0, j = 0, i2 = 0;
	char seq1[256]{}, seq2[256]{}, seq3[256]{};

	while (seq[i] != '\0')
	{
		seq1[k] = seq[i];
		i++;
		k++;

		if (seq[i] == 44)
		{
			i++;
			i2 = i;
			k = 0;
			j = i;
			while (seq[j] != '\0')
			{
				seq2[k] = seq[j];
				j++;
				k++;

				if ((seq[j] == 44) || (seq[j] == 46))
				{
					if (strcmp(seq1, seq2) == 0)
					{
						int p = 0, t = 0, u = 0;

						while (seq[t] != '\0')
						{
							seq3[p] = seq[t];
							p++;
							t++;

							if (seq[t] == 44)
							{
								if (strcmp(seq3, seq2) == 0)
								{
									int q = u;

									while (seq[q] != 44)
									{
										seq[q] = ' ';
										q++;
									}
									seq[q] = ' ';
									break;
								}
								else
								{
									t++;
									u = t;
									p = 0;
									for (int c = 0; c < 256; c++)
									{
										seq3[c] = '\0';
									}
								}
							}
						}
					}
					else
					{
						k = 0;
					}
					j++;
					for (int c = 0; c < 256; c++)
					{
						seq2[c] = '\0';
					}
				}
			}
			for (int c = 0; c < 256; c++)
			{
				seq1[c] = '\0';
			}
			k = 0;
			i = i2;
		}
	}

}

struct TP_types
{
	string name;
	string type;
	char operations[256];
} types[256];

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string c, d;
	int i = 0, col_oper = 0;
	char seq1[256]{}, ymi[256]{}, p;

	cout << "Типы ТР" << endl;

	while (true)
	{
		cout << "___________________________________________\n\n";

		cout << "Введите имя " << i + 1 << "-го типа: ";
		getline(cin, types[i].name);
		cout << "Введите тип: ";
		getline(cin, types[i].type);
		cout << "Введите операции (или операцию), разрешенные(-ую) в данном типе (Через запятую, БЕЗ пробелов и с точкой в конце!): ";
		getline(cin, d);
		strcpy_s(types[i].operations, d.c_str());

		cout << "___________________________________________";

		cout << "\n\nХотите продолжить ввод? Нажмите ENTER. Если нет, то напишите \"Стоп\": ";
		getline(cin, c);

		if ((c == "стоп") || (c == "Стоп"))
		{
			cout << "___________________________________________\n\n\n";
			break;
		}

		i++;
	}

	int k = 0, u = 0;

	for (int l = 0; l <= i; l++)
	{
		while (true)
		{
			p = types[l].operations[k];

			if (p == 46)
			{
				seq1[u] = ',';
				u++;
				k = 0;
				break;
			}
			else
			{
				seq1[u] = p;
				k++;
				u++;
			}
		}
		if (l == i)
		{
			seq1[u - 1] = '.';
		}
	}

	lab10(seq1);

	int r = 0, q = 0;

	while (seq1[r] != '\0')
	{
		if (seq1[r] == 32)
		{
			r++;
		}
		else
		{
			ymi[q] = seq1[r];

			if ((ymi[q] == 44) || (ymi[q] == 46))
			{
				col_oper += 1;
			}

			q++;
			r++;
		}
	}

	cout << ymi << "\nВсего " << col_oper << " операций!\n\n___________________________________________\n\n\nСписики операций для типов.";

	r = 0, k = 0;

	char oper[256]{}, tip[256]{};

	while (ymi[r] != '\0')
	{
		while (true)
		{
			oper[k] = ymi[r];
			k++;
			r++;
			if ((ymi[r] == 44) || (ymi[r] == 46))
			{
				k = 0;
				r++;
				break;
			}
		}

		cout << "Типы для операции \"" << oper << "\"!" << endl;

		q = 0, u = 0;

		for (int l = 0; u <= i; u++)
		{
			while (types[u].operations[q] != '\0')
			{
				if ((types[u].operations[q] == 44) || (types[u].operations[q] == 46))
				{
					if (strcmp(oper, tip) == 0)
					{
						cout << "Тип: " << types[u].type << endl;

						for (int c = 0; c < 256; c++)
						{
							tip[c] = '\0';
						}
						q = 0;
						l = 0;
						break;
					}
					else
					{
						for (int c = 0; c < 256; c++)
						{
							tip[c] = '\0';
						}
						l = 0;
						q++;
					}
				}
				else
				{
					tip[l] = types[u].operations[q];
					q++;
					l++;
				}
			}
			q = 0;
		}

		cout << "\n\n";

		for (int c = 0; c < 256; c++)
		{
			oper[c] = '\0';
		}
	}

	cout << "___________________________________________" << endl;

	_getch();
	return 0;
}