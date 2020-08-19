#include "Point.h"

void Point::SetX(const float x)
{
	this->_x = x;
}

void Point::SetY(const float y)
{
	this->_y = y;
}

float Point::GetX()
{
	return _x;
}

float Point::GetY()
{
	return _y;
}

Point::Point()
{
	SetX(0.0);
	SetY(0.0);
}

Point::Point(const float x, const float y)
{
	SetX(x);
	SetY(y);
}

