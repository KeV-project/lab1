#include "Rectangle.h"

Rectangle* MakeRectangle(float length, float width, string color)
{
	Rectangle* rectangle = new Rectangle();
	rectangle->Length = length;
	rectangle->Width = width;
	rectangle->Diagonal = sqrt(pow(length, 2) + pow(width, 2));
	rectangle->Color = color;
	rectangle->Perimeter = (length + width) * 2;
	rectangle->Area = length * width;
	return rectangle;
}

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
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) 
		+ pow(rectangle.Width, 2));
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

void ChangeFields(Rectangle* rectangle, float length,
	float width, string color)
{
	rectangle->Length = length;
	rectangle->Width = width;
	rectangle->Color = color;
	rectangle->Diagonal = sqrt(pow(rectangle->Length, 2) 
		+ pow(rectangle->Width, 2));
	rectangle->Perimeter = (rectangle->Length + rectangle->Width) * 2;
	rectangle->Area = rectangle->Length * rectangle->Width;
}

void DemoRectangle()
{
	// Task 2.2.3.1
	Rectangle firstRectangle;
	firstRectangle.Length = 13.5;
	firstRectangle.Width = 7.3;
	firstRectangle.Diagonal = 15.3;
	firstRectangle.Color = "yellow";
	firstRectangle.Perimeter = 41.6;
	firstRectangle.Area = 98.55;
	
	// Task 2.2.3.2
	Rectangle secondRectangle;
	cout << "ПРЯМОУГОЛЬНИК" << endl << endl;
	ReadRectangle(secondRectangle);
	PrintRectangle(secondRectangle);
	PrintLine();
	
	// Task 2.2.3.3
	const int rectanglesCount = 3;
	Rectangle** rectangles = new Rectangle * [rectanglesCount]
	{
		MakeRectangle(13.5, 10.0, "серый"),
		MakeRectangle(15.3, 7.2, "красный"),
		MakeRectangle(5.0, 3.5, "зеленый"),
	};
	cout << "Массив прямоугольников: " << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << ":" << endl << endl;
		PrintRectangle(*rectangles[i]);
	}
	PrintLine();
	for (int i = 0; i < rectanglesCount; i++)
	{
		delete rectangles[i];
	}
	delete[] rectangles;
	
	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Rectangle* pFirstRectangle = &firstRectangle;
	cout << "Прямоугольник firstRectangle: " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "Измененный прямоугольник firstRectangle: " << endl << endl;
	ChangeFields(pFirstRectangle, 111, 11, "коричневый");
	PrintRectangle(*pFirstRectangle);
	PrintLine();
	
	// Task 2.2.4.2
	Rectangle* pFirstRectangle2 = &firstRectangle;
	cout << "Адрес переменной firstRectangle: ";
	cout << &firstRectangle << endl << endl;
	cout << "Адрес в указателе pFirstRectangle: ";
	cout << pFirstRectangle << endl << endl;
	cout << "Адрес в указателе pFirstRectangle2: ";
	cout << pFirstRectangle2 << endl << endl;
	PrintLine();
}


