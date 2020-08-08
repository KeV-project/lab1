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

Circle* MakeCircle(const double x, const double y, const double radius, const string &color);
Circle* CopyCircle(const Circle& circle);
void DemoCircle();