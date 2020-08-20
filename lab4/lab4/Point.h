#pragma once

class Point
{
private:
	float _x;
	float _y;

	void SetX(const float x);
	void SetY(const float y);

public:
	float GetX();
	float GetY();

	Point();
	Point(const float x, const float y);
};