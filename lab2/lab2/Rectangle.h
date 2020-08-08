#pragma once

#include <iostream>
#include "Input.h"
#include "Output.h"
#include "ColorType.h"

using namespace std;

struct Rectangle
{
	float Length;
	float Width;
	float Diagonal;
	ColorType Color;
	float Perimeter;
	float Area;
};

void SetLength(Rectangle &rectangle, const float length);
void SetWidth(Rectangle& rectangle, const float width);
void SetColor(Rectangle& rectangle, const ColorType& color);

Rectangle* MakeRectangle();
Rectangle* MakeRectangle(const float length, const float width,
	const ColorType& color);

Rectangle* CopyRectangle(const Rectangle& rectangle);
void ReadRectangle(Rectangle& rectangle);
void PrintRectangle(const Rectangle& rectangle);
Rectangle** DemoReadAndPrintRectangles(const int rectanglesCount);
void ChangeRectangle(Rectangle* rectangle, const float length,
	const float width, const ColorType& color);
void Exchange(Rectangle& rectangle1, Rectangle& rectangle2);
void FindRectangle(Rectangle** rectangles, const int rectanglesCount);
void FindMaxRectangle(Rectangle** rectangles, const int rectanglesCount);
void DemoRectangle();
