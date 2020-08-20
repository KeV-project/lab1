#pragma once
#include <iostream>
#include "FloatValidator.h"
#include "Point.h"

using namespace std;

class Rect
{
private:
	static int AllRectCount;

	Point _center;
	float _length;
	float _width;
	
public:
	void SetCenter(const float x, const float y);
	void SetLength(float length);
	void SetWidth(float width);

	float GetLength();
	float GetWidth();
	float GetCentreX();
	float GetCentreY();
	float GetArea();
	int GetAllRectCount();

	Rect();
	Rect(const float length, const float width, 
		const float x, const float y);

	void PrintRect();
};

