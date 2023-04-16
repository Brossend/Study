#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int i = 0, k = 0, j = 0, i2 = 0;
	char seq[]{ 'd','o','g',',','c','a','t',',','m','o','u','s','e',',','n','u','t','s',',','n','u','t','s',',','m','i','l','k',',','c','a','t',',','c','a','t','.','\0'};
	char seq1[5]{}, seq2[5]{}, seq3[5]{};

	cout << "Текст в начале: " << seq << endl;

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
									for (int c = 0; c < 5; c++)
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
					for (int c = 0; c < 5; c++)
					{
						seq2[c] = '\0';
					}
				}
			}
			for (int c = 0; c < 5; c++)
			{
				seq1[c] = '\0';
			}
			k = 0;
			i = i2;
		}
	}

	cout << "\nТекст в конце: " << seq << endl;
	


	_getch();
	return 0;
}