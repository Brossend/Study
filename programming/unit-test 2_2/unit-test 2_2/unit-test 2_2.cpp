#include <iostream>
#include <conio.h>
#include <math.h>
#include "que.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    que A;

    A.queque();

    A.print();

    _getch();
    return(0);
}