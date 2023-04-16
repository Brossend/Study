#include "Example.h"
#include <math.h>
#include <iostream>

using namespace std;

Example::Example(float t)
{
    this->t = t;
}

float Example::Get_Z()
{
    return z;
}

void Example::check()
{
    if (t < a)
    {
        z = a * pow(t, 2.0) - (b * sqrt(t + 1.0));
    }
    else if (t > b)
    {
        z = a * cbrt(49) - cbrt(t + 1); // 7 в степени 2/3 это все равно что и 49 в кубическом корне.
    }
    else
    {
        z = a - b;
    }

    cout << "\nОтвет: " << z << endl;
}