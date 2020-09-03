#pragma once
#include "Output.h"
#include "Book.h"
#include "Route.h"
#include "Rectangle.h"
#include "Flight.h"
#include "Band.h"

using namespace std;

static class DemoWorkingWithClasses
{
public:
	static int FindBookByAuthor(Book* books, const int booksCount,
		const string& findedAuthor);
	static void DemoBook();

	static int FindRouteTo(Route* routes, const int routesCount,
		const string& findedStop);
	static void DemoRoute();

	static void WriteRectangles(Rect** rectangles,
		const int rectanglesCount);
	static float GetMeanCenterX(Rect** rectangles,
		const int rectanglesCount);
	static float GetMeanCenterY(Rect** rectangles,
		const int rectanglesCount);
	static void DemoRectangleWithPoint();

	static void WriteFlights(Flight** flights, const int flightsCount);
	static void DemoFlightWithTime();

	static void DemoBand();
};

