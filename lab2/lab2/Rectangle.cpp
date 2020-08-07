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
	cout << "������� ����� ��������������(���. �): ";
	cin >> rectangle.Length;
	cout << endl;
	cout << "������� ������ ��������������(���. �): ";
	cin >> rectangle.Width;
	cout << endl;
	cout << "������� ���� ��������������: ";
	cin >> rectangle.Color;
	cout << endl;
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) 
		+ pow(rectangle.Width, 2));
	rectangle.Perimeter = (rectangle.Length + rectangle.Width) * 2;
	rectangle.Area = rectangle.Length * rectangle.Width;
}

void PrintRectangle(Rectangle& rectangle)
{
	cout << "�����: " << rectangle.Length << endl;
	cout << "������: " << rectangle.Width << endl;
	cout << "���������: " << rectangle.Diagonal << endl;
	cout << "����: " << rectangle.Color << endl;
	cout << "��������: " << rectangle.Perimeter << endl;
	cout << "�������: " << rectangle.Area << endl << endl;
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
		cout << "������������� �" << i + 1 << ":" << endl << endl;
		ReadRectangle(*rectangles[i]);
	}
	cout << "������ ���������������: " << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "������������� �" << i + 1 << ":" << endl << endl;
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
	cout << "�������������" << endl << endl;
	ReadRectangle(secondRectangle);
	PrintRectangle(secondRectangle);
	PrintLine();
	
	// Task 2.2.3.3 / 2.2.5.3
	const int rectanglesCount = 5;
	DemoReadAndPrintRectangles(rectanglesCount);
	PrintLine();
	
	// Task 2.2.4.1
	cout << "������ � ���������� �� ���������:" << endl << endl;
	Rectangle* pFirstRectangle = &firstRectangle;
	cout << "������������� firstRectangle: " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "���������� ������������� firstRectangle: " << endl << endl;
	ChangeRectangle(pFirstRectangle, 111, 11, "����������");
	PrintRectangle(*pFirstRectangle);
	PrintLine();
	
	// Task 2.2.4.2
	Rectangle* pFirstRectangle2 = &firstRectangle;
	cout << "����� ���������� firstRectangle: ";
	cout << &firstRectangle << endl << endl;
	cout << "����� � ��������� pFirstRectangle: ";
	cout << pFirstRectangle << endl << endl;
	cout << "����� � ��������� pFirstRectangle2: ";
	cout << pFirstRectangle2 << endl << endl;
	PrintLine();

}


