#include "ColorType.h"

void PrintColor(const ColorType& color)
{
	switch (color)
	{
		case Red:
		{
			cout << "�������";
			break;
		}	
		case Orange:   
		{
			cout << "���������"; 
			break;
		}
		case Yellow:
		{
			cout << "������";
			break;
		}
		case Green:
		{
			cout << "�������";
			break;
		}
		case Blue:
		{
			cout << "�������";
			break;
		}
		case DarkBlue:
		{
			cout << "�����";     
			break;
		}
		case Purple:
		{
			cout << "����������";
			break;
		}
	}
}

ColorType GetColorType(const int numColor)
{
	//TODO: ����������� �� ���������� ����� �� ��������� +
	if (!IsValueInRange(numColor, 0, 6))
	{
		string message = "����� " + to_string(numColor) + 
			" �� ������ � ���������� �������� [0, 6] "
			"� �� ����� ���� ������������ � ��������������� "
			"��������� ������������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	switch (numColor)
	{
		case 0: 
		{
			return Red;
		}
		case 1: 
		{
			return Orange;
		}
		case 2: 
		{
			return Yellow;
		}
		case 3: 
		{
			return Green;
		}
		case 4: 
		{
			return Blue;
		}
		case 5: 
		{
			return DarkBlue;
		}
		case 6: 
		{
			return Purple;
		}
	}
}

int CountRed(ColorType* colors, const int colorsCount)
{
	int redCount = 0;
	for (int i = 0; i < colorsCount; i++)
	{
		if (colors[i] == Red)
		{
			redCount++;
		}
	}
	return redCount;
}

int CountColor(ColorType* colors, const int colorsCount,
	ColorType &findedColor)
{
	int colorCount = 0;
	for (int i = 0; i < colorsCount; i++)
	{
		if (colors[i] == findedColor)
		{
			colorCount++;
		}
	}
	return colorCount;
}