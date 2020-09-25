#include "Ring.h"

int Ring::AllRingsCount = 0;

void Ring::SetCenter(const float x, const float y)
{
	_center = Point(x, y);
}

void Ring::SetRadius(float inRadius, float outRadius)
{
	ValueCorrector::RoundFloatToHundredths(inRadius);
	ValueCorrector::RoundFloatToHundredths(outRadius);
	const float minRadius = 0.00;
	const float maxRadius = INT32_MAX;
	ValueValidator::AssertValueInRange(inRadius,
		minRadius, maxRadius, NotPositive, "радиус внутреннего кольца");
	ValueValidator::AssertValueInRange(outRadius,
		minRadius, maxRadius, NotPositive, "радиус внешнего кольца");

	ValueValidator::AssertValueInRange(inRadius,
		minRadius, outRadius, NotInRange, "радиус внутреннего кольца");
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
	return M_PI * (pow(_outRadius, 2) - pow(_inRadius, 2));
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