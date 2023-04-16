#pragma once
class que
{
	int* temp = new int[] { 2, 4, 8, -1 }, i = 0, multiply = 1;
	float result = 0;
public:
	~que();
	int queque();
	float Get_result();
	void print();
};