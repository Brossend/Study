#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <fstream>

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

	string c, d, file1, file2;
	int i = 0, col_oper = 0, cc = 0;
	char seq1[256]{}, ymi[256]{}, p;

	cout << "Типы ТР.\nВведите имя файла, в котором хранятся данные \"Имя.txt\": ";
	cin >> file1;

	fstream fin;

	fin.open(file1);

	if (!fin.is_open())
	{
		cout << "Файл не открыт!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;

		while (true)
		{
			fin >> types[i].name;
			fin >> types[i].type;
			fin >> d;
			strcpy_s(types[i].operations, d.c_str()); // Операции
			fin >> c; //Продолжение ввода

			if ((c == "стоп") || (c == "Стоп"))
			{
				break;
			}

			i++;
		}

		fin.close();

		cout << "Работа с файлом завершена!" << endl;
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

	fstream fout;

	cout << "\nВведите имя файла, в который записываются данные \"Имя.txt\": ";
	cin >> file2;

	fout.open(file2);

	if (!fout.is_open())
	{
		cout << "Файл не открыт!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;

		fout << ymi << "\nВсего " << col_oper << " операций!\n\n___________________________________________\n\n\nСписики операций для типов.";

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

			fout << "Типы для операции \"" << oper << "\"!" << endl;

			q = 0, u = 0;

			for (int l = 0; u <= i; u++)
			{
				while (types[u].operations[q] != '\0')
				{
					if ((types[u].operations[q] == 44) || (types[u].operations[q] == 46))
					{
						if (strcmp(oper, tip) == 0)
						{
							fout << "Тип: " << types[u].type << endl;

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

			fout << "\n\n";

			for (int c = 0; c < 256; c++)
			{
				oper[c] = '\0';
			}
		}

		fout << "___________________________________________" << endl;

		fout.close();

		cout << "Работа с файлом завершена!" << endl;
	}



	_getch();
	return 0;
}