#include "que.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

que::~que()
{
    delete[] temp;
}

int que::queque()
{
    while (true)
    {
        cout << "Число " << i + 1 << ": " << temp[i];
        cout << "\n";

        if (temp[i] >= 0)
        {
            multiply *= temp[i];
            i++;
        }
        else
        {
            result = pow(multiply, pow(i, -1));
            break;
        }
    }

    return 0;
}

float que::Get_result()
{
    return result;
}

void que::print()
{
    cout << "Среднее геометрическое: " << result << endl;
}

