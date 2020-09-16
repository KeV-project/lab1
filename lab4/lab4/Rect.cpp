#include "Rect.h"

int Rect::AllRectsCount = 0;

void Rect::SetCenter(const float x, const float y)
{
	_center = Point(x, y);
}

void Rect::SetLength(float length)
{
	//TODO: ввод значений с ограничением на 2 знака дублируется в нескольких местах.
	//TODO: Дублирование лучше убрать, т.к. тут дублируется прям формула рассчёта +
	// Ограничение на инициализацию длины прямоугольника больше 2х знаков после запятой +
	ValueCorrector::RoundFloatToHundredths(length);
	const float minLength = 0.0;
	const float maxLength = INT32_MAX;
	ValueValidator::AssertValueInRange(length, 
		minLength, maxLength, NotPositive,"длину прямоулогьника");
	this->_length = length;
}

void Rect::SetWidth(float width)
{
	//TODO: ввод значений с ограничением на 2 знака дублируется в нескольких местах.
	//TODO: Дублирование лучше убрать, т.к. тут дублируется прям формула рассчёта
	// Ограничение на инициализацию шиниры прямоугольника больше 2х знаков после запятой +
	ValueCorrector::RoundFloatToHundredths(width);
	const float minWidth = 0.0;
	const float maxWidth = INT32_MAX;
	ValueValidator::AssertValueInRange(width, 
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

