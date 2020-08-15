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
		throw exception();
	}
	this->_length = length;
}

void Rectangle::SetWidth(const float width)
{
}

float Rectangle::GetCenterX()
{
	return 0.0f;
}

float Rectangle::GetCenterY()
{
	return 0.0f;
}

float Rectangle::GetLength()
{
	return 0.0f;
}

float Rectangle::GetWidth()
{
	return 0.0f;
}

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const float x, const float y, const float length, const float width)
{
}
