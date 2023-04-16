#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int processing(int B[5][5], int n, int k, int* A_S, int* A_C);

int main()
{
    setlocale(LC_ALL, "ru");

    int line1, line2, column1, column2, A[5][5]{ {1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5} }, B[5][5], A_NULL = 0, A_SUM = 0, B_NULL = 0, B_SUM = 0;

    cout << "\n\tМатрица 1B\n ___ ___ ___ ___ ___" << endl; // Вывод массива B

    for (int j = 0; j < 5; j++)
    {
        for (int l = 0; l < 5; l++)
        {
            printf("|%3d", A[j][l]);

        }
        cout << "|\n|___|___|___|___|___|" << endl;
    }

    for (int i = 0; i < 5; i++) // Копирование массива B в новый массив для работы с двумя наборами исходных данных (Массив ведь один - матрица B)
    {
        for (int j = 0; j < 5; j++)
        {
            B[i][j] = A[i][j];
        }
    }

    cout << "\nВведите номер строки ПЕРВОГО массива, которую хотите обнулить: ";
    cin >> line1;
    cout << "Введите номер столбца ПЕРВОГО массива, который хотите обнулить: ";
    cin >> column1;
    cout << "\nВведите номер строки ВТОРОГО массива, которую хотите обнулить: ";
    cin >> line2;
    cout << "Введите номер столбца ВТОРОГО массива, который хотите обнулить: ";
    cin >> column2;

    processing(A, line1, column1, &A_NULL, &A_SUM); // Вызов функции для матрицы 1C

    cout << "\n\tМатрица 1C\n ___ ___ ___ ___ ___" << endl; // Вывод матрицы 1C

    for (int j = 0; j < 5; j++)
    {
        for (int l = 0; l < 5; l++)
        {
            printf("|%3d", A[j][l]);

        }
        cout << "|\n|___|___|___|___|___|" << endl;
    }

    cout << "\n\nМатрица 1C. Количество нулей в строке или столбце: " << A_NULL << "\n\t    Сумма всех нулей: " << A_SUM << endl;

    processing(B, line2, column2, &B_NULL, &B_SUM); // Вызов функции для матрицы 2C

    cout << "\n\n\tМатрица 2C\n ___ ___ ___ ___ ___" << endl; // Вывод матрицы 2C

    for (int j = 0; j < 5; j++)
    {
        for (int l = 0; l < 5; l++)
        {
            printf("|%3d", B[j][l]);
        }
        cout << "|\n|___|___|___|___|___|" << endl;
    }

    cout << "\n\nМатрица 2C. Количество нулей в строке или столбце: " << B_NULL << "\n\t    Сумма всех нулей: " << B_SUM << endl;

    _getch();
    return(0);
}

int processing(int X[5][5], int line, int column, int* A_NULL, int* A_SUM) // Функция обработки матрицы
{
    for (int i = 0; i < 5; i++)
    {
        X[line - 1][i] = 0;
        X[i][column - 1] = 0;
        (*A_NULL)++;
    }

    *A_SUM = (*A_NULL) + (*A_NULL);

    return(0);
}