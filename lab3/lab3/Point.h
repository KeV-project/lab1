#pragma once

class Point
{
private:
	float _x;
	float _y;

public:
	void SetX(const float x);
	void SetY(const float y);

	float GetX();
	float GetY();

	Point();
	Point(const float x, const float y);
};

