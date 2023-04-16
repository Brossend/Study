#pragma once
class var
{
	const int SIZE = 10;
	float* seq = new float[SIZE] { 1.56, 2.4, 3.67, 4.34, 5.3536, 6.9, 7.33, 8.123, 9.35367, 10.6 };
	bool TF = false;
public:
	int Get_TF();
	void check();
	void print();
	~var();
};

