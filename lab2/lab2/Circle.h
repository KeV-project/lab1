#pragma once

#include <iostream>

using namespace std;

struct Circle
{
	double X;
	double Y;
	double Radius;
	string Color;
};

Circle* MakeCircle(const double x, const double y, const double radius, string color);
Circle* CopyCircle(Circle& circle);
void DemoCircle();