#include "Rectangle.h"

void Rect::SetCenterX(const float x)
{
	this->_center.SetX(x);
}

void Rect::SetCenterY(const float y)
{
	this->_center.SetY(y);
}

void Rect::SetLength(const float length)
{
	if (length <= 0)
	{
		string message = "����� " + to_string(length) +
			" �� �������� �������������\n"
			"� �� ����� ���������� ����� ��������������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_length = length;
}

void Rect::SetWidth(const float width)
{
	if (width <= 0)
	{
		string message = "����� " + to_string(width) +
			" �� �������� �������������\n"
			"� �� ����� ���������� ������� ��������������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_width = width;
}

float Rect::GetCenterX()
{
	return _center.GetX();
}

float Rect::GetCenterY()
{
	return _center.GetY();
}

float Rect::GetLength()
{
	return _length;
}

float Rect::GetWidth()
{
	return _width;
}

Rect::Rect()
{
	SetLength(1.0);
	SetWidth(1.0);
	SetCenterX(0.0);
	SetCenterY(0.0);
}

Rect::Rect(const float length, const float width,
	const float x, const float y)
{
	SetLength(length);
	SetWidth(width);
	SetCenterX(x);
	SetCenterY(y);
}

void Rect::ChangeRectangle(const float length, const float width,
	const float x, const float y)
{
	SetLength(length);
	SetWidth(width);
	SetCenterX(x);
	SetCenterY(y);
}

void Rect::WriteRectangle()
{
	cout << "����a: " << _length << endl;
	cout << "������: " << _width << endl;
	cout << "x: " << GetCenterX() << endl;
	cout << "y: " << GetCenterY() << endl << endl;
}
