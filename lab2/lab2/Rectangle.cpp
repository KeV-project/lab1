#include "Rectangle.h"

Rectangle* MakeRectangle()
{
	Rectangle* rectangle = new Rectangle();
	rectangle->Length = 0.0;
	rectangle->Width = 0.0;
	rectangle->Diagonal = 0.0;
	rectangle->Color = "";
	rectangle->Perimeter = 0.0;
	rectangle->Area = 0.0;
	return rectangle;
}

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
	cout << "Длина: " << rectangle.Length << endl;
	cout << "Ширина: " << rectangle.Width << endl;
	cout << "Диагональ: " << rectangle.Diagonal << endl;
	cout << "Цвет: " << rectangle.Color << endl;
	cout << "Периметр: " << rectangle.Perimeter << endl;
	cout << "Площадь: " << rectangle.Area << endl << endl;
}

void DemoReadAndPrintRectangles(int rectanglesCount)
{
	Rectangle** rectangles = new Rectangle * [rectanglesCount];
	for (int i = 0; i < rectanglesCount; i++)
	{
		rectangles[i] = MakeRectangle();
	}
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << ":" << endl << endl;
		ReadRectangle(*rectangles[i]);
	}
	cout << "Массив прямоугольников: " << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << ":" << endl << endl;
		PrintRectangle(*rectangles[i]);
	}
	for (int i = 0; i < rectanglesCount; i++)
	{
		delete rectangles[i];
	}
	delete[] rectangles;
}

void ChangeRectangle(Rectangle* rectangle, float length,
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

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2)
{
	Rectangle rectangle;

	rectangle.Length = rectangle1.Length;
	rectangle.Width = rectangle1.Width;
	rectangle.Color = rectangle1.Color;
	rectangle.Diagonal = rectangle1.Diagonal;
	rectangle.Perimeter = rectangle1.Perimeter;
	rectangle.Area = rectangle1.Area;

	rectangle1.Length = rectangle2.Length;
	rectangle1.Width = rectangle2.Width;
	rectangle1.Color = rectangle2.Color;
	rectangle1.Diagonal = rectangle2.Diagonal;
	rectangle1.Perimeter = rectangle2.Perimeter;
	rectangle1.Area = rectangle2.Area;

	rectangle2.Length = rectangle.Length;
	rectangle2.Width = rectangle.Width;
	rectangle2.Color = rectangle.Color;
	rectangle2.Diagonal = rectangle.Diagonal;
	rectangle2.Perimeter = rectangle.Perimeter;
	rectangle2.Area = rectangle.Area;
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
	
	// Task 2.2.3.3 / 2.2.5.3
	const int rectanglesCount = 5;
	DemoReadAndPrintRectangles(rectanglesCount);
	PrintLine();
	
	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Rectangle* pFirstRectangle = &firstRectangle;
	cout << "Прямоугольник firstRectangle: " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "Измененный прямоугольник firstRectangle: " << endl << endl;
	ChangeRectangle(pFirstRectangle, 111, 11, "коричневый");
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
	
	// Task 2.2.5.4
	cout << "Прямоугольник firstRectangle:" << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "Прямоугольник secondRectangle:" << endl << endl;
	PrintRectangle(secondRectangle);

	Exchange(firstRectangle, secondRectangle);

	cout << "Прямоугольник firstRectangle ";
	cout << "после работы функции Exchange : " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "Прямоугольник secondRectangle ";
	cout << "после работы функции Exchange : " << endl << endl;
	PrintRectangle(secondRectangle);
	
	PrintLine();
}


