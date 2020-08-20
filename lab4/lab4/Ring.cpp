#include "Ring.h"

int Ring::AllRingsCount = 0;

void Ring::SetCenter(const float x, const float y)
{
	_center = Point(x, y);
}

void Ring::SetRadius(float inRadius, float outRadius)
{
	FloatValidator::AssertPositiveValue(inRadius,
		"радиус внутреннего кольца");
	FloatValidator::AssertPositiveValue(outRadius,
		"радиус внешнего кольца");
	FloatValidator::AssertValueInRange(inRadius,
		0, outRadius, "радиус внутреннего кольца");
	_inRadius = inRadius;
	_outRadius = outRadius;
}

float Ring::GetCentreX()
{
	return _center.GetX();
}

float Ring::GetCentreY()
{
	return _center.GetY();
}

float Ring::GetInRadius()
{
	return _inRadius;
}

float Ring::GetOutRadius()
{
	return _outRadius;
}

float Ring::GetArea()
{
	return PI * (pow(_outRadius, 2) - pow(_inRadius, 2));
}

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}

Ring::Ring()
{
	_center = Point(0.0, 0.0);
	SetRadius(1.0, 2.0);
	AllRingsCount++;
}

Ring::Ring(const float x, const float y, 
	const float inRadius, const float outRadius)
{
	_center = Point(x, y);
	SetRadius(inRadius, outRadius);
	AllRingsCount++;
}

void Ring::PrintRing()
{
	cout << "x = " << _center.GetX() << ", y = " << _center.GetY();
	cout << ", внутренний радиус = " << _inRadius;
	cout << ", внешний радиус = " << _outRadius;
}
