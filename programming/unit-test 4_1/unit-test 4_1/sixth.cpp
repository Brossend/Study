#include "sixth.h"
#include <iostream>

using namespace std;

bool sixth::ex6_1(int SIZE, float seq[])
{
	bool TF = false;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (seq[j] > seq[i])
			{
				TF = true;
				break;
			}
			else if (seq[j] == seq[i + 1])
			{
				TF = true;
				break;
			}
		}
	}

	return TF;
}

void sixth::metod()
{
	cout << "\n������ �������!\n\"���� 10 ������������ �����. ����������, �������� �� ��� ������������ ������������������.\"\n\n������� ���������� ������������ ����� 1-� ������������������: ";
	cin >> SIZE1;

	float* seq = new float[SIZE1];

	if (SIZE1 > 1) // �������� �� ���������� ����� � ������������������. 1 ����� - �� ������������������
	{

		for (int i = 0; i < SIZE1; i++)
		{
			cout << "������� " << i + 1 << "-e ����������oe ����o 1-� ������������������: ";
			cin >> seq[i];
		}
		if (ex6_1(SIZE1, seq) == false)
		{
			cout << "\n1-� ������������������ ������������!" << endl;
		}
		else
		{
			cout << "\n1-� ������������������ �� ������������!" << endl;
		}
	}
	else
	{
		cout << "\n�� ����� 1 �����! ��� �� ������������������!" << endl;
	}

	cout << "\n������� ���������� ������������ ����� 2-� ������������������: ";
	cin >> SIZE2;

	float* seq2 = new float[SIZE2];

	if (SIZE2 > 1) // �������� �� ���������� ����� � ������������������. 1 ����� - �� ������������������
	{
		for (int i = 0; i < SIZE2; i++)
		{
			cout << "������� " << i + 1 << "-e ����������oe ����o 2-� ������������������: ";
			cin >> seq2[i];
		}
		if (ex6_1(SIZE2, seq2) == false)
		{
			cout << "\n2-� ������������������ ������������!" << endl;
		}
		else
		{
			cout << "\n2-� ������������������ �� ������������!" << endl;
		}
	}
	else
	{
		cout << "\n�� ����� 1 �����! ��� �� ������������������!" << endl;
	}

	cout << "\n����� ���������, ������� ���-������ ��� ����������!" << endl;

	delete[] seq;
}