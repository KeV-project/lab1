#include "Rectangle.h"

void ReadRectangle(Rectangle& rectangle)
{
	cout << "¬ведите длину пр€моугольника(вещ. ч): ";
	cin >> rectangle.Length;
	cout << endl;
	cout << "¬ведите ширину пр€моугольника(вещ. ч): ";
	cin >> rectangle.Width;
	cout << endl;
	cout << "¬ведите цвет пр€моугольника: ";
	cin >> rectangle.Color;
	cout << endl;
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) 
		+ pow(rectangle.Width, 2));
	rectangle.Perimeter = (rectangle.Length + rectangle.Width) * 2;
	rectangle.Area = rectangle.Length * rectangle.Width;
}

void PrintRectangle(Rectangle& rectangle)
{
	cout << "ѕр€моугольник:" << endl;
	cout << "ƒлина: " << rectangle.Length << endl;
	cout << "Ўирина: " << rectangle.Width << endl;
	cout << "ƒиагональ: " << rectangle.Diagonal << endl;
	cout << "÷вет: " << rectangle.Color << endl;
	cout << "ѕериметр: " << rectangle.Perimeter << endl;
	cout << "ѕлощадь: " << rectangle.Area << endl << endl;
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
	cout << "ѕ–яћќ”√ќЋ№Ќ» " << endl << endl;
	ReadRectangle(secondRectangle);
	PrintRectangle(secondRectangle);
	PrintLine();
}


