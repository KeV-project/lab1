#include "Rect.h"

int Rect::AllRectsCount = 0;

void Rect::SetCenter(const float x, const float y)
{
	_center = Point(x, y);
}

void Rect::SetLength(const float length)
{
	const int minLength = 0.0;
	const int maxLength = INT32_MAX;
	FloatValidator::AssertValueInRange(length, 
		minLength, maxLength, NotPositive,"длину прямоулогьника");
	this->_length = length;
}

void Rect::SetWidth(float width)
{
	const int minWidth = 0.0;
	const int maxWidth = INT32_MAX;
	FloatValidator::AssertValueInRange(width, 
		minWidth, maxWidth, NotPositive, "ширину прямоугольника");
	this->_width = width;
}

float Rect::GetLength()
{
	return this->_length;
}

float Rect::GetWidth()
{
	return this->_width;
}

float Rect::GetCentreX()
{
	return _center.GetX();
}

float Rect::GetCentreY()
{
	return _center.GetY();
}

float Rect::GetArea()
{
	return _length * _width;
}

int Rect::GetAllRectsCount()
{
	return AllRectsCount;
}

Rect::Rect()
{
	_center = Point(0.0, 0.0);
	SetLength(1.0);
	SetWidth(1.0);
	AllRectsCount++;
}

Rect::Rect(const float x, const float y, 
	const float length, const float width)
{
	_center = Point(x, y);
	SetLength(length);
	SetWidth(width);
	AllRectsCount++;
}

