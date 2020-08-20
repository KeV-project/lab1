#pragma once
#include <iostream>
#include "FloatValidator.h"
#include "Point.h"

using namespace std;

class Rect
{
private:
	static int AllRectsCount;

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
	static int GetAllRectsCount();

	Rect();
	Rect(const float x, const float y, 
		const float length, const float width);
	~Rect()
	{
		AllRectsCount--;
	}

	void PrintRect();
};

