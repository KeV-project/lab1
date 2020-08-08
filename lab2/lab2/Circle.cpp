#include "Circle.h"

//TODO: ќпечатка +
//TODO: ѕохорошему - везде, где значение не измен€етс€ в сигнатере правильнее писать const
//TODO: “.к. строка может оказатьс€ достаточно большой дл€ передачи - правильнее передавать еЄ по ссылке, чтобы избежать копировани€
//TODO: ƒальше везде буду писать "—игнатура" чтобы не повтор€тьс€
Circle* MakeCircle(const double x, const double y,
	const double radius, const string &color)
{
	Circle* circle = new Circle();
	circle->X = x;
	circle->Y = y;
	circle->Radius = radius;
	circle->Color = color;
	return circle;
}

Circle* CopyCircle(const Circle& circle)
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
	Circle* circle1 = MakeCircle(5.0, 7.0, 7.5, "Red");
	Circle* circle2 = MakeCircle(2.0, -12.0, 12.75, "Green");
	Circle* circle3 = MakeCircle(-10.0, 10.0, 1.45, "Blue");

	Circle* copiedCircle1(circle1);
	Circle* copiedCircle2(circle2);
	Circle* copiedCircle3(circle3);
}