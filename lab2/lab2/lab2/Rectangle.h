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

void ReadRectangle(Rectangle& rectangle);
void PrintRectangle(Rectangle& rectangle);
void DemoRectangle();
