#include "Rectangle.h"

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
	cout << "�������������:" << endl;
	cout << "�����: " << rectangle.Length << endl;
	cout << "������: " << rectangle.Width << endl;
	cout << "���������: " << rectangle.Diagonal << endl;
	cout << "����: " << rectangle.Color << endl;
	cout << "��������: " << rectangle.Perimeter << endl;
	cout << "�������: " << rectangle.Area << endl << endl;
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
	cout << "�������������" << endl << endl;
	ReadRectangle(secondRectangle);
	PrintRectangle(secondRectangle);
	PrintLine();
}


