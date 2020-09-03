#pragma once
#include "Point.h"
#include <iostream>
#include <string>

using namespace std;

// ���������� Windows.h �� ��������� ������������ ����� Rectangle
// � �������� �������� ������
class Rect
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

	Rect();
	Rect(const float length, const float width,
		const float x, const float y);

	void ChangeRectangle(const float length, const float width,
		const float x, const float y);
	void WriteRectangle();
};

void WriteRectangles(Rect** rectangles,
	const int rectanglesCount);
float GetMeanCenterX(Rect** rectangles,
	const int rectanglesCount);
float GetMeanCenterY(Rect** rectangles,
	const int rectanglesCount);

