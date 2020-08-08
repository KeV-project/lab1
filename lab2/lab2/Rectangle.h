#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Rectangle
{
	float Length;
	float Width;
	float Diagonal;
	string Color;
	float Perimeter;
	float Area;
};

Rectangle* MakeRectangle();
Rectangle* MakeRectangle(const float length, const float width,
	const string& color);
Rectangle* CopyRectangle(const Rectangle& rectangle);
void ReadRectangle(Rectangle& rectangle);
void PrintRectangle(const Rectangle& rectangle);
Rectangle** DemoReadAndPrintRectangles(const int rectanglesCount);
void ChangeRectangle(Rectangle* rectangle, const float length,
	const float width, const string& color);
void Exchange(Rectangle& rectangle1, Rectangle& rectangle2);
void FindRectangle(Rectangle** rectangles, int rectanglesCount);
void DemoRectangle();
