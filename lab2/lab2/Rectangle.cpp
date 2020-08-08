#include "Rectangle.h"

void SetLength(Rectangle& rectangle, const float length)
{
	if (length <= 0)
	{
		throw exception("ИСКЛЮЧЕНИЕ: длина прямоугольника"
			"не может быть меньше или равна 0");
	}
	rectangle.Length = length;
}

void SetWidth(Rectangle& rectangle, const float width)
{
	if (width <= 0)
	{
		throw exception("ИСКЛЮЧЕНИЕ: ширина прямоугольника"
			"не может быть меньше или равна 0");
	}
	rectangle.Width = width;
}

void SetColor(Rectangle& rectangle, const ColorType& color)
{
	rectangle.Color = color;
}

Rectangle* MakeRectangle()
{
	Rectangle* rectangle = new Rectangle();
	SetLength(*rectangle, 1.0);
	SetWidth(*rectangle, 1.0);
	rectangle->Diagonal = 1.0;
	SetColor(*rectangle, Red);
	rectangle->Perimeter = 2.0;
	return rectangle;
}

//TODO: Сигнатура +
Rectangle* MakeRectangle(const float length, const float width,
	const ColorType& color)
{
	Rectangle* rectangle = new Rectangle();
	SetLength(*rectangle, length);
	SetWidth(*rectangle, width);
	rectangle->Diagonal = sqrt(pow(length, 2) + pow(width, 2));
	SetColor(*rectangle, color);
	rectangle->Perimeter = (length + width) * 2;
	rectangle->Area = length * width;
	return rectangle;
}

Rectangle* CopyRectangle(const Rectangle& rectangle)
{
	Rectangle* copiedRectangle = new Rectangle();
	copiedRectangle->Length = rectangle.Length;
	copiedRectangle->Width = rectangle.Width;
	copiedRectangle->Diagonal = rectangle.Diagonal;
	copiedRectangle->Color = rectangle.Color;
	copiedRectangle->Perimeter = rectangle.Perimeter;
	copiedRectangle->Area = rectangle.Area;
	return copiedRectangle;
}


void ReadRectangle(Rectangle& rectangle)
{
	cout << "Введите длину прямоугольника: ";
	float length = 0.0;
	cin >> length;
	cout << endl;
	SetLength(rectangle, length);
	cout << "Введите ширину прямоугольника: ";
	float width = 0.0;
	cin >> width;
	cout << endl;
	SetWidth(rectangle, width);
	cout << "Введите цвет прямоугольника: " << endl << endl;
	SetColor(rectangle, ReadColor());
	cout << endl;
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) 
		+ pow(rectangle.Width, 2));
	rectangle.Perimeter = (rectangle.Length + rectangle.Width) * 2;
	rectangle.Area = rectangle.Length * rectangle.Width;
}

void PrintRectangle(const Rectangle& rectangle)
{
	cout << "Длина: " << rectangle.Length << endl;
	cout << "Ширина: " << rectangle.Width << endl;
	cout << "Диагональ: " << rectangle.Diagonal << endl;
	cout << "Цвет: ";
	PrintColor(rectangle.Color);
	cout << endl;
	cout << "Периметр: " << rectangle.Perimeter << endl;
	cout << "Площадь: " << rectangle.Area << endl << endl;
}

//TODO: Сигнатура +
Rectangle** DemoReadAndPrintRectangles(const int rectanglesCount)
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
	return rectangles;
}

//TODO: Сигнатура +
void ChangeRectangle(Rectangle* rectangle, const float length,
	const float width, const ColorType& color)
{
	SetLength(*rectangle, length);
	SetWidth(*rectangle, width);
	SetColor(*rectangle, color);
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

void FindRectangle(Rectangle** rectangles, const int rectanglesCount)
{
	float maxLength = 0.0;
	int maxLengthIndex = 0;
	for (int i = 0; i < rectanglesCount; i++)
	{
		if (rectangles[i]->Length > maxLength)
		{
			maxLength = rectangles[i]->Length;
			maxLengthIndex = i;
		}
	}
	cout << "Прямоугольник с наибольшей длиной: ";
	cout << rectangles[maxLengthIndex]->Length << " * ";
	cout << rectangles[maxLengthIndex]->Width << endl << endl;
}

void FindMaxRectangle(Rectangle** rectangles, const int rectanglesCount)
{
	float maxArea = 0.0;
	int maxAreaIndex = 0;
	for (int i = 0; i < rectanglesCount; i++)
	{
		if (rectangles[i]->Area > maxArea)
		{
			maxArea = rectangles[i]->Area;
			maxAreaIndex = i;
		}
	}
	cout << "Прямоугольник с наибольшей площадью: ";
	cout << rectangles[maxAreaIndex]->Length << " * ";
	cout << rectangles[maxAreaIndex]->Width << endl << endl;
}

void DemoRectangle()
{
	// Task 2.2.3.1
	Rectangle firstRectangle;
	SetLength(firstRectangle, 13.5);
	SetWidth(firstRectangle, 7.3);
	SetColor(firstRectangle, Yellow);
	firstRectangle.Diagonal = 15.3;
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
	Rectangle** rectangles = DemoReadAndPrintRectangles(rectanglesCount);
	PrintLine();
	
	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Rectangle* pFirstRectangle = &firstRectangle;
	cout << "Прямоугольник firstRectangle: " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "Измененный прямоугольник firstRectangle: " << endl << endl;
	ChangeRectangle(pFirstRectangle, 111, 11, Purple);
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

	// Task 2.2.5.5
	FindRectangle(rectangles, rectanglesCount);
	PrintLine();

	// Task 2.2.5.6
	FindMaxRectangle(rectangles, rectanglesCount);
	PrintLine();

	for (int i = 0; i < rectanglesCount; i++)
	{
		delete rectangles[i];
	}
	delete[] rectangles;
}
