#include "while_do.h"
#include <iostream>
#include <math.h>

using namespace std;

while_do::while_do(float a)
{
    this->a = a;
}

float while_do::Get_Z1()
{
    return Z1;
}

float while_do::Get_Z2()
{
    return Z2;
}

int while_do::whilef()
{
    X = a / 2;

    cout << "\nРезультат функции a(x-a)^3/2 в промежутке (1 <= X <= 2.5) с шагом " << X << ": ";

    do
    {
        Z1 = a * sqrt(pow((x - a), 3));

        cout << Z1 << "; ";

        x += X;
    } while (1 <= x && x <= 2.5);

    cout << "\n\nРезультат функции a/2(e^x/a +e^-x/a) в промежутке (2.5 < X <= 4) c шагом " << X << ": ";

    x = 2.5 + X;

    do
    {
        Z2 = (a / 2) * (exp(x / a) + exp(-x / a));

        cout << Z2 << "; ";

        x += X;
    } while (2.5 < x && x <= 4);

    return 0;
}