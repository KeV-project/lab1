#include "ColorType.h"

//TODO: Сигнатура +
void PrintColor(const ColorType &color)
{
	switch (color)
	{
		//TODO: RSDN +
	case Red:      cout << "красный";   break;
	case Orange:   cout << "оранжевый"; break;
	case Yellow:   cout << "желтый";    break;
	case Green:    cout << "зеленый";   break;
	case Blue:     cout << "голубой";   break;
	case DarkBlue: cout << "синий";     break;
	case Purple:   cout << "фиолетовый"; break;
	}
}

ColorType ReadColor(const int numColor)
{
	
	//TODO: Не обработан случай ввода отрицательного значения и больше 6 +
	if (!IsValueInRange(numColor, 0, 6))
	{
		throw exception("Число не входит в допустимый диапазон");
	}
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

//TODO: Сигнатура +
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

//TODO: Сигнатура +
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