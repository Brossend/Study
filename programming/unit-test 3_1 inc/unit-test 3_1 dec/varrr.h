#pragma once
class varrr
{
	const int SIZE = 10;
	float* seq = new float[SIZE] { 1.56, 2.4, 3.67, 0, 5.3536, 6.9, 7.33, 8.123, 9.35367, 10.6 };
	bool TF = false;
public:
	~varrr();
	int Get_TF();
	void metod();
	void print();
};