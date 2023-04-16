#include "first.h"
#include <math.h>
#define a 1.5
#define b -1.2

float first::ex1_x1()
{
	return exp(-a * x1) * cbrt(a * x1 + b * sin(2 * x1));
}

float first::ex1_x2()
{
	return exp(-a * x2) * cbrt(a * x2 + b * sin(2 * x2));
}

int first::Set_x1(int x1)
{
	this->x1 = x1;
	return 0;
}

int first::Set_x2(int x2)
{
	this->x2 = x2;
	return 0;
}