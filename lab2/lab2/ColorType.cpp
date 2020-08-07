#include "ColorType.h"

void PrintColor(ColorType color)
{
	switch (color)
	{
	case Red:
		cout << "������� ����" << endl;
		break;
	case Orange:
		cout << "��������� ����" << endl;
		break;
	case Yellow:
		cout << "������ ����" << endl;
		break;
	case Green:
		cout << "������� ����" << endl;
		break;
	case Blue:
		cout << "������� ����" << endl;
		break;
	case DarkBlue:
		cout << "����� ����" << endl;
		break;
	case Purple:
		cout << "��������� ����" << endl;
		break;
	}
}

ColorType ReadColor()
{
	int numColor;
	cout << "������� ����� �� 0 �� 6 (0 � �������, 1 � ���������,";
	cout << "\n2 � ������, 3 ��������, 4 � �������, 5 � �����, 6 � ����������): ";
	cin >> numColor;
	cout << endl;
	switch (numColor)
	{
	case 0:
		return Red;
	case 1:
		return Orange;
	case 2:
		return Yellow;
	case 3:
		return Green;
	case 4:
		return Blue;
	case 5:
		return DarkBlue;
	case 6:
		return Purple;
	}
}

int CountRed(ColorType* colors, int colorsCount)
{
	int count = 0;
	for (int i = 0; i < colorsCount; i++)
	{
		if (colors[i] == Red)
		{
			count++;
		}
	}
	return count;
}