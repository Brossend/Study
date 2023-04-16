#include <iostream>
#include <conio.h>
#include <string>
#include "example.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int a;

    cout << "Введите число, чтобы узнать остаток от деления на 5!\n<< ";
    cin >> a;

    example A1(a);

    A1.residue();

    A1.print();

    _getch();
    return 0;
}