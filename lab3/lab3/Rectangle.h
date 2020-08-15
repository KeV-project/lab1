#pragma once
#include "Point.h"
#include <iostream>

using namespace std;

class Rectangle
{
private:
	Point _center;
	float _length;
	float _width;

public:
	void SetCenterX(const float x);
	void SetCenterY(const float y);
	void SetLength(const float length);
	void SetWidth(const float width);

	float GetCenterX();
	float GetCenterY();
	float GetLength();
	float GetWidth();

	Rectangle();
	Rectangle(const float x, const float y,
		const float length, const float width);
};

