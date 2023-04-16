#include <iostream>
#include <math.h>
#include <conio.h>
#include "while_do.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    float a;

    while (true)
    {
        cout << "\nПо задаче A = 0.5, 1. Введите A: ";
        cin >> a;

        if (a == 0.5 || a == 1)
        {
            while_do A(a);
            A.whilef();
            break;
        }
        else
        {
            cout << "\nВведите А по условию задачи!" << endl;
        }
    }

    _getch();
    return(0);
}
