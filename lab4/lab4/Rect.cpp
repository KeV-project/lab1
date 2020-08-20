#include "Rect.h"

int Rect::AllRectsCount = 0;

void Rect::SetCenter(const float x, const float y)
{
	_center = Point(x, y);
}

void Rect::SetLength(const float length)
{
	FloatValidator::AssertPositiveValue(length, "длину прямоулогьника");
	this->_length = length;
}

void Rect::SetWidth(float width)
{
	FloatValidator::AssertPositiveValue(width, "ширину прямоугольника");
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

void Rect::PrintRect()
{
	cout << "x = " << _center.GetX() << ", y = ";
	cout << _center.GetY() << ", длина = ";
	cout << _length << ", ширина = " << _width;
}

