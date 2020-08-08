#include "ColorType.h"

//TODO: —игнатура +
void PrintColor(ColorType &color)
{
	switch (color)
	{
		//TODO: RSDN +
	case Red:      cout << " расный цвет";   break;
	case Orange:   cout << "ќранжевый цвет"; break;
	case Yellow:   cout << "∆елтый цвет";    break;
	case Green:    cout << "«еленый цвет";   break;
	case Blue:     cout << "√олубой цвет";   break;
	case DarkBlue: cout << "—иний цвет";     break;
	case Purple:   cout << "ѕурпурный цвет"; break;
	}
}

ColorType ReadColor()
{
	int numColor;
	cout << "¬ведите число от 0 до 6 (0 Ц красный, 1 Ц оранжевый,";
	cout << "\n2 Ц желтый, 3 Цзеленый, 4 Ц голубой, 5 Ц синий, 6 Ц фиолетовый): ";
	cin >> numColor;
	cout << endl;
	//TODO: Ќе обработан случай ввода отрицательного значени€ и больше 6
	switch (numColor)
	{
		//TODO: RSDN +
	case 0: return Red;
	case 1: return Orange;
	case 2: return Yellow;
	case 3: return Green;
	case 4: return Blue;
	case 5: return DarkBlue;
	case 6: return Purple;
	}
}

//TODO: —игнатура +
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

//TODO: —игнатура +
int CountColor(ColorType* colors, const int colorsCount, ColorType &findedColor)
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