#include "ColorType.h"

void PrintColor(ColorType color)
{
	switch (color)
	{
	case Red:
		cout << " расный цвет" << endl;
		break;
	case Orange:
		cout << "ќранжевый цвет" << endl;
		break;
	case Yellow:
		cout << "∆елтый цвет" << endl;
		break;
	case Green:
		cout << "«еленый цвет" << endl;
		break;
	case Blue:
		cout << "√олубой цвет" << endl;
		break;
	case DarkBlue:
		cout << "—иний цвет" << endl;
		break;
	case Purple:
		cout << "ѕурпурный цвет" << endl;
		break;
	}
}

ColorType ReadColor()
{
	int numColor;
	cout << "¬ведите число от 0 до 6 (0 Ц красный, 1 Ц оранжевый,";
	cout << "\n2 Ц желтый, 3 Цзеленый, 4 Ц голубой, 5 Ц синий, 6 Ц фиолетовый): ";
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