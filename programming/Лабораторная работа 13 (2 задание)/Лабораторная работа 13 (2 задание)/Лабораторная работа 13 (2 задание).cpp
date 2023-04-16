#include <iostream>
#include <conio.h>
#include <ctime>
#include "cho_necho.h"
#include "switch_zero.h"
#define LI_COL1 4
#define LI_COL2 6

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    extern int seq[LI_COL1][LI_COL1], seq1[LI_COL2][LI_COL2], ch, nch;

    cout << "________________________________________\n" << endl;

    for (int i = 0; i < LI_COL1; i++) // Вывод первой матрицы
    {
        for (int j = 0; j < LI_COL1; j++)
        {
            printf("%d\t", seq[i][j]);
        }
        cout << "\n";
    }

    cho_necho1(seq, &ch, &nch); // Функция счета четных и нечетных для 1 матрицы

    cout << "\nКол-во четных чисел первой матрицы: " << ch << "\nКол-во нечетных чисел первой матрицы: " << nch << endl;

    cout << "________________________________________\n" << endl;

    for (int i = 0; i < LI_COL2; i++) // Вывод второй матрицы
    {
        for (int j = 0; j < LI_COL2; j++)
        {
            printf("%d\t", seq1[i][j]);
        }
        cout << "\n";
    }

    cho_necho2(seq1, &ch, &nch); // Функция счета четных и нечетных для 2 матрицы

    cout << "\nКол-во четных чисел первой матрицы: " << ch << "\nКол-во нечетных чисел первой матрицы: " << nch << endl;

    switch_zero1(seq); // Обнуление четных элементов для 1 матрицы
    switch_zero2(seq1); // Обнуление четных элементов для 2 матрицы


    cout << "________________________________________\n" << endl;

    for (int i = 0; i < LI_COL1; i++) // Вывод первой обновленной матрицы
    {
        for (int j = 0; j < LI_COL1; j++)
        {
            printf("%d\t", seq[i][j]);
        }
        cout << "\n";
    }

    cho_necho1(seq, &ch, &nch); // Функция счета четных и нечетных для 1 обновленной матрицы

    cout << "\nКол-во четных чисел второй матрицы (0 - четное): " << ch << "\nКол-во нечетных чисел второй матрицы: " << nch << "\n________________________________________\n" << endl;

    for (int i = 0; i < LI_COL2; i++) // Вывод второй обновленной матрицы
    {
        for (int j = 0; j < LI_COL2; j++)
        {
            printf("%d\t", seq1[i][j]);
        }
        cout << "\n";
    }

    cho_necho2(seq1, &ch, &nch); // Функция счета четных и нечетных для 2 обновленной матрицы

    cout << "\nКол-во четных чисел второй матрицы (0 - четное): " << ch << "\nКол-во нечетных чисел второй матрицы: " << nch << "\n________________________________________\n" << endl;

    _getch();
    return(0);
}