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

//TODO: ��������� +
Rectangle* MakeRectangle(const float length, const float width,
	const string& color)
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

Rectangle* CopyRectangle(Rectangle& rectangle)
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

//TODO: ���������
Rectangle** DemoReadAndPrintRectangles(int rectanglesCount)
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
	return rectangles;
}

//TODO: ���������
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

void FindRectangle(Rectangle** rectangles, int rectanglesCount)
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
	cout << "������������� � ���������� ������: ";
	cout << rectangles[maxLengthIndex]->Length << " * ";
	cout << rectangles[maxLengthIndex]->Width << endl << endl;
}

void FindMaxRectangle(Rectangle** rectangles, int rectanglesCount)
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
	cout << "������������� � ���������� ��������: ";
	cout << rectangles[maxAreaIndex]->Length << " * ";
	cout << rectangles[maxAreaIndex]->Width << endl << endl;
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
	Rectangle** rectangles = DemoReadAndPrintRectangles(rectanglesCount);
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
	
	// Task 2.2.5.4
	cout << "������������� firstRectangle:" << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "������������� secondRectangle:" << endl << endl;
	PrintRectangle(secondRectangle);

	Exchange(firstRectangle, secondRectangle);

	cout << "������������� firstRectangle ";
	cout << "����� ������ ������� Exchange : " << endl << endl;
	PrintRectangle(firstRectangle);
	cout << "������������� secondRectangle ";
	cout << "����� ������ ������� Exchange : " << endl << endl;
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


