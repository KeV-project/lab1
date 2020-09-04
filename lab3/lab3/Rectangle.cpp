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
	//TODO: Дубль +
	int const minLength = 1;
	int const maxLength = 2147483647;
	if (!IsValueInRange(length, minLength, maxLength))
	{
		char message[255];
		strcpy_s(message, MakeMessage(length, NotPositive,
			"длину прямоугольника").c_str());
		throw exception(message);
	}
	this->_length = length;
}

void Rect::SetWidth(const float width)
{
	//TODO: Дубль +
	int const minWidth = 1;
	int const maxWidth = 2147483647;
	if (!IsValueInRange(width, minWidth, maxWidth))
	{
		char message[255];
		strcpy_s(message, MakeMessage(width, NotPositive,
			"ширину прямоугольника").c_str());
		throw exception(message);
	}
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

void Rect::WriteRectangle()
{
	//TODO: Этот метод не должен тут находиться, т.к. таким образов вы прикалачиваете его к консоли, консольный ввод лучше вынести 
	cout << "Длинa: " << _length << endl;
	cout << "Ширина: " << _width << endl;
	cout << "x: " << GetCenterX() << endl;
	cout << "y: " << GetCenterY() << endl << endl;
}

void WriteRectangles(Rect** rectangles,
	const int rectanglesCount)
{
	//TODO: Этот метод не должен тут находиться, т.к. таким образов вы прикалачиваете его к консоли, консольный ввод лучше вынести 
	cout << "Массив прямоугольников:" << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << ": " << endl;
		rectangles[i]->WriteRectangle();
	}
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
