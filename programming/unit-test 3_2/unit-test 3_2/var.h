#pragma once
class var
{
	const int SIZE = 20;
	int N = 0;
	float X = 0, y = 0, * seq = new float[SIZE], * seq1 = new float[SIZE], * seq2 = new float[SIZE];
public:
	float Get_seq(int i);
	float Get_seq1(int i);
	float Get_seq2(int i);
	var(int N);
	~var();
	void metod();
};

