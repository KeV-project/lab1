#include "Ring.h"

int Ring::AllRingsCount = 0;

void Ring::SetCenterX(const float x)
{
	_center.SetX(x);
}

void Ring::SetCenterY(const float y)
{
	_center.SetY(y);
}

void Ring::SetRadius(float inRadius, float outRadius)
{
	FloatValidator::AssertPositiveValue(inRadius,
		"радиус внутреннего кольца");
	FloatValidator::AssertPositiveValue(outRadius,
		"радиус внешнего кольца");
	FloatValidator::AssertValueInRange(inRadius, 0, outRadius);
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
	return Pi * (pow(_outRadius, 2) - pow(_inRadius, 2));
}

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}

Ring::Ring()
{
	_center.SetX(0.0);
	_center.SetY(0.0);
	SetRadius(1.0, 2.0);
}

Ring::Ring(const float x, const float y, 
	const float inRadius, const float outRadius)
{
	_center.SetX(x);
	_center.SetY(y);
	SetRadius(inRadius, outRadius);
	AllRingsCount++;
}
