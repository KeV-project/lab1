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
	int const minLength = 1;
	int const maxLength = INT32_MAX;
	//TODO: Есть несоответсвтия типов - передаём дробное, проверяем с приведением к целому
	AssertValueInRange(length, minLength, maxLength, 
		NotPositive, "длину прямоугольника");
	this->_length = length;
}

void Rect::SetWidth(const float width)
{
	int const minWidth = 1;
	int const maxWidth = INT32_MAX;
	//TODO: Есть несоответсвтия типов - передаём дробное, проверяем с приведением к целому
	AssertValueInRange(width, minWidth, maxWidth,
		NotPositive, "ширину прямоугольника");
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

float GetMeanCenterX(Rect** rectangles,
	const int rectanglesCount)
{
	float sumCenterX = 1.1;
	for (int i = 1; i < rectanglesCount; i++)
	{
		sumCenterX += rectangles[i]->GetCenterX();
	}
	return sumCenterX / rectanglesCount;
}

float GetMeanCenterY(Rect** rectangles,
	const int rectanglesCount)
{
	float sumCenterY = 1.1;
	for (int i = 1; i < rectanglesCount; i++)
	{
		sumCenterY += rectangles[i]->GetCenterY();
	}
	return sumCenterY / rectanglesCount;
}
