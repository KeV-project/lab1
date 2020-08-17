#include "Rectangle.h"

void Rectangle::SetCenterX(const float x)
{
	this->_center.SetX(x);
}

void Rectangle::SetCenterY(const float y)
{
	this->_center.SetY(y);
}

void Rectangle::SetLength(const float length)
{
	if (length <= 0)
	{
		string message = "Число " + to_string(length) +
			" не является положительным\n"
			"и не может определять длину прямоугольника";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_length = length;
}

void Rectangle::SetWidth(const float width)
{
	if (width <= 0)
	{
		string message = "Число " + to_string(width) +
			" не является положительным\n"
			"и не может определять ширинну прямоугольника";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_width = width;
}

float Rectangle::GetCenterX()
{
	return GetCenterX();
}

float Rectangle::GetCenterY()
{
	return GetCenterY();
}

float Rectangle::GetLength()
{
	return _length;
}

float Rectangle::GetWidth()
{
	return _width;
}

Rectangle::Rectangle()
{
	SetLength(1.0);
	SetWidth(1.0);
	SetCenterX(0.0);
	SetCenterY(0.0);
}

Rectangle::Rectangle(const float length, const float width,
	const float x, const float y)
{
	SetLength(length);
	SetWidth(width);
	SetCenterX(x);
	SetCenterY(y);
}
