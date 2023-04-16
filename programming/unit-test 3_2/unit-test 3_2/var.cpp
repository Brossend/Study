#include "var.h"
#include <iostream>
#define a 0
#define PI 3.1415926535
#define b 2*PI

float var::Get_seq(int i)
{
	return seq[i];
}

float var::Get_seq1(int i)
{
	return seq1[i];
}

float var::Get_seq2(int i)
{
	return seq2[i];
}

var::var(int N)
{
	this->N = N;
}

var::~var()
{
	delete[]seq, seq1, seq2;
}

void var::metod()
{
	X = b / N;

	printf(" _________ _________ _________ \n|         |         |         |\n|    X    |   F1!   |   F2!   |\n|_________|_________|_________|\n");

	for (int i = 0; y <= b; y += X, i++)
	{
		seq[i] = y;
		seq1[i] = 5 - 3 * cos(y);
		seq2[i] = sqrt(1 + pow(sin(y), 2));

		printf("|         |         |         |\n|%9.7f|%9.7f|%9.7f|\n|_________|_________|_________|\n", seq[i], seq1[i], seq2[i]);
	}
}
