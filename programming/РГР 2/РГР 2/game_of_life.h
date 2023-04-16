#pragma once
#define fieldX 12
#define fieldY 12

const int a = fieldX - 2;
const int b = fieldY - 2;

class game_of_life
{

	int field[a][b], rule(int i, int j);
	void print_field(), generate();

public:
	game_of_life();

	void start_game();
};