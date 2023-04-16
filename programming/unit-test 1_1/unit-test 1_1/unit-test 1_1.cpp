#include <iostream>
#include <conio.h>
#include <math.h>
#include "Example.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    float t;

    while (true)
    {
        cout << "\nВведите t: ";
        cin >> t;

        if ((t >= 0.5) && (t <= 3))
        {
            Example A1(t);

            A1.check();

            break;
        }
        else
        {
            cout << "\nВведите t еще раз!" << endl;
        }
    }

    _getch();
    return 0;
}