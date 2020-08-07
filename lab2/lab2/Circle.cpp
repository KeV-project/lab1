#include "Circle.h"

Circle* MakeCercle(double x, double y, double radius, string color)
{
	Circle* circle = new Circle();
	circle->X = x;
	circle->Y = y;
	circle->Radius = radius;
	circle->Color = color;
	return circle;
}

Circle* CopyCircle(Circle& circle)
{
	Circle* copiedCircle = new Circle();
	copiedCircle->X = circle.X;
	copiedCircle->Y = circle.Y;
	copiedCircle->Radius = circle.Radius;
	copiedCircle->Color = circle.Color;
	return copiedCircle;
}

void DemoCircle()
{
	Circle* circle1 = MakeCercle(5.0, 7.0, 7.5, "Red");
	Circle* circle2 = MakeCercle(2.0, -12.0, 12.75, "Green");
	Circle* circle3 = MakeCercle(-10.0, 10.0, 1.45, "Blue");

	Circle* copiedCircle1(circle1);
	Circle* copiedCircle2(circle2);
	Circle* copiedCircle3(circle3);
}