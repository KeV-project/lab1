#pragma once
#include <iostream>
#include <math.h> 
#include "Point.h"
#include "FloatValidator.h"
using namespace std;

const float Pi = 3.14;

class Ring
{
private:
	static int AllRingsCount;

	Point _center;
	float _inRadius;
	float _outRadius;

public:
	void SetCenterX(const float x);
	void SetCenterY(const float y);
	void SetRadius(float inRadius, float outRadius);

	float GetCentreX();
	float GetCentreY();
	float GetInRadius();
	float GetOutRadius();
	float GetArea();
	static int GetAllRingsCount();

	Ring();
	Ring(const float x, const float y,
		const float inRadius, const float outRadius);

	~Ring()
	{
		AllRingsCount--;
	}
};
