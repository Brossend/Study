#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

int cho_necho1(int seq[4][4], int* ch, int* nch);
int cho_necho2(int seq[6][6], int* ch, int* nch);

int switch_zero1(int seq[4][4]);
int switch_zero2(int seq[6][6]);

int main()
{
    setlocale(LC_ALL, "ru");

    int const LI_COL1 = 4, LI_COL2 = 6;
    int seq[LI_COL1][LI_COL1], seq1[LI_COL2][LI_COL2], ch = 0, nch = 0;

    string file1 = "seq.txt";
    string file2 = "seq1.txt";

    ifstream fin;

    fin.open(file1);

    if (!fin.is_open())
    {
        cout << "\nОшибка чтения файла! \"seq.txt\"/n" << endl;
    }
    else
    {
        cout << "\n________________________________________\n\nФайл \"seq.txt\" открыт!\n" << endl;

        for (int i = 0; i < LI_COL1; i++)
        {
            for (int j = 0; j < LI_COL1; j++)
            {
                fin >> seq[i][j];
            }
        }

        for (int i = 0; i < LI_COL2; i++)
        {
            for (int j = 0; j < LI_COL2; j++)
            {
                fin >> seq1[i][j];
            }
        }

        fin.close();

        cout << "Работа с файлом \"seq.txt\" завершена!\n________________________________________\n" << endl;
    }

    ofstream fout;

    fout.open(file2);

    if (!fout.is_open())
    {
        cout << "Ошибка чтения файла \"seq1.txt\"!\n" << endl;
    }
    else
    {
        cout << "Файл \"seq1.txt\" открыт!\n" << endl;

        fout << "________________________________________\n" << endl;

        for (int i = 0; i < LI_COL1; i++) // Вывод первой матрицы
        {
            for (int j = 0; j < LI_COL1; j++)
            {
                fout << seq[i][j] << " ";
            }
            fout << "\n";
        }

        cho_necho1(seq, &ch, &nch); // Функция счета четных и нечетных для 1 матрицы

        fout << "\nКол-во четных чисел первой матрицы: " << ch << "\nКол-во нечетных чисел первой матрицы: " << nch << endl;

        fout << "________________________________________\n" << endl;

        for (int i = 0; i < LI_COL2; i++) // Вывод второй матрицы
        {
            for (int j = 0; j < LI_COL2; j++)
            {
                fout << seq1[i][j] << " ";
            }
            fout << "\n";
        }

        cho_necho2(seq1, &ch, &nch); // Функция счета четных и нечетных для 2 матрицы

        fout << "\nКол-во четных чисел первой матрицы: " << ch << "\nКол-во нечетных чисел первой матрицы: " << nch << endl;

        switch_zero1(seq); // Обнуление четных элементов для 1 матрицы
        switch_zero2(seq1); // Обнуление четных элементов для 2 матрицы


        fout << "________________________________________\n" << endl;

        for (int i = 0; i < LI_COL1; i++) // Вывод первой обновленной матрицы
        {
            for (int j = 0; j < LI_COL1; j++)
            {
                fout << seq[i][j] << " ";
            }
            fout << "\n";
        }

        cho_necho1(seq, &ch, &nch); // Функция счета четных и нечетных для 1 обновленной матрицы

        fout << "\nКол-во четных чисел второй матрицы (0 - четное): " << ch << "\nКол-во нечетных чисел второй матрицы: " << nch << "\n________________________________________\n" << endl;

        for (int i = 0; i < LI_COL2; i++) // Вывод второй обновленной матрицы
        {
            for (int j = 0; j < LI_COL2; j++)
            {
                fout << seq1[i][j] << " ";
            }
            fout << "\n";
        }

        cho_necho2(seq1, &ch, &nch); // Функция счета четных и нечетных для 2 обновленной матрицы

        fout << "\nКол-во четных чисел второй матрицы (0 - четное): " << ch << "\nКол-во нечетных чисел второй матрицы: " << nch << "\n________________________________________\n" << endl;

        fout.close();

        cout << "Работа с файлом \"seq1.txt\" завершена!\n________________________________________\n" << endl;
    }

    _getch();
    return(0);
}

int cho_necho1(int seq[4][4], int* ch, int* nch)
{
    *ch = 0;
    *nch = 0;
    for (int i = 0; i < 4; i++) // Счет четных и нечетных 1 матрица
    {
        for (int j = 0; j < 4; j++)
        {
            if ((seq[i][j] % 2) == 0)
            {
                *ch += 1;
            }
            else
            {
                *nch += 1;
            }
        }
    }
    return 0;
}

int cho_necho2(int seq[6][6], int* ch, int* nch)
{
    *ch = 0;
    *nch = 0;
    for (int i = 0; i < 6; i++) // Счет четных и нечетных 2 матрица
    {
        for (int j = 0; j < 6; j++)
        {
            if ((seq[i][j] % 2) == 0)
            {
                *ch += 1;
            }
            else
            {
                *nch += 1;
            }
        }
    }
    return 0;
}

int switch_zero1(int seq[4][4])
{
    for (int i = 0; i < 4; i++) // Обнуление четных элементов 1 матрица
    {
        for (int j = 0; j < 4; j++)
        {
            if (((i % 2) == true) && ((j % 2) == true))
            {
                seq[i][j] = 0;
            }
        }
    }
    return 0;
}

int switch_zero2(int seq[6][6])
{
    for (int i = 0; i < 6; i++) // Обнуление четных элементов 2 матрица
    {
        for (int j = 0; j < 6; j++)
        {
            if (((i % 2) == true) && ((j % 2) == true))
            {
                seq[i][j] = 0;
            }
        }
    }
    return 0;
}
