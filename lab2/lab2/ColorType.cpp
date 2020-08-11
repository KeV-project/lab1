#include "ColorType.h"

void PrintColor(const ColorType& color)
{
	switch (color)
	{
		//TODO: RSDN - ¬сегда дл€ Switch-case использовать правила длинной последовательности + ставить скобочки дл€ case-ов +
	case Red:
	{
		cout << "красный";
		break;
	}	
	case Orange:   
	{
		cout << "оранжевый"; 
		break;
	}
	case Yellow:
	{
		cout << "желтый";
		break;
	}
	case Green:
	{
		cout << "зеленый";
		break;
	}
	case Blue:
	{
		cout << "голубой";
		break;
	}
	case DarkBlue:
	{
		cout << "синий";     
		break;
	}
	case Purple:
	{
		cout << "фиолетовый";
		break;
	}
	}
}

ColorType GetColorType(const int numColor)
{
	if (!IsValueInRange(numColor, 0, 6))
	{
		throw exception("„исло не входит в допустимый диапазон");
	}
	switch (numColor)
	{
		//TODO: RSDN - ¬сегда дл€ Switch-case использовать правила длинной последовательности + ставить скобочки дл€ case-ов +
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