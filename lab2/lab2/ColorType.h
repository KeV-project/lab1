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

void PrintColor(ColorType color);
ColorType ReadColor();
