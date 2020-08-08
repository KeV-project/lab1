#pragma once
#include <iostream>

using namespace std;

enum ColorType
{
	Red,
	Orange,
	Yellow,
	Green,
	Blue,
	DarkBlue,
	Purple
};

void PrintColor(ColorType &color);
ColorType ReadColor();
int CountRed(ColorType* colors, const int colorsCount);
int CountColor(ColorType* colors, const int colorsCount, ColorType &findedColor);
