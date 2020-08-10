#include "Rectangle.h"

void SetLength(Rectangle& rectangle, const float length)
{
	if (length <= 0)
	{
		throw exception("����������: ����� ��������������"
			"�� ����� ���� ������ ��� ����� 0");
	}
	rectangle.Length = length;
}

void SetWidth(Rectangle& rectangle, const float width)
{
	if (width <= 0)
	{
		throw exception("����������: ������ ��������������"
			"�� ����� ���� ������ ��� ����� 0");
	}
	rectangle.Width = width;
}

void SetDiagonal(Rectangle& rectangle, const float length, const float width)
{
	rectangle.Diagonal = sqrt(pow(length, 2) + pow(width, 2));
}

void SetColor(Rectangle& rectangle, const ColorType& color)
{
	rectangle.Color = color;
}

void SetPerimeter(Rectangle& rectangle, const float length, const float width)
{
	rectangle.Perimeter = (length + width) * 2;
}

void SetArea(Rectangle& rectangle, const float length, const float width)
{
	rectangle.Area = length * width;
}

Rectangle* MakeRectangle()
{
	Rectangle* rectangle = new Rectangle();
	SetLength(*rectangle, 1.0);
	SetWidth(*rectangle, 1.0);
	SetDiagonal(*rectangle, rectangle->Length, rectangle->Width);
	SetColor(*rectangle, Red);
	SetPerimeter(*rectangle, rectangle->Length, rectangle->Width);
	SetArea(*rectangle, rectangle->Length, rectangle->Width);
	return rectangle;
}

Rectangle* MakeRectangle(const float length, const float width,
	const ColorType& color)
{
	Rectangle* rectangle = new Rectangle();
	SetLength(*rectangle, length);
	SetWidth(*rectangle, width);
	SetDiagonal(*rectangle, rectangle->Length, rectangle->Width);
	SetColor(*rectangle, color);
	SetPerimeter(*rectangle, rectangle->Length, rectangle->Width);
	SetArea(*rectangle, rectangle->Length, rectangle->Width);
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
	do
	{
		cout << "������� ����� ��������������: ";
		float length = 0.0;
		cin >> length;
		cout << endl;
		if (IsValue())
		{
			SetLength(rectangle, length);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ������ ��������������: ";
		float width = 0.0;
		cin >> width;
		cout << endl;
		if (IsValue())
		{
			SetWidth(rectangle, width);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���� ��������������" << endl << endl;
		int numColor;
		cout << "������� ����� �� 0 �� 6 (0 � �������, 1 � ���������,";
		cout << "\n2 � ������, 3 ��������, 4 � �������, ";
		cout << "5 � �����, 6 � ����������): ";
		cin >> numColor;
		cout << endl;
		if (IsValue())
		{
			SetColor(rectangle, GetColorType(numColor));
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	rectangle.Diagonal = sqrt(pow(rectangle.Length, 2) 
		+ pow(rectangle.Width, 2));
	rectangle.Perimeter = (rectangle.Length + rectangle.Width) * 2;
	rectangle.Area = rectangle.Length * rectangle.Width;
}

void PrintRectangle(const Rectangle& rectangle)
{
	cout << "�����: " << rectangle.Length << endl;
	cout << "������: " << rectangle.Width << endl;
	cout << "���������: " << rectangle.Diagonal << endl;
	cout << "����: ";
	PrintColor(rectangle.Color);
	cout << endl;
	cout << "��������: " << rectangle.Perimeter << endl;
	cout << "�������: " << rectangle.Area << endl << endl;
}

Rectangle** DemoReadAndPrintRectangles(const int rectanglesCount)
{
	Rectangle** rectangles = new Rectangle * [rectanglesCount];
	for (int i = 0; i < rectanglesCount; i++)
	{
		rectangles[i] = MakeRectangle();
	}
	for (int i = 0; i < rectanglesCount; i++)
	{
		//TODO: �����
		cout << "������������� �" << i + 1 << ":" << endl << endl;
		ReadRectangle(*rectangles[i]);
	}
	cout << "������ ���������������: " << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		//TODO: �����
		cout << "������������� �" << i + 1 << ":" << endl << endl;
		PrintRectangle(*rectangles[i]);
	}
	return rectangles;
}

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
	cout << "������������� � ���������� ������: ";
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
	cout << "������������� � ���������� ��������: ";
	cout << rectangles[maxAreaIndex]->Length << " * ";
	cout << rectangles[maxAreaIndex]->Width << endl << endl;
}

void DemoRectangle()
{
	// Task 2.2.3.1
	Rectangle firstRectangle;
	SetLength(firstRectangle, 13.5);
	SetWidth(firstRectangle, 7.3);
	SetDiagonal(firstRectangle, firstRectangle.Length, firstRectangle.Width);
	SetColor(firstRectangle, Yellow);
	SetPerimeter(firstRectangle, firstRectangle.Length, firstRectangle.Width);
	SetArea(firstRectangle, firstRectangle.Length, firstRectangle.Width);
	
	// Task 2.2.3.2
	Rectangle secondRectangle;
	cout << "�������������" << endl << endl;
	//TODO: � �������� ������� ���������� ����� ���������� ��������� ������, � �� ���������� � ��� �������
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
	ChangeRectangle(pFirstRectangle, 111, 11, Purple);
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
