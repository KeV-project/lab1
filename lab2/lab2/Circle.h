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

Circle* MakeCircle(double x, double y, double radius, string color);
Circle* CopyCircle(Circle& circle);
void DemoCircle();