#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> 
#include "MessageType.h"
#include "Point.h"
#include "FloatValidator.h"
using namespace std;

class Ring
{
private:

	static int AllRingsCount;

	Point _center;
	float _inRadius;
	float _outRadius;

public:
	void SetCenter(const float x, const float y);
	void SetRadius(const float inRadius, const float outRadius);

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
