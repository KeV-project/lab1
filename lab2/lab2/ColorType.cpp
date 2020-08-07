#include "ColorType.h"

void PrintColor(ColorType color)
{
	switch (color)
	{
	case Red:
		cout << "Красный цвет" << endl;
		break;
	case Orange:
		cout << "Оранжевый цвет" << endl;
		break;
	case Yellow:
		cout << "Желтый цвет" << endl;
		break;
	case Green:
		cout << "Зеленый цвет" << endl;
		break;
	case Blue:
		cout << "Голубой цвет" << endl;
		break;
	case DarkBlue:
		cout << "Синий цвет" << endl;
		break;
	case Purple:
		cout << "Пурпурный цвет" << endl;
		break;
	}
}