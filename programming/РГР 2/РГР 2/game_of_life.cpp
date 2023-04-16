#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "game_of_life.h"
#include "Sys.h"

using namespace std;

int game_of_life::rule(int i, int j)
{
    int alive = 0;

    for (int l = i - 1; l < i + 2; l++)
    {
        for (int n = j - 1; n < j + 2; n++)
        {
            alive = alive + field[l][n];
        }
    }

    alive = alive - field[i][j];

    if ((alive == 3) && (field[i][j] == 0))
    {
        field[i][j] = 1;
    }
    if (((alive < 2) || (alive > 3)) && (field[i][j] == 1))
    {
        field[i][j] = 0;
    }

    return alive;
}

void game_of_life::print_field()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            XY(55 + i, 10 + j);

            if (field[i][j] == 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void game_of_life::generate()
{
    srand(time(NULL));

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            field[i][j] = rand() % 2;
        }
    }
}

void game_of_life::start_game()
{
    XY(54, 7);
    cout << "Игра \"Жизнь\"";
    XY(80, 7);
    cout << "Обратите внимание!";
    XY(80, 9);
    cout << "Как только колония прекратит изменяться,";
    XY(80, 10);
    cout << "значит игра завершена!";
    XY(80, 12);
    cout << "Для выхода нажмите SPACEBAR \"Пробел\"";


    generate();
    print_field();
    Sleep(1000);
    system("cls");

    while (true)
    {
        XY(54, 7);
        cout << "Игра \"Жизнь\"";
        XY(80, 7);
        cout << "Обратите внимание!";
        XY(80, 9);
        cout << "Как только колония прекратит изменяться,";
        XY(80, 10);
        cout << "значит игра завершена!";
        XY(80, 12);
        cout << "Для выхода нажмите SPACEBAR \"Пробел\"";

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                rule(i, j);
            }
        }

        print_field();
        Sleep(150);
        system("cls");

        if (GetAsyncKeyState(VK_SPACE))
        {
            break;
        }
    }
}

game_of_life::game_of_life()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            field[i][j] = 0;
        }
    }
}