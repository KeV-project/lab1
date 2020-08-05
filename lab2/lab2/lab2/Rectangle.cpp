#include "Rectangle.h"

void ReadRectangle(Rectangle& rectangle)
{
	cout << "Введите длину прямоугольника(вещ. ч): ";
	cin >> rectangle.Length;
	cout << endl;
	cout << "Введите ширину прямоугольника(вещ. ч): ";
	cin >> rectangle.Width;
	cout << endl;
	cout << "Введите цвет прямоугольника: ";
	cin >> rectangle.Color;
	cout << endl;
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) + pow(rectangle.Width, 2));
	rectangle.Perimeter = (rectangle.Length + rectangle.Width) * 2;
	rectangle.Area = rectangle.Length * rectangle.Width;
}

void PrintRectangle(Rectangle& rectangle)
{
	cout << "Прямоугольник:" << endl;
	cout << "Длина: " << rectangle.Length << endl;
	cout << "Ширина: " << rectangle.Width << endl;
	cout << "Диагональ: " << rectangle.Diagonal << endl;
	cout << "Цвет: " << rectangle.Color << endl;
	cout << "Периметр: " << rectangle.Perimeter << endl;
	cout << "Площадь: " << rectangle.Area << endl << endl;
}

void DemoRectangle()
{
	// Task 2.2.3.1
	Rectangle FirstRectangle;
	FirstRectangle.Length = 13.5;
	FirstRectangle.Width = 7.3;
	FirstRectangle.Diagonal = 15.3;
	FirstRectangle.Color = "yellow";
	FirstRectangle.Perimeter = 41.6;
	FirstRectangle.Area = 98.55;

	// Task 2.2.3.2
	Rectangle secondRectangle;
	ReadRectangle(secondRectangle);
	PrintRectangle(secondRectangle);
	PrintLine();
}


